#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _ui->tableWidget->setAcceptDrops(true);
    _ui->tableWidget->installEventFilter(this);
    _ui->tableWidget->setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == _ui->tableWidget)
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
            auto item = _ui->tableWidget->itemAt(pos);
            item->setIcon(QIcon("://apple_64px.png"));
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
    close();
}

void MainWindow::on_pushButtonMainMenu_clicked()
{
    _ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton
        && _ui->label->geometry().contains(event->pos())) {

        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        mimeData->setText("apple 1");
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap("://apple_64px.png"));

        drag->exec();
    }
}
