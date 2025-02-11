/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *cityNameInput;
    QGraphicsView *graphicsView;
    QPushButton *addCityButton;
    QLineEdit *city1Input;
    QLineEdit *city2Input;
    QLineEdit *distanceInput;
    QPushButton *addRouteButton;
    QPushButton *resetButton;
    QPushButton *startButton;
    QTextEdit *algorithmStepsTextEdit;
    QMenuBar *menubar;
    QMenu *menuTSP;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1278, 877);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMaximumSize(QSize(1603, 679));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        cityNameInput = new QLineEdit(centralwidget);
        cityNameInput->setObjectName("cityNameInput");

        gridLayout->addWidget(cityNameInput, 0, 0, 1, 4);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 4, 6, 1);

        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName("addCityButton");

        gridLayout->addWidget(addCityButton, 1, 0, 1, 4);

        city1Input = new QLineEdit(centralwidget);
        city1Input->setObjectName("city1Input");

        gridLayout->addWidget(city1Input, 2, 0, 1, 1);

        city2Input = new QLineEdit(centralwidget);
        city2Input->setObjectName("city2Input");

        gridLayout->addWidget(city2Input, 2, 1, 1, 2);

        distanceInput = new QLineEdit(centralwidget);
        distanceInput->setObjectName("distanceInput");

        gridLayout->addWidget(distanceInput, 2, 3, 1, 1);

        addRouteButton = new QPushButton(centralwidget);
        addRouteButton->setObjectName("addRouteButton");

        gridLayout->addWidget(addRouteButton, 3, 0, 1, 4);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");

        gridLayout->addWidget(resetButton, 4, 0, 1, 2);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        gridLayout->addWidget(startButton, 4, 2, 1, 2);

        algorithmStepsTextEdit = new QTextEdit(centralwidget);
        algorithmStepsTextEdit->setObjectName("algorithmStepsTextEdit");

        gridLayout->addWidget(algorithmStepsTextEdit, 5, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1278, 37));
        menuTSP = new QMenu(menubar);
        menuTSP->setObjectName("menuTSP");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTSP->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addCityButton->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        city1Input->setText(QString());
        city2Input->setText(QString());
        distanceInput->setText(QString());
        addRouteButton->setText(QCoreApplication::translate("MainWindow", "Add Route", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        menuTSP->setTitle(QCoreApplication::translate("MainWindow", "TSP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
