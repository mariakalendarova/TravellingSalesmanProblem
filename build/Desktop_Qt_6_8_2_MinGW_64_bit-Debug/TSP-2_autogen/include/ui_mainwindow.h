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
    QLineEdit *distanceInput;
    QLineEdit *city1Input;
    QPushButton *addRouteButton;
    QPushButton *undoButton;
    QTextEdit *algorithmStepsTextEdit;
    QPushButton *startButton;
    QLineEdit *city2Input;
    QPushButton *resetButton;
    QGraphicsView *graphicsView;
    QPushButton *addCityButton;
    QPushButton *redoButton;
    QPushButton *saveGraphButton;
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

        gridLayout->addWidget(cityNameInput, 2, 0, 1, 4);

        distanceInput = new QLineEdit(centralwidget);
        distanceInput->setObjectName("distanceInput");

        gridLayout->addWidget(distanceInput, 4, 3, 1, 1);

        city1Input = new QLineEdit(centralwidget);
        city1Input->setObjectName("city1Input");

        gridLayout->addWidget(city1Input, 4, 0, 1, 1);

        addRouteButton = new QPushButton(centralwidget);
        addRouteButton->setObjectName("addRouteButton");

        gridLayout->addWidget(addRouteButton, 5, 0, 1, 4);

        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName("undoButton");

        gridLayout->addWidget(undoButton, 9, 4, 1, 1);

        algorithmStepsTextEdit = new QTextEdit(centralwidget);
        algorithmStepsTextEdit->setObjectName("algorithmStepsTextEdit");

        gridLayout->addWidget(algorithmStepsTextEdit, 8, 0, 1, 4);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        gridLayout->addWidget(startButton, 6, 2, 1, 2);

        city2Input = new QLineEdit(centralwidget);
        city2Input->setObjectName("city2Input");

        gridLayout->addWidget(city2Input, 4, 1, 1, 2);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");

        gridLayout->addWidget(resetButton, 6, 0, 1, 2);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 2, 4, 7, 1);

        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName("addCityButton");

        gridLayout->addWidget(addCityButton, 3, 0, 1, 4);

        redoButton = new QPushButton(centralwidget);
        redoButton->setObjectName("redoButton");

        gridLayout->addWidget(redoButton, 10, 4, 1, 1);

        saveGraphButton = new QPushButton(centralwidget);
        saveGraphButton->setObjectName("saveGraphButton");

        gridLayout->addWidget(saveGraphButton, 9, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1278, 21));
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
        distanceInput->setText(QString());
        city1Input->setText(QString());
        addRouteButton->setText(QCoreApplication::translate("MainWindow", "Add Route", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        city2Input->setText(QString());
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        addCityButton->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        redoButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        saveGraphButton->setText(QCoreApplication::translate("MainWindow", "Save Graph", nullptr));
        menuTSP->setTitle(QCoreApplication::translate("MainWindow", "TSP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
