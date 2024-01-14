#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "finalwindow.h"

int lap, lap_s;
int TV,TV_s;
int Printer,Printer_s;
int lapP;//н
int TVPrice;
int PrintPrice;
int tot = 0;

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    window2 = nullptr;

    QFile file(":/files/products.txt");

    if (!file.exists()) {
        qDebug() << "Файл не найден";
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Ошибка открытия файла";
        return;
    }

    QTextStream in(&file);

    int supercoun = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();

        QStringList keys = line.split('|');

        int coun = 0;

        for (const QString& key : keys) {
            bool help;
            if (coun == 0 && supercoun == 0) {ui->Laptop->setText(key);}
            if (coun == 0 && supercoun == 1) {ui->TV->setText(key);}
            if (coun == 0 && supercoun == 2) {ui->Printer->setText(key);}
            if (coun == 1 && supercoun == 0) {lap = key.toInt(&help);lap_s = key.toInt(&help);}
            if (coun == 1 && supercoun == 1) {TV = key.toInt(&help);TV_s = key.toInt(&help);}
            if (coun == 1 && supercoun == 2) {Printer = key.toInt(&help);Printer_s = key.toInt(&help);}
            if (coun == 2 && supercoun == 0) {lapP = key.toInt(&help);}
            if (coun == 2 && supercoun == 1) {TVPrice = key.toInt(&help);}
            if (coun == 2 && supercoun == 2) {PrintPrice = key.toInt(&help);}
            coun++;
            qDebug() << key;
        }
        supercoun ++;
    }

    ui->LP->setText(QString::number(lap));
    ui->TVP->setText(QString::number(TV));
    ui->PP->setText(QString::number(Printer));
    ui->lapPrice->setText(QString::number(lapP));
    ui->TVPrice->setText(QString::number(TVPrice));
    ui->printerPrice->setText(QString::number(PrintPrice));

    file.close();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

QString temLap = " ";
QString temTV = " ";
QString temPrint = " ";


void SecondWindow::on_pushButton_clicked()
{
    if (lap >0){
    lap -= 1;

    ui->LP->setText(QString::number(lap));
    if (lap !=lap_s){
        ui->lapBas->setText("Laptop "+QString::number(lap_s-lap));
        if ((lap_s-lap) != 0) temLap = ("Laptop "+QString::number(lap_s-lap)); else temLap = " ";
        if (lap != lap_s) tot += lapP;
        ui->total->setText("Total: "+QString::number(tot));
    }
    if (lap == -1) lap = 0;
    }
}

void SecondWindow::on_pushButton_2_clicked()
{
    if (lap < lap_s){
    tot -= lapP;
    lap += 1;
        ui->LP->setText(QString::number(lap));}
    if (lap <= lap_s){
        ui->lapBas->setText("Laptop "+QString::number(lap_s-lap));
        if ((lap_s-lap) != 0) temLap = ("Laptop "+QString::number(lap_s-lap)); else temLap = " ";
        ui->total->setText("Total: "+QString::number(tot));
        if (lap == lap_s){ui->lapBas->setText("⠀");}
    }
}

void SecondWindow::on_pushButton_5_clicked()
{
    if (TV < TV_s){
        tot -= TVPrice;
        TV += 1;
        ui->TVP->setText(QString::number(TV));}
    if (TV <= TV_s){
        ui->TVBas->setText("TV "+QString::number(TV_s-TV));
        if ((TV_s-TV) != 0) temTV = ("TV "+QString::number(TV_s-TV)); else temTV = " ";
        ui->total->setText("Total: "+QString::number(tot));
        if (TV == TV_s){ui->TVBas->setText("⠀"); temTV = " ";}
    }
}


void SecondWindow::on_pushButton_3_clicked()
{
    if (TV > 0){
    TV -= 1;
    ui->TVP->setText(QString::number(TV));
    if (TV !=TV_s){
        ui->TVBas->setText("TV "+QString::number(TV_s-TV));
        temTV = ("TV "+QString::number(TV_s-TV));
        if (TV != TV_s) tot += TVPrice;
        ui->total->setText("Total: "+QString::number(tot));
    }
    }
}


void SecondWindow::on_pushButton_4_clicked()
{
    if (Printer > 0){
    Printer -= 1;
    ui->PP->setText(QString::number(Printer));
    if (Printer !=Printer_s){
        ui->PrintBas->setText("Printer "+QString::number(Printer_s-Printer));
        temPrint = ("Printer "+QString::number(Printer_s-Printer));
        if (Printer != Printer_s) tot += PrintPrice;
        ui->total->setText("Total: "+QString::number(tot));
    }
    }
}


void SecondWindow::on_pushButton_6_clicked()
{
    if (Printer < Printer_s){
        tot -= PrintPrice;
        Printer += 1;
        ui->PP->setText(QString::number(Printer));}
    if (Printer <= Printer_s){
        ui->PrintBas->setText("Printer "+QString::number(Printer_s-Printer));
        if ((Printer_s-Printer) != 0) temPrint = ("Printer "+QString::number(Printer_s-Printer)); else temPrint = " ";
        ui->total->setText("Total: "+QString::number(tot));
        if (Printer == Printer_s){ui->PrintBas->setText("⠀");}
    }
}


void SecondWindow::on_pushButton_7_clicked()
{

    window2 = new FinalWindow;
    window2->setModal(true);
    window2->show();
}

