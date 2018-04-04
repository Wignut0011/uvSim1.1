#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "memory.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_Run_clicked();

    void on_RefreshMemory_clicked();

private:
    Ui::MainWindow *ui;

    void updateMemory();
};

#endif // MAINWINDOW_H
