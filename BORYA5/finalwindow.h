#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QDialog>

namespace Ui {
class FinalWindow;
}

class FinalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FinalWindow(QWidget *parent = nullptr);
    ~FinalWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FinalWindow *ui;

};

#endif // SECONDWINDOW_H
