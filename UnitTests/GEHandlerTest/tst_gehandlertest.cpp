#include <QtTest>

// add necessary includes here
#include "interfaces/igameeventhandler.h"
#include "gameeventhandler.h"

class GEHandlerTest : public QObject
{
    Q_OBJECT

public:
    GEHandlerTest();
    ~GEHandlerTest();

private Q_SLOTS:
    void test_case1();

};

GEHandlerTest::GEHandlerTest()
{

}

GEHandlerTest::~GEHandlerTest()
{

}

void GEHandlerTest::test_case1()
{

}

QTEST_APPLESS_MAIN(GEHandlerTest)

#include "tst_gehandlertest.moc"
