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
#include "water.h"
#include <desert.h>
#include "rocky_mountains.h"
#include "buildings/farm.h"
#include "studentoutpost.h"
#include "buildings/headquarters.h"
#include "mine.h"
#include "nuclearplant.h"
#include "buildings/buildingbase.h"
#include "interfaces/igameeventhandler.h"
#include "graphics/simplegamescene.h"
#include "objectmanager.h"
#include "gameeventhandler.h"
#include "core/resourcemaps.h"
#include "core/basicresources.h"
#include "workers/basicworker.h"
#include "advancedworker.h"
#include "eliteworker.h"
#include "soldier.h"
#include "player.h"
#include <cstdlib>
#include <stdio.h>
#include <time.h>

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
    void setStatus(std::string text);
    QPixmap getImageByString(std::string building_name);
    void paintWorker(std::shared_ptr<Course::TileBase> tile);
    void paintBuilding(std::shared_ptr<Course::TileBase> tile,QPixmap building);
    void update_player_resources();
    void add_new_worker(std::shared_ptr<Course::WorkerBase> worker, Course::ResourceMap cost, std::shared_ptr<Course::TileBase> tile);
    bool add_new_building(std::shared_ptr<Course::BuildingBase> building, Course::ResourceMap cost);
    void draw_tiles();
    void print_total_production();
    void gamewon();

public slots:


    void print_tile_info(Course::Coordinate coordinates);
    //Tallentaa tilen koordinaatit, jota klikattu viimeksi, eli joka on "aktiivinen".
    void save_activate_tile(Course::Coordinate coordinates);
    void init_game(std::string name1, std::string name2);

private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<Course::iGameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::GameScene> m_gamescene = nullptr;

    std::shared_ptr<Student::GameEventHandler> gameEventHandler;
    std::shared_ptr<Student::ObjectManager> objectManager;

    std::shared_ptr<Student::Player> player1;
    std::shared_ptr<Student::Player> player2;
    std::shared_ptr<Student::Player> current_player;

    Course::Coordinate last_clicked_tile;

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

    void on_addBWButton_clicked();
    void on_addAWButton_clicked();

    void on_TurnButton_clicked();
    void on_addEWButton_clicked();
    void on_pushButton_8_clicked();
};

#endif // MapWINDOW_HH

