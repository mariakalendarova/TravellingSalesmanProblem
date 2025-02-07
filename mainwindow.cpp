#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::visualizeNextCity); // Connect timer to new slot
    tourIndex = 0;
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addCityButton_clicked() {
    QString cityName = ui->cityNameInput->text().trimmed();
    if (cityName.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a valid city name.");
        return;
    }

    if (cityMap.contains(cityName)) {
        QMessageBox::warning(this, "Warning", "City already exists.");
        return;
    }

    double x = rand() % 400;
    double y = rand() % 300;

    QGraphicsEllipseItem *city = new QGraphicsEllipseItem(x, y, 60, 60);
    city->setBrush(Qt::white);
    scene->addItem(city);

    QPointF center(x + 30, y + 30);
    cityMap[cityName] = center;

    QGraphicsTextItem *cityLabel = new QGraphicsTextItem(cityName);
    cityLabel->setPos(center.x() - 20, center.y() - 10);
    cityLabel->setDefaultTextColor(Qt::black);
    cityLabel->setFont(QFont("Arial", 12));

    scene->addItem(cityLabel);

    ui->cityNameInput->clear();
}

void MainWindow::on_addRouteButton_clicked() {
    QString city1Name = ui->city1Input->text().trimmed();
    QString city2Name = ui->city2Input->text().trimmed();
    QString distanceStr = ui->distanceInput->text().trimmed();

    if (!cityMap.contains(city1Name) || !cityMap.contains(city2Name)) {
        QMessageBox::warning(this, "Warning", "One or both cities do not exist.");
        return;
    }

    if (city1Name == city2Name) {
        QMessageBox::warning(this, "Warning", "Cannot connect a city to itself.");
        return;
    }

    bool ok;
    double distance = distanceStr.toDouble(&ok);
    if (!ok || distance <= 0) {
        QMessageBox::warning(this, "Warning", "Please enter a valid distance.");
        return;
    }

    // Store the route and distance
    QPair<QString, QString> route(city1Name, city2Name);
    routeMap[route] = distance;

    QPointF pos1 = cityMap[city1Name];
    QPointF pos2 = cityMap[city2Name];

    QGraphicsLineItem *routeLine = new QGraphicsLineItem(QLineF(pos1, pos2));

    QPen pen(Qt::darkGreen);
    pen.setWidth(3);
    routeLine->setPen(pen);

    scene->addItem(routeLine);

    QGraphicsTextItem *distanceLabel = new QGraphicsTextItem(QString("%1 km").arg(distance));
    QPointF midPoint((pos1.x() + pos2.x()) / 2, (pos1.y() + pos2.y()) / 2);
    distanceLabel->setPos(midPoint.x(), midPoint.y() - 10);
    distanceLabel->setDefaultTextColor(Qt::black);
    distanceLabel->setFont(QFont("Arial", 12));

    scene->addItem(distanceLabel);
}


void MainWindow::on_resetButton_clicked() {
    scene->clear();
    cityMap.clear();
    routeMap.clear(); // Clear the routes as well

    ui->cityNameInput->clear();
    ui->city1Input->clear();
    ui->city2Input->clear();
    ui->distanceInput->clear();
}

void MainWindow::on_startButton_clicked() {
    if (cityMap.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please add cities before starting the algorithm.");
        return;
    }

    tspSolver = new TSPsolver(cityMap, routeMap);

    QString startCity = cityMap.keys().first();
    currentTour = tspSolver->solveTSP(startCity);

    tourIndex = 0;

    // Clear the QTextEdit at the start of the algorithm
    ui->algorithmStepsTextEdit->clear();

    timer->start(500);
}



void MainWindow::visualizeNextCity() {
    if (tourIndex < currentTour.size() - 1) {
        QString city1Name = currentTour[tourIndex];
        QString city2Name = currentTour[tourIndex + 1];

        // Append the algorithm step to the QTextEdit
        QString stepText = QString("Step %1: Start at node %2, Next city node %3\n")
                               .arg(tourIndex + 1)
                               .arg(city1Name)
                               .arg(city2Name);
        ui->algorithmStepsTextEdit->append(stepText);

        QPointF pos1 = cityMap[city1Name];
        QPointF pos2 = cityMap[city2Name];

        QGraphicsLineItem *tourLine = new QGraphicsLineItem(QLineF(pos1, pos2));
        QPen pen(Qt::red);
        pen.setWidth(5);
        tourLine->setPen(pen);
        scene->addItem(tourLine);

        tourIndex++; // Increment the index for the next city
    } else {
        timer->stop(); // Stop the timer when the tour is complete
        QString finalText = QString("Final Tour Complete!\n");
        ui->algorithmStepsTextEdit->append(finalText);
    }
}


