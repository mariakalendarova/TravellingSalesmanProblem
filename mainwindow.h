#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMap>
#include <QPointF>
#include <QPair>
#include <QTimer>
#include <QUndoStack>

#include "tsp_solver.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addCityButton_clicked();
    void on_addRouteButton_clicked();
    void on_resetButton_clicked();
    void on_startButton_clicked();
    void visualizeNextCity();
    void resetCityHighlights();
    void on_redoButton_clicked();
    void on_undoButton_clicked();
    void on_saveGraphButton_clicked();
    void on_loadGraphButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QUndoStack *undoStack;
    QMap<QString, QPointF> cityMap;
    QMap<QPair<QString, QString>, double> routeMap;         // Store routes and distances
    TSPsolver* tspSolver = nullptr;
    void visualizeTour(const QList<QString>& tour);

    QTimer *timer;
    int tourIndex;
    QList<QString> currentTour;
    double scaleFactor = 1.0;
    QSet<QString> visitedCities;
    QString getCityNameFromEllipse(QGraphicsEllipseItem *cityItem);



protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // MAINWINDOW_H
