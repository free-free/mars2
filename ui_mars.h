/********************************************************************************
** Form generated from reading UI file 'mars.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARS_H
#define UI_MARS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mars
{
public:
    QAction *connectSPAction;
    QAction *disconnectSPAction;
    QAction *exitAppAction;
    QAction *serialPortProtocolDialogAction;
    QAction *aboutAction;
    QAction *exportAction;
    QAction *clearScreenAction;
    QAction *serialPortConfigDialogAction;
    QAction *importAction;
    QAction *saveGraphAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *mainWidget;
    QGroupBox *horizontalGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *horizontalGroupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *modeBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *modeRadioButtonLayout;
    QRadioButton *pModeRadioButton;
    QRadioButton *plModeRadioButton;
    QRadioButton *tModeRadioButton;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *forceCurveCheckBox;
    QCheckBox *displacementCurveCheckBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *formLayout;
    QMenuBar *menuBar;
    QMenu *helpMenu;
    QMenu *protocolDescription;
    QMenu *toolsMenu;
    QMenu *configurationsMenu;
    QMenu *menu;
    QMenu *serialPortMenu;

    void setupUi(QMainWindow *Mars)
    {
        if (Mars->objectName().isEmpty())
            Mars->setObjectName(QStringLiteral("Mars"));
        Mars->resize(629, 397);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/mars"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/icon/mars"), QSize(), QIcon::Disabled, QIcon::Off);
        Mars->setWindowIcon(icon);
        Mars->setStyleSheet(QStringLiteral(""));
        connectSPAction = new QAction(Mars);
        connectSPAction->setObjectName(QStringLiteral("connectSPAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/sp_connect"), QSize(), QIcon::Normal, QIcon::Off);
        connectSPAction->setIcon(icon1);
        disconnectSPAction = new QAction(Mars);
        disconnectSPAction->setObjectName(QStringLiteral("disconnectSPAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/sp_disconnect"), QSize(), QIcon::Normal, QIcon::Off);
        disconnectSPAction->setIcon(icon2);
        exitAppAction = new QAction(Mars);
        exitAppAction->setObjectName(QStringLiteral("exitAppAction"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/exit"), QSize(), QIcon::Normal, QIcon::Off);
        exitAppAction->setIcon(icon3);
        serialPortProtocolDialogAction = new QAction(Mars);
        serialPortProtocolDialogAction->setObjectName(QStringLiteral("serialPortProtocolDialogAction"));
        aboutAction = new QAction(Mars);
        aboutAction->setObjectName(QStringLiteral("aboutAction"));
        exportAction = new QAction(Mars);
        exportAction->setObjectName(QStringLiteral("exportAction"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/export"), QSize(), QIcon::Normal, QIcon::Off);
        exportAction->setIcon(icon4);
        clearScreenAction = new QAction(Mars);
        clearScreenAction->setObjectName(QStringLiteral("clearScreenAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/clear"), QSize(), QIcon::Normal, QIcon::Off);
        clearScreenAction->setIcon(icon5);
        serialPortConfigDialogAction = new QAction(Mars);
        serialPortConfigDialogAction->setObjectName(QStringLiteral("serialPortConfigDialogAction"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/settings"), QSize(), QIcon::Normal, QIcon::Off);
        serialPortConfigDialogAction->setIcon(icon6);
        importAction = new QAction(Mars);
        importAction->setObjectName(QStringLiteral("importAction"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/import"), QSize(), QIcon::Normal, QIcon::Off);
        importAction->setIcon(icon7);
        saveGraphAction = new QAction(Mars);
        saveGraphAction->setObjectName(QStringLiteral("saveGraphAction"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/graph"), QSize(), QIcon::Normal, QIcon::Off);
        saveGraphAction->setIcon(icon8);
        centralWidget = new QWidget(Mars);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(50, 50, 50, 255));"));

        verticalLayout_2->addWidget(mainWidget);

        horizontalGroupBox = new QGroupBox(centralWidget);
        horizontalGroupBox->setObjectName(QStringLiteral("horizontalGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalGroupBox->sizePolicy().hasHeightForWidth());
        horizontalGroupBox->setSizePolicy(sizePolicy1);
        horizontalGroupBox->setMaximumSize(QSize(16777215, 140));
        horizontalGroupBox->setStyleSheet(QLatin1String("QGroupBox{\n"
"padding:0px 0px 0px 0px;\n"
"margin:0px 0px 0px 0px;\n"
"border:0px 0px 0px 0px;\n"
"}\n"
""));
        horizontalGroupBox->setFlat(true);
        horizontalLayout_4 = new QHBoxLayout(horizontalGroupBox);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalGroupBox_2 = new QGroupBox(horizontalGroupBox);
        horizontalGroupBox_2->setObjectName(QStringLiteral("horizontalGroupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalGroupBox_2->sizePolicy().hasHeightForWidth());
        horizontalGroupBox_2->setSizePolicy(sizePolicy2);
        horizontalGroupBox_2->setMinimumSize(QSize(300, 0));
        horizontalGroupBox_2->setMaximumSize(QSize(300, 16777215));
        horizontalGroupBox_2->setStyleSheet(QLatin1String("\n"
"padding:0px 0px 0px 0px;\n"
"margin:0px 0px 0px 0px;\n"
"border:0px 0px 0px 0px;"));
        horizontalLayout_5 = new QHBoxLayout(horizontalGroupBox_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        modeBox = new QGroupBox(horizontalGroupBox_2);
        modeBox->setObjectName(QStringLiteral("modeBox"));
        sizePolicy2.setHeightForWidth(modeBox->sizePolicy().hasHeightForWidth());
        modeBox->setSizePolicy(sizePolicy2);
        modeBox->setMinimumSize(QSize(0, 0));
        modeBox->setMaximumSize(QSize(160, 16777215));
        modeBox->setStyleSheet(QStringLiteral("font-weight:bold"));
        modeBox->setFlat(true);
        verticalLayoutWidget_2 = new QWidget(modeBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(30, 30, 101, 91));
        modeRadioButtonLayout = new QVBoxLayout(verticalLayoutWidget_2);
        modeRadioButtonLayout->setSpacing(0);
        modeRadioButtonLayout->setContentsMargins(11, 11, 11, 11);
        modeRadioButtonLayout->setObjectName(QStringLiteral("modeRadioButtonLayout"));
        modeRadioButtonLayout->setContentsMargins(0, 0, 0, 0);
        pModeRadioButton = new QRadioButton(verticalLayoutWidget_2);
        pModeRadioButton->setObjectName(QStringLiteral("pModeRadioButton"));
        pModeRadioButton->setFocusPolicy(Qt::NoFocus);
        pModeRadioButton->setStyleSheet(QLatin1String("border:none;\n"
"font-weight:normal;"));

        modeRadioButtonLayout->addWidget(pModeRadioButton);

        plModeRadioButton = new QRadioButton(verticalLayoutWidget_2);
        plModeRadioButton->setObjectName(QStringLiteral("plModeRadioButton"));
        plModeRadioButton->setFocusPolicy(Qt::NoFocus);
        plModeRadioButton->setStyleSheet(QLatin1String("border:none;\n"
"font-weight:normal;\n"
""));

        modeRadioButtonLayout->addWidget(plModeRadioButton);

        tModeRadioButton = new QRadioButton(verticalLayoutWidget_2);
        tModeRadioButton->setObjectName(QStringLiteral("tModeRadioButton"));
        tModeRadioButton->setFocusPolicy(Qt::NoFocus);
        tModeRadioButton->setStyleSheet(QLatin1String("border:none;\n"
"font-weight:normal;"));

        modeRadioButtonLayout->addWidget(tModeRadioButton);


        horizontalLayout_5->addWidget(modeBox);

        groupBox_2 = new QGroupBox(horizontalGroupBox_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMaximumSize(QSize(160, 16777215));
        groupBox_2->setStyleSheet(QLatin1String("font-weight:bold\n"
""));
        groupBox_2->setFlat(true);
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(30, 30, 101, 81));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        forceCurveCheckBox = new QCheckBox(verticalLayoutWidget_3);
        forceCurveCheckBox->setObjectName(QStringLiteral("forceCurveCheckBox"));
        forceCurveCheckBox->setFocusPolicy(Qt::NoFocus);
        forceCurveCheckBox->setStyleSheet(QLatin1String("border:none;\n"
"font-weight:normal;"));

        verticalLayout_4->addWidget(forceCurveCheckBox);

        displacementCurveCheckBox = new QCheckBox(verticalLayoutWidget_3);
        displacementCurveCheckBox->setObjectName(QStringLiteral("displacementCurveCheckBox"));
        displacementCurveCheckBox->setFocusPolicy(Qt::NoFocus);
        displacementCurveCheckBox->setStyleSheet(QLatin1String("border:none;\n"
"font-weight:normal;"));

        verticalLayout_4->addWidget(displacementCurveCheckBox);


        horizontalLayout_5->addWidget(groupBox_2);


        horizontalLayout_4->addWidget(horizontalGroupBox_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(horizontalGroupBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(100, 0));
        groupBox->setMaximumSize(QSize(100, 16777215));
        groupBox->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 86, 88));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.354067 rgba(15, 174, 10, 255), stop:1 rgba(100, 200, 100, 255));\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	padding-top:5px;\n"
"  padding-bottom:5px;\n"
"  color:white;\n"
" border: 1px solid #aaa;\n"
"\n"
"}\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(15, 174, 10, 255), stop:1 rgba(100, 200, 100, 255));\n"
"}"));
        pushButton->setFlat(false);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"   \n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0.46, x2:0, y2:1, stop:0.354067 rgba(247, 0, 29, 255), stop:1 rgba(255, 20, 60, 255));\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	padding-top:5px;\n"
"   padding-bottom:5px;\n"
"   color:white;\n"
"   border: 1px solid #aaa;\n"
"\n"
"}\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.0239234 rgba(247, 0, 29, 255), stop:1 rgba(255, 100, 100, 255));\n"
"}"));

        verticalLayout->addWidget(pushButton_2);


        gridLayout_2->addWidget(groupBox, 3, 1, 1, 1);

        formLayout = new QVBoxLayout();
        formLayout->setSpacing(0);
        formLayout->setObjectName(QStringLiteral("formLayout"));

        gridLayout_2->addLayout(formLayout, 3, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_2);


        verticalLayout_2->addWidget(horizontalGroupBox);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        Mars->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mars);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 26));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy3);
        menuBar->setStyleSheet(QLatin1String("QMenuBar{\n"
"					padding-top:0px;\n"
"                 padding-bottom:0px;\n"
"					height:26px;\n"
"					background-color:qlineargradient(spread:reflect, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(50, 50, 50, 255), stop:1 rgba(150, 150, 150, 255));\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"				 margin: 0px 0px 0px 0px;\n"
"					background-color:qlineargradient(spread:reflect, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(50, 50, 50, 255), stop:1 rgba(150, 150, 150, 255));\n"
"                color:white; \n"
"                padding:0px 10px 0px 10px;\n"
"}\n"
"QMenuBar::item:pressed{\n"
"				background-color:#666;\n"
"		       color:#efefef;\n"
"}\n"
"/*\n"
"QMenu{\n"
"                   background-color:#555;\n"
"                   border:0px 0px 0px 0px;\n"
"                   color:#f1f1f1;\n"
"}\n"
"*/\n"
"/*\n"
"QMenu::item{\n"
"                 padding:3px 50px;\n"
"                    margin:0px 0px 0px 0px;\n"
"                    font-weight:400;\n"
"                }\n"
"QMenu::item:tearoff{\n"
"                    colo"
                        "r:#efefef;\n"
"}\n"
"*/\n"
"QMenu::separator {\n"
"                    height: 1px;\n"
"}\n"
"QMenu::item:selected{\n"
"	    background-color: rgb(255, 94, 0);\n"
"}\n"
"QMenu::item::pressed{\n"
"		background-color: rgb(255, 94, 0);\n"
"}\n"
""));
        menuBar->setNativeMenuBar(false);
        helpMenu = new QMenu(menuBar);
        helpMenu->setObjectName(QStringLiteral("helpMenu"));
        protocolDescription = new QMenu(helpMenu);
        protocolDescription->setObjectName(QStringLiteral("protocolDescription"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/connect-protocol"), QSize(), QIcon::Normal, QIcon::Off);
        protocolDescription->setIcon(icon9);
        toolsMenu = new QMenu(menuBar);
        toolsMenu->setObjectName(QStringLiteral("toolsMenu"));
        configurationsMenu = new QMenu(menuBar);
        configurationsMenu->setObjectName(QStringLiteral("configurationsMenu"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        serialPortMenu = new QMenu(menu);
        serialPortMenu->setObjectName(QStringLiteral("serialPortMenu"));
        Mars->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(toolsMenu->menuAction());
        menuBar->addAction(configurationsMenu->menuAction());
        menuBar->addAction(helpMenu->menuAction());
        helpMenu->addAction(protocolDescription->menuAction());
        helpMenu->addAction(aboutAction);
        protocolDescription->addAction(serialPortProtocolDialogAction);
        toolsMenu->addAction(clearScreenAction);
        toolsMenu->addAction(exportAction);
        toolsMenu->addAction(importAction);
        toolsMenu->addAction(saveGraphAction);
        configurationsMenu->addAction(serialPortConfigDialogAction);
        menu->addAction(serialPortMenu->menuAction());
        menu->addAction(exitAppAction);
        serialPortMenu->addAction(connectSPAction);
        serialPortMenu->addAction(disconnectSPAction);

        retranslateUi(Mars);

        QMetaObject::connectSlotsByName(Mars);
    } // setupUi

    void retranslateUi(QMainWindow *Mars)
    {
        Mars->setWindowTitle(QApplication::translate("Mars", "Mars", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Mars->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Mars->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Mars->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        Mars->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        Mars->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        connectSPAction->setText(QApplication::translate("Mars", "\350\277\236\346\216\245\344\270\262\345\217\243\n"
"", Q_NULLPTR));
        disconnectSPAction->setText(QApplication::translate("Mars", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        exitAppAction->setText(QApplication::translate("Mars", "\351\200\200\345\207\272", Q_NULLPTR));
        serialPortProtocolDialogAction->setText(QApplication::translate("Mars", "\344\270\262\345\217\243\345\215\217\350\256\256", Q_NULLPTR));
        aboutAction->setText(QApplication::translate("Mars", " \345\205\263\344\272\216", Q_NULLPTR));
        exportAction->setText(QApplication::translate("Mars", "\345\257\274\345\207\272\346\225\260\346\215\256", Q_NULLPTR));
        exportAction->setShortcut(QApplication::translate("Mars", "Ctrl+E", Q_NULLPTR));
        clearScreenAction->setText(QApplication::translate("Mars", "\346\270\205\351\231\244\345\261\217\345\271\225", Q_NULLPTR));
        clearScreenAction->setShortcut(QApplication::translate("Mars", "Ctrl+C", Q_NULLPTR));
        serialPortConfigDialogAction->setText(QApplication::translate("Mars", "\344\270\262\345\217\243\351\205\215\347\275\256", Q_NULLPTR));
        serialPortConfigDialogAction->setShortcut(QApplication::translate("Mars", "Ctrl+S", Q_NULLPTR));
        importAction->setText(QApplication::translate("Mars", "\345\257\274\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        importAction->setShortcut(QApplication::translate("Mars", "Ctrl+I", Q_NULLPTR));
        saveGraphAction->setText(QApplication::translate("Mars", "\344\277\235\345\255\230\345\233\276\345\203\217", Q_NULLPTR));
        saveGraphAction->setShortcut(QApplication::translate("Mars", "Ctrl+S", Q_NULLPTR));
        modeBox->setTitle(QApplication::translate("Mars", "  \346\250\241\345\274\217\351\200\211\346\213\251", Q_NULLPTR));
        pModeRadioButton->setText(QApplication::translate("Mars", "\344\275\215\347\275\256\346\250\241\345\274\217", Q_NULLPTR));
        plModeRadioButton->setText(QApplication::translate("Mars", "\346\201\222\345\256\232\350\275\275\350\215\267", Q_NULLPTR));
        tModeRadioButton->setText(QApplication::translate("Mars", "\351\234\207\345\212\250\346\265\213\350\257\225", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Mars", "\346\230\276\347\244\272\346\233\262\347\272\277 ", Q_NULLPTR));
        forceCurveCheckBox->setText(QApplication::translate("Mars", "\345\212\233\346\233\262\347\272\277", Q_NULLPTR));
        displacementCurveCheckBox->setText(QApplication::translate("Mars", "\344\275\215\347\247\273\346\233\262\347\272\277", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Mars", "\350\256\276\347\275\256\345\217\202\346\225\260", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Mars", "\345\201\234    \346\255\242", Q_NULLPTR));
        helpMenu->setTitle(QApplication::translate("Mars", "\345\270\256\345\212\251", Q_NULLPTR));
        protocolDescription->setTitle(QApplication::translate("Mars", "\350\277\236\346\216\245\345\215\217\350\256\256", Q_NULLPTR));
        toolsMenu->setTitle(QApplication::translate("Mars", "\345\267\245\345\205\267", Q_NULLPTR));
        configurationsMenu->setTitle(QApplication::translate("Mars", "\351\205\215\347\275\256", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Mars", "\350\277\236\346\216\245\n"
"", Q_NULLPTR));
        serialPortMenu->setTitle(QApplication::translate("Mars", "\344\270\262\345\217\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Mars: public Ui_Mars {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARS_H
