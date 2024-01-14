#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "finalwindow.h"

extern QString temLap;
extern QString temTV;
extern QString temPrint;
extern int tot;

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::SecondWindow *ui;
    FinalWindow *window2;
};

#endif // SECONDWINDOW_H
