#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <sstream>
#include <QThread>

#include "compiler.h"

using namespace std;



int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateMemory();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Run_clicked()
{
    if(threadRep.size() == 0){
    QString input = ui->Code->toPlainText();

    stringstream code;

    code << input.toStdString();

    Compiler b(code);
    updateMemory();
    b.Run();
    }
}

void MainWindow::updateMemory(){

    stringstream out;
    out << "     ";
    for (int j = 0; j < 10; j++) {
            out << std::right << std::setfill('0') << std::setw(2) << j << "     ";
        }

        // Display the contents of memory
        for (int i = 0; i < 1000; i++) {
            if (i == 0 || i % 10 == 0) {
                out << endl;
                 out << std::setfill('0') << std::setw(2) << (i)/10 << " ";
            }
                out << std::setfill('0') << std::setw(4) << Memory[i] << " ";
        }

        ui->MemoryShow->document()->setPlainText(QString::fromStdString(out.str()));
}

void MainWindow::on_RefreshMemory_clicked()
{
    updateMemory();
}
