/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QTextBrowser *InfoText;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_6;
    QLabel *MoneyLabel;
    QLabel *StoneLabel;
    QLabel *FoodLabel;
    QLabel *OreLabel;
    QLabel *WoodLabel;
    QLabel *TileTypeLabel;
    QPushButton *addBWButton;
    QPushButton *addAWButton;
    QLabel *statusLabel;
    QLabel *CurrentPlayerLabel;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_7;
    QLabel *MoneyPlayerLabel;
    QLabel *FoodPlayerLabel;
    QLabel *OrePlayerLabel;
    QLabel *WoodPlayerLabel;
    QLabel *StonePlayerLabel;
    QPushButton *TurnButton;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_8;
    QLabel *MoneyPlayerLabel_2;
    QLabel *OrePlayerLabel_2;
    QLabel *StonePlayerLabel_2;
    QLabel *FoodPlayerLabel_2;
    QLabel *WoodPlayerLabel_2;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QLabel *outpost_label;
    QLabel *hq_label;
    QLabel *farm_label;
    QLabel *mine_label;
    QPushButton *addSoldierButton;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *moneyPic;
    QLabel *foodPic;
    QLabel *woodPic;
    QLabel *stonePic;
    QLabel *orePic;
    QPushButton *pushButton_8;
    QLabel *np_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QString::fromUtf8("MapWindow"));
        MapWindow->resize(1420, 871);
        MapWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 1061, 791));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(1040, 675));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1273, 370, 111, 31));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1113, 370, 121, 31));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1113, 400, 121, 31));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(1273, 400, 111, 31));
        InfoText = new QTextBrowser(centralwidget);
        InfoText->setObjectName(QString::fromUtf8("InfoText"));
        InfoText->setGeometry(QRect(1080, 539, 151, 181));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(1250, 539, 61, 181));
        gridLayout_4 = new QGridLayout(gridLayoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_4->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout_4->addWidget(label_4, 2, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(1320, 539, 61, 181));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        MoneyLabel = new QLabel(gridLayoutWidget_2);
        MoneyLabel->setObjectName(QString::fromUtf8("MoneyLabel"));
        MoneyLabel->setFont(font);

        gridLayout_6->addWidget(MoneyLabel, 0, 0, 1, 1);

        StoneLabel = new QLabel(gridLayoutWidget_2);
        StoneLabel->setObjectName(QString::fromUtf8("StoneLabel"));
        StoneLabel->setFont(font);

        gridLayout_6->addWidget(StoneLabel, 3, 0, 1, 1);

        FoodLabel = new QLabel(gridLayoutWidget_2);
        FoodLabel->setObjectName(QString::fromUtf8("FoodLabel"));
        FoodLabel->setFont(font);

        gridLayout_6->addWidget(FoodLabel, 1, 0, 1, 1);

        OreLabel = new QLabel(gridLayoutWidget_2);
        OreLabel->setObjectName(QString::fromUtf8("OreLabel"));
        OreLabel->setFont(font);

        gridLayout_6->addWidget(OreLabel, 4, 0, 1, 1);

        WoodLabel = new QLabel(gridLayoutWidget_2);
        WoodLabel->setObjectName(QString::fromUtf8("WoodLabel"));
        WoodLabel->setFont(font);

        gridLayout_6->addWidget(WoodLabel, 2, 0, 1, 1);

        TileTypeLabel = new QLabel(centralwidget);
        TileTypeLabel->setObjectName(QString::fromUtf8("TileTypeLabel"));
        TileTypeLabel->setGeometry(QRect(1090, 489, 301, 41));
        QFont font1;
        font1.setPointSize(16);
        TileTypeLabel->setFont(font1);
        TileTypeLabel->setAutoFillBackground(false);
        TileTypeLabel->setAlignment(Qt::AlignCenter);
        addBWButton = new QPushButton(centralwidget);
        addBWButton->setObjectName(QString::fromUtf8("addBWButton"));
        addBWButton->setGeometry(QRect(1085, 300, 101, 51));
        addAWButton = new QPushButton(centralwidget);
        addAWButton->setObjectName(QString::fromUtf8("addAWButton"));
        addAWButton->setGeometry(QRect(1190, 300, 91, 51));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(10, 808, 1051, 31));
        QFont font2;
        font2.setPointSize(18);
        statusLabel->setFont(font2);
        statusLabel->setAlignment(Qt::AlignCenter);
        CurrentPlayerLabel = new QLabel(centralwidget);
        CurrentPlayerLabel->setObjectName(QString::fromUtf8("CurrentPlayerLabel"));
        CurrentPlayerLabel->setGeometry(QRect(1090, 5, 271, 31));
        QFont font3;
        font3.setPointSize(14);
        CurrentPlayerLabel->setFont(font3);
        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(1090, 85, 61, 181));
        gridLayoutWidget_4->setFont(font3);
        gridLayout_7 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        MoneyPlayerLabel = new QLabel(gridLayoutWidget_4);
        MoneyPlayerLabel->setObjectName(QString::fromUtf8("MoneyPlayerLabel"));
        QFont font4;
        font4.setPointSize(12);
        MoneyPlayerLabel->setFont(font4);

        gridLayout_7->addWidget(MoneyPlayerLabel, 0, 0, 1, 1);

        FoodPlayerLabel = new QLabel(gridLayoutWidget_4);
        FoodPlayerLabel->setObjectName(QString::fromUtf8("FoodPlayerLabel"));
        FoodPlayerLabel->setFont(font4);

        gridLayout_7->addWidget(FoodPlayerLabel, 1, 0, 1, 1);

        OrePlayerLabel = new QLabel(gridLayoutWidget_4);
        OrePlayerLabel->setObjectName(QString::fromUtf8("OrePlayerLabel"));
        OrePlayerLabel->setFont(font4);

        gridLayout_7->addWidget(OrePlayerLabel, 4, 0, 1, 1);

        WoodPlayerLabel = new QLabel(gridLayoutWidget_4);
        WoodPlayerLabel->setObjectName(QString::fromUtf8("WoodPlayerLabel"));
        WoodPlayerLabel->setFont(font4);

        gridLayout_7->addWidget(WoodPlayerLabel, 2, 0, 1, 1);

        StonePlayerLabel = new QLabel(gridLayoutWidget_4);
        StonePlayerLabel->setObjectName(QString::fromUtf8("StonePlayerLabel"));
        StonePlayerLabel->setFont(font4);

        gridLayout_7->addWidget(StonePlayerLabel, 3, 0, 1, 1);

        TurnButton = new QPushButton(centralwidget);
        TurnButton->setObjectName(QString::fromUtf8("TurnButton"));
        TurnButton->setGeometry(QRect(1080, 750, 321, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nirmala UI"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setUnderline(false);
        font5.setWeight(75);
        TurnButton->setFont(font5);
        TurnButton->setMouseTracking(false);
        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(1310, 85, 61, 181));
        gridLayoutWidget_5->setFont(font3);
        gridLayout_8 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        MoneyPlayerLabel_2 = new QLabel(gridLayoutWidget_5);
        MoneyPlayerLabel_2->setObjectName(QString::fromUtf8("MoneyPlayerLabel_2"));
        MoneyPlayerLabel_2->setFont(font4);

        gridLayout_8->addWidget(MoneyPlayerLabel_2, 0, 0, 1, 1);

        OrePlayerLabel_2 = new QLabel(gridLayoutWidget_5);
        OrePlayerLabel_2->setObjectName(QString::fromUtf8("OrePlayerLabel_2"));
        OrePlayerLabel_2->setFont(font4);

        gridLayout_8->addWidget(OrePlayerLabel_2, 4, 0, 1, 1);

        StonePlayerLabel_2 = new QLabel(gridLayoutWidget_5);
        StonePlayerLabel_2->setObjectName(QString::fromUtf8("StonePlayerLabel_2"));
        StonePlayerLabel_2->setFont(font4);

        gridLayout_8->addWidget(StonePlayerLabel_2, 3, 0, 1, 1);

        FoodPlayerLabel_2 = new QLabel(gridLayoutWidget_5);
        FoodPlayerLabel_2->setObjectName(QString::fromUtf8("FoodPlayerLabel_2"));
        FoodPlayerLabel_2->setFont(font4);

        gridLayout_8->addWidget(FoodPlayerLabel_2, 1, 0, 1, 1);

        WoodPlayerLabel_2 = new QLabel(gridLayoutWidget_5);
        WoodPlayerLabel_2->setObjectName(QString::fromUtf8("WoodPlayerLabel_2"));
        WoodPlayerLabel_2->setFont(font4);

        gridLayout_8->addWidget(WoodPlayerLabel_2, 2, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1290, 50, 141, 21));
        QFont font6;
        font6.setPointSize(10);
        label_11->setFont(font6);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(1080, 50, 91, 21));
        label_12->setFont(font6);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(1080, 257, 321, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(1080, 220, 321, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(1080, 184, 321, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(1080, 146, 321, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(1080, 109, 321, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(1080, 75, 321, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(1242, 564, 151, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(1242, 600, 151, 20));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(1242, 638, 151, 20));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(1242, 675, 151, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(1242, 709, 151, 20));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(centralwidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(1242, 530, 151, 20));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(centralwidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(1080, 360, 321, 20));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        outpost_label = new QLabel(centralwidget);
        outpost_label->setObjectName(QString::fromUtf8("outpost_label"));
        outpost_label->setGeometry(QRect(1083, 370, 31, 31));
        hq_label = new QLabel(centralwidget);
        hq_label->setObjectName(QString::fromUtf8("hq_label"));
        hq_label->setGeometry(QRect(1083, 400, 31, 31));
        farm_label = new QLabel(centralwidget);
        farm_label->setObjectName(QString::fromUtf8("farm_label"));
        farm_label->setGeometry(QRect(1243, 370, 31, 31));
        mine_label = new QLabel(centralwidget);
        mine_label->setObjectName(QString::fromUtf8("mine_label"));
        mine_label->setGeometry(QRect(1243, 400, 31, 31));
        addSoldierButton = new QPushButton(centralwidget);
        addSoldierButton->setObjectName(QString::fromUtf8("addSoldierButton"));
        addSoldierButton->setGeometry(QRect(1290, 300, 91, 51));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1180, 230, 59, 31));
        QFont font7;
        font7.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font7.setPointSize(11);
        font7.setBold(true);
        font7.setWeight(75);
        label_9->setFont(font7);
        label_9->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1180, 193, 59, 31));
        label_7->setFont(font7);
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1180, 156, 59, 31));
        label_10->setFont(font7);
        label_10->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1180, 119, 59, 31));
        label_8->setFont(font7);
        label_8->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1180, 82, 59, 31));
        label_6->setFont(font7);
        label_6->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1240, 85, 49, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        moneyPic = new QLabel(verticalLayoutWidget);
        moneyPic->setObjectName(QString::fromUtf8("moneyPic"));

        verticalLayout->addWidget(moneyPic);

        foodPic = new QLabel(verticalLayoutWidget);
        foodPic->setObjectName(QString::fromUtf8("foodPic"));

        verticalLayout->addWidget(foodPic);

        woodPic = new QLabel(verticalLayoutWidget);
        woodPic->setObjectName(QString::fromUtf8("woodPic"));

        verticalLayout->addWidget(woodPic);

        stonePic = new QLabel(verticalLayoutWidget);
        stonePic->setObjectName(QString::fromUtf8("stonePic"));

        verticalLayout->addWidget(stonePic);

        orePic = new QLabel(verticalLayoutWidget);
        orePic->setObjectName(QString::fromUtf8("orePic"));

        verticalLayout->addWidget(orePic);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(1273, 430, 111, 31));
        np_label = new QLabel(centralwidget);
        np_label->setObjectName(QString::fromUtf8("np_label"));
        np_label->setGeometry(QRect(1240, 430, 31, 31));
        MapWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MapWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1420, 21));
        MapWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MapWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MapWindow->setStatusBar(statusbar);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MainWindow", nullptr));
        pushButton_4->setText(QApplication::translate("MapWindow", "Build Farm", nullptr));
        pushButton_5->setText(QApplication::translate("MapWindow", "Build Outpost", nullptr));
        pushButton_6->setText(QApplication::translate("MapWindow", "Build HQ", nullptr));
        pushButton_7->setText(QApplication::translate("MapWindow", "Build Mine", nullptr));
        label->setText(QApplication::translate("MapWindow", "MONEY", nullptr));
        label_2->setText(QApplication::translate("MapWindow", "STONE", nullptr));
        label_3->setText(QApplication::translate("MapWindow", "FOOD", nullptr));
        label_5->setText(QApplication::translate("MapWindow", "ORE", nullptr));
        label_4->setText(QApplication::translate("MapWindow", "WOOD", nullptr));
        MoneyLabel->setText(QString());
        StoneLabel->setText(QString());
        FoodLabel->setText(QString());
        OreLabel->setText(QString());
        WoodLabel->setText(QString());
        TileTypeLabel->setText(QString());
        addBWButton->setText(QApplication::translate("MapWindow", "Add BasicWorker", nullptr));
        addAWButton->setText(QApplication::translate("MapWindow", "Add\n"
" AdvancedWorker", nullptr));
        statusLabel->setText(QString());
        CurrentPlayerLabel->setText(QApplication::translate("MapWindow", "Current player: ", nullptr));
        MoneyPlayerLabel->setText(QString());
        FoodPlayerLabel->setText(QString());
        OrePlayerLabel->setText(QString());
        WoodPlayerLabel->setText(QString());
        StonePlayerLabel->setText(QString());
        TurnButton->setText(QApplication::translate("MapWindow", "END TURN", nullptr));
        MoneyPlayerLabel_2->setText(QString());
        OrePlayerLabel_2->setText(QString());
        StonePlayerLabel_2->setText(QString());
        FoodPlayerLabel_2->setText(QString());
        WoodPlayerLabel_2->setText(QString());
        label_11->setText(QApplication::translate("MapWindow", "Current production", nullptr));
        label_12->setText(QApplication::translate("MapWindow", "Total resources", nullptr));
        outpost_label->setText(QApplication::translate("MapWindow", "2", nullptr));
        hq_label->setText(QString());
        farm_label->setText(QString());
        mine_label->setText(QString());
        addSoldierButton->setText(QApplication::translate("MapWindow", "Add Soldier", nullptr));
        label_9->setText(QApplication::translate("MapWindow", "ORE", nullptr));
        label_7->setText(QApplication::translate("MapWindow", "STONE", nullptr));
        label_10->setText(QApplication::translate("MapWindow", "WOOD", nullptr));
        label_8->setText(QApplication::translate("MapWindow", "FOOD", nullptr));
        label_6->setText(QApplication::translate("MapWindow", "MONEY", nullptr));
        moneyPic->setText(QApplication::translate("MapWindow", "TextLabel", nullptr));
        foodPic->setText(QApplication::translate("MapWindow", "TextLabel", nullptr));
        woodPic->setText(QApplication::translate("MapWindow", "TextLabel", nullptr));
        stonePic->setText(QApplication::translate("MapWindow", "TextLabel", nullptr));
        orePic->setText(QApplication::translate("MapWindow", "TextLabel", nullptr));
        pushButton_8->setText(QApplication::translate("MapWindow", "Build Nuclearplant", nullptr));
        np_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
