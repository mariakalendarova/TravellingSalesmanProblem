#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QRandomGenerator>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600); // Set the scene rectangle here, adjust size if needed
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

    const int nodeSize = 60;
    const int minDistance = 100; // Minimum distance between nodes

    QRectF sceneRect = scene->sceneRect();

    QPointF position;
    bool validPosition = false;
    int attempts = 0;
    const int maxAttempts = 100; // Limit attempts to prevent infinite loop

    while (!validPosition && attempts < maxAttempts) {
        attempts++;
        qreal x = QRandomGenerator::global()->generateDouble() * (sceneRect.width() - nodeSize) + sceneRect.x() + nodeSize/2;
        qreal y = QRandomGenerator::global()->generateDouble() * (sceneRect.height() - nodeSize) + sceneRect.y() + nodeSize/2;
        position = QPointF(x, y);

        validPosition = true;
        for (const QPointF& existingPosition : cityMap.values()) {
            qreal distance = qSqrt(qPow(position.x() - existingPosition.x(), 2) +
                                   qPow(position.y() - existingPosition.y(), 2));
            if (distance < minDistance) {
                validPosition = false;
                break; // Reject and try again
            }
        }
    }

    if (!validPosition) {
        QMessageBox::warning(this, "Warning", "Could not find a valid position after " + QString::number(maxAttempts) + " attempts!");
        return;
    }

    QGraphicsEllipseItem *city = new QGraphicsEllipseItem(position.x() - nodeSize/2, position.y() - nodeSize/2, nodeSize, nodeSize);
    city->setBrush(Qt::white);
    scene->addItem(city);

    QPointF center(position.x(), position.y());
    cityMap[cityName] = center;

    QGraphicsTextItem *cityLabel = new QGraphicsTextItem(cityName);
    QFont font("Arial", 12);
    cityLabel->setFont(font);

    // Get the bounding rectangle of the text
    QRectF textRect = cityLabel->boundingRect();

    // Center the text within the circle
    cityLabel->setPos(position.x() - textRect.width() / 2, position.y() - textRect.height() / 2);

    cityLabel->setDefaultTextColor(Qt::black);
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

    // Calculate offset to avoid starting inside the circle
    const int nodeSize = 60; // Same size used for drawing cities
    QLineF line(pos1, pos2);
    double length = line.length();

    if (length > nodeSize) {
        double ratio = (nodeSize / 2) / length;
        QPointF offsetPos1(pos1.x() + ratio * (pos2.x() - pos1.x()),
                           pos1.y() + ratio * (pos2.y() - pos1.y()));

        QPointF offsetPos2(pos2.x() - ratio * (pos2.x() - pos1.x()),
                           pos2.y() - ratio * (pos2.y() - pos1.y()));

        QGraphicsLineItem *routeLine = new QGraphicsLineItem(QLineF(offsetPos1, offsetPos2));

        QPen pen(Qt::darkGreen);
        pen.setWidth(3);
        routeLine->setPen(pen);

        scene->addItem(routeLine);

        // Adjust distance label position accordingly
        QPointF midPoint((offsetPos1.x() + offsetPos2.x()) / 2,
                         (offsetPos1.y() + offsetPos2.y()) / 2);

        QGraphicsTextItem *distanceLabel = new QGraphicsTextItem(QString("%1 km").arg(distance));

        distanceLabel->setPos(midPoint.x(), midPoint.y());

        // Ensure the text remains on top of the lines
        distanceLabel->setZValue(2); // Higher value than lines

        distanceLabel->setDefaultTextColor(Qt::white);

        distanceLabel->setFont(QFont("Arial", 12));

        scene->addItem(distanceLabel);

    } else { // If line is too short to adjust without intersecting circles
        QMessageBox::warning(this, "Warning", "Cities are too close.");
        return;
    }
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

    timer->start(2000);
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

        // Calculate offset to avoid starting inside the circle
        const int nodeSize = 60; // Same size used for drawing cities
        QLineF line(pos1, pos2);
        double length = line.length();

        QPointF adjustedPos1 = pos1;
        QPointF adjustedPos2 = pos2;

        // If line length is greater than the node size, adjust the positions
        if (length > nodeSize) {
            double ratio = (nodeSize / 2) / length;
            adjustedPos1 = QPointF(pos1.x() + ratio * (pos2.x() - pos1.x()),
                                   pos1.y() + ratio * (pos2.y() - pos1.y()));

            adjustedPos2 = QPointF(pos2.x() - ratio * (pos2.x() - pos1.x()),
                                   pos2.y() - ratio * (pos2.y() - pos1.y()));
        }

        // Create the route line with adjusted positions
        QGraphicsLineItem *tourLine = new QGraphicsLineItem(QLineF(adjustedPos1, adjustedPos2));
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



