#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMap>
#include <QPointF>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT // Ensure this macro is present

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addCityButton_clicked();
    void on_addRouteButton_clicked();
    void on_resetButton_clicked(); // Declare the reset button slot here

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene; // Scene for graphics view
    QMap<QString, QPointF> cityMap; // Map city names to their positions
};

#endif // MAINWINDOW_H
