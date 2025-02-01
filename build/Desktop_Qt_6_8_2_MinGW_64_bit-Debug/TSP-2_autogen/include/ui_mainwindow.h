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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *addCityButton;
    QPushButton *addRouteButton;
    QLineEdit *cityNameInput;
    QLineEdit *city1Input;
    QLineEdit *city2Input;
    QLineEdit *distanceInput;
    QPushButton *resetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 701, 551));
        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName("addCityButton");
        addCityButton->setGeometry(QRect(0, 30, 601, 31));
        addRouteButton = new QPushButton(centralwidget);
        addRouteButton->setObjectName("addRouteButton");
        addRouteButton->setGeometry(QRect(0, 80, 601, 31));
        cityNameInput = new QLineEdit(centralwidget);
        cityNameInput->setObjectName("cityNameInput");
        cityNameInput->setGeometry(QRect(0, 0, 601, 31));
        city1Input = new QLineEdit(centralwidget);
        city1Input->setObjectName("city1Input");
        city1Input->setGeometry(QRect(0, 60, 191, 21));
        city2Input = new QLineEdit(centralwidget);
        city2Input->setObjectName("city2Input");
        city2Input->setGeometry(QRect(190, 60, 211, 21));
        distanceInput = new QLineEdit(centralwidget);
        distanceInput->setObjectName("distanceInput");
        distanceInput->setGeometry(QRect(400, 60, 201, 21));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(600, 0, 101, 111));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addCityButton->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        addRouteButton->setText(QCoreApplication::translate("MainWindow", "Add Route", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
