#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QEvent>

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

#include "graphics/simplegamescene.h"
#include "graphics/simplemapitem.h"

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

    //dialog lahettaa tiilien lukumaaran ja tama tallentaa sen.
    void draw_tiles(int value);


private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<Course::iGameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Course::SimpleGameScene> m_simplescene = nullptr;

    std::shared_ptr<Student::GameEventHandler> gameEventHandler;
    std::shared_ptr<Student::ObjectManager> objectManager;

    std::shared_ptr<Student::Player> player1;


//    bool event(QEvent* event);



};

#endif // MapWINDOW_HH

