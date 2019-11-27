#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->horizontalSlider->setMaximum(300);
    ui->horizontalSlider->setMinimum(300);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::exec()
{
    int dialog = QDialog::exec();

    if(dialog == QDialog::Accepted)
    {
        emit sendtilecount(ui->horizontalSlider->value());
    }
    return dialog; //
}
