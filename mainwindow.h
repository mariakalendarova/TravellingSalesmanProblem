#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMap>
#include <QPointF>
#include <QPair> // Add this line
#include "tsp_solver.h" // Add this line
#include <QTimer> // Add this line
#include <QUndoStack>


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


    void on_redoButton_clicked();

    void on_undoButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QUndoStack *undoStack;
    QMap<QString, QPointF> cityMap;
    QMap<QPair<QString, QString>, double> routeMap; // Store routes and distances
    TSPsolver* tspSolver = nullptr; //instance of TSPsolver class
    void visualizeTour(const QList<QString>& tour);

    QTimer *timer;
    int tourIndex; // Current index in the tour
    QList<QString> currentTour; // Store the current tour being visualized
    double scaleFactor = 1.0; // Tracks the current scale factor

protected:
    void resizeEvent(QResizeEvent *event) override;


};

#endif // MAINWINDOW_H
