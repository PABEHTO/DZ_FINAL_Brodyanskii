#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "secondwindow.h"
#include <QFile>

QString name;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile fileout("D:/TRY/BORYA5/BORYA5/files/cheque.txt");
    if(fileout.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QTextStream out(&fileout);
        fileout.close(); }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    name = ui->nameLine->text();
    if (name != ""){
    hide();
    window = new SecondWindow;
    window->setModal(true);
    window->show();
    }

}

