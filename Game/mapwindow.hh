#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QEvent>
#include <QApplication>
#include "exceptions/illegalaction.h"

#include <math.h>
#include <map>

#include "tiles/tilebase.h"
#include <tiles/forest.h>
#include <tiles/grassland.h>
#include <desert.h>
#include "buildings/farm.h"
#include "buildings/headquarters.h"
#include "buildings/buildingbase.h"
#include "interfaces/igameeventhandler.h"
#include "graphics/simplegamescene.h"
#include "objectmanager.h"
#include "gameeventhandler.h"
#include "core/resourcemaps.h"
#include "workers/basicworker.h"
#include "player.h"

#include "windows/gamescene.h"
#include "graphics/simplemapitem.h"
#include <QPainter>
#include <QPoint>

namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<Course::iGameEventHandler> GEHandler = {}
                       );
    ~MapWindow();

    void setGEHandler(std::shared_ptr<Course::iGameEventHandler> nHandler);

    void setSize(int width, int height);
    void setScale(int scale);
    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);


public slots:

    void draw_tiles(int value);
    void print_tile_info(Course::Coordinate coordinates);
    //Tallentaa tilen koordinaatit, jota klikattu viimeksi, eli joka on "aktiivinen".
    void save_activate_tile(Course::Coordinate coordinates);


private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<Course::iGameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::GameScene> m_gamescene = nullptr;

    std::shared_ptr<Student::GameEventHandler> gameEventHandler;
    std::shared_ptr<Student::ObjectManager> objectManager;

    std::shared_ptr<Student::Player> player1;
    Course::Coordinate last_clicked_tile;

private slots:
    void on_pushButton_4_clicked();

    void on_addBWButton_clicked();




};

#endif // MapWINDOW_HH

