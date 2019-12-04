#include <QtTest>

// add necessary includes here

class ObjManagerTest : public QObject
{
    Q_OBJECT

public:
    ObjManagerTest();
    ~ObjManagerTest();

private slots:
    void test_case1();

};

ObjManagerTest::ObjManagerTest()
{

}

ObjManagerTest::~ObjManagerTest()
{

}

void ObjManagerTest::test_case1()
{

}

QTEST_APPLESS_MAIN(ObjManagerTest)

#include "tst_objmanagertest.moc"
