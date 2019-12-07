#include "mapwindow.hh"
#include "windows/dialog.h"

#include <QApplication>

#include "iostream"



int main(int argc, char* argv[])
{

    QApplication app(argc, argv);    
    Dialog dia;
    MapWindow mapWindow;



    QObject::connect(&dia, &Dialog::sendPlayerName,
                     &mapWindow, &MapWindow::init_game);
    dia.setWindowTitle("Settings");
    if(dia.exec() == QDialog::Accepted)
    {
        mapWindow.show();
    }

    return app.exec();
}
