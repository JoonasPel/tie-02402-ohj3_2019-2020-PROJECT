#include "mapwindow.hh"
#include "dialog.h"

#include <QApplication>

#include "iostream"


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);    
    Dialog dia;
    MapWindow mapWindow;

    QObject::connect(&dia, &Dialog::sendtilecount,
                     &mapWindow, &MapWindow::draw_tiles);

    if(dia.exec() == QDialog::Accepted)
    {
        mapWindow.show();
    }

    return app.exec();
}
