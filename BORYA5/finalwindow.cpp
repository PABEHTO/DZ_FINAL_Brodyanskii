#include "finalwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "ui_finalwindow.h"
#include "secondwindow.h"
#include "mainwindow.h"
#include <QCoreApplication>



FinalWindow::FinalWindow(QWidget *parent)

    : QDialog(parent)
    , ui(new Ui::FinalWindow)
    {
        ui->setupUi(this);
        ui->label->setText(name+", your cheque is:");
        ui->Total->setText(QString::number(tot));

        /*ui->Laptop->setText(temLap);
        ui->TVv->setText(temTV);
        ui->Printer->setText(temPrint);
        ui->Total->setText("Total: "+QString::number(tot));*/

        if (temLap!=" " && temTV!=" " && temPrint!=" "){ui->Laptop->setText(temLap);ui->TVv->setText(temTV); ui->Printer->setText(temPrint);}

        if (temLap == " " && (temTV!=" " && temPrint!=" ")){ui->Laptop->setText(temTV); ui->TVv->setText(temPrint);}
        if (temLap == " " && temTV == " "){ui->Laptop->setText(temPrint);}
        if (temLap == " " && temPrint == " "){ui->Laptop->setText(temTV);}

        if (temTV == " " && (temLap!=" " && temPrint!=" ")){ui->Laptop->setText(temLap); ui->TVv->setText(temPrint);}
        if (temTV == " " && temPrint == " "){ui->Laptop->setText(temLap);}

        if (temPrint == " " && (temLap!=" " && temTV!=" ")){ui->Laptop->setText(temLap); ui->TVv->setText(temTV);}
    }

FinalWindow::~FinalWindow()
    {
        delete ui;
    }

void FinalWindow::on_pushButton_clicked()
{
    hide();
}


void FinalWindow::on_pushButton_2_clicked()
{
    QFile fileout("D:/TRY/BORYA5/BORYA5/files/cheque.txt");
    if(fileout.open(QIODevice::WriteOnly | QIODevice:: Text)){
        QTextStream out(&fileout);
        out<<(name+", your cheque: ")<<'\n'<<'\n';
        if (temLap != " ") out<<temLap<<'\n';
        if(temTV != " ") out<<temTV<<'\n';
        if (temPrint != " ") out<<temPrint<<'\n';
        out<<'\n'<<("Total price is: "+QString::number(tot))<<'\n'<<'\n';
        out<<"________________________THANK YOU_____________________"<<'\n';
        fileout.close();
    }

    QApplication::quit();
}

