#include <QtTest>
#include <QTest>
#include <QString>

// add necessary includes here
#include "interfaces/iobjectmanager.h"
#include "objectmanager.h"
#include "interfaces/igameeventhandler.h"
#include "gameeventhandler.h"
#include "core/worldgenerator.h"
#include "tiles/forest.h"

class ObjManagerTest : public QObject
{
    Q_OBJECT

public:
    ObjManagerTest();
    ~ObjManagerTest();

private Q_SLOTS:
    void test_tile_generation();

};

ObjManagerTest::ObjManagerTest()
{

}

ObjManagerTest::~ObjManagerTest()
{

}

void ObjManagerTest::test_tile_generation()
{
    std::shared_ptr<Student::ObjectManager> objectManager =
    std::make_shared<Student::ObjectManager>();

    std::shared_ptr<Student::GameEventHandler> gameEventHandler =
    std::make_shared<Student::GameEventHandler>();

    for(unsigned int x = 0; x < 21 ; ++x)
    {
        for(unsigned int y = 0; y < 16 ; ++y)
        {
            Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
            worldGen.addConstructor<Course::Forest>(1);
            worldGen.generateMap(x,y,404, objectManager, gameEventHandler);

            //Generoituuko ja tallentuuko tileja oikea maara huomioiden generointiarvot.
            QCOMPARE(objectManager->getTiles().size(),x*y);
        }
    }
}

QTEST_APPLESS_MAIN(ObjManagerTest)

#include "tst_objmanagertest.moc"
