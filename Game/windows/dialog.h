#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    virtual int exec();

signals:
    void sendPlayerName(std::string name1,std::string name2);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
