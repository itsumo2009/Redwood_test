#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_pushButtonNewGame_clicked();
    void on_pushButtonExit_clicked();
    void on_pushButtonMainMenu_clicked();

private:
    Ui::MainWindow *_ui;

};
#endif // MAINWINDOW_H
