#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "itemdelegate.h"

#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
    , _model(new InventoryTableModel())
{
    _ui->setupUi(this);
    _model->loadFromDb();
    _ui->tableView->setModel(_model.data());
    _ui->tableView->installEventFilter(this);
    _ui->tableView->setAcceptDrops(true);
    _ui->tableView->setItemDelegate(new ItemDelegate());

    connect(_ui->tableView, &QTableView::customContextMenuRequested, [this](QPoint pos)
    {
        auto index = _ui->tableView->indexAt(pos);
        if (index.isValid())
        {
            _model->useItem(index);
        }
    });
}

MainWindow::~MainWindow()
{
    delete _ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == _ui->tableView)
    {
        if (event->type() == QEvent::Type::DragEnter)
        {
            auto dragEnterEvent = dynamic_cast<QDragEnterEvent*>(event);
            dragEnterEvent->acceptProposedAction();
        }
        else if (event->type() == QEvent::Type::Drop)
        {
            auto dropEvent = dynamic_cast<QDropEvent*>(event);
            QPoint pos = dropEvent->pos();
            auto index = _ui->tableView->indexAt(pos);
            if (index.isValid())
            {
                QByteArray array = dropEvent->mimeData()->data("application/inventory");
                if (array.isEmpty())
                {
                    _model->addItem(index, Item{});
                }
                else
                {
                    auto column = array[0];
                    auto row = array[1];
                    _model->moveItem(column, row, index);
                }
            }
            dropEvent->acceptProposedAction();
        }
    }
    return true;
}

void MainWindow::on_pushButtonNewGame_clicked()
{
    _ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonExit_clicked()
{
    _model->saveToDb();
    close();
}

void MainWindow::on_pushButtonMainMenu_clicked()
{
    _ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton
        && _ui->label->geometry().contains(event->pos()))
    {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        mimeData->setText("apple 1");
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap("://apple_64px.png"));

        drag->exec();
    }
}
