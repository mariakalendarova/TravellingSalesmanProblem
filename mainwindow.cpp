#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a graphics scene and set it to the QGraphicsView
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addCityButton_clicked() {
    QString cityName = ui->cityNameInput->text().trimmed(); // Get city name from input field
    if (cityName.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a valid city name.");
        return;
    }

    if (cityMap.contains(cityName)) {
        QMessageBox::warning(this, "Warning", "City already exists.");
        return;
    }

    // Generate random position for the city
    double x = rand() % 400; // Random x-coordinate (adjust as needed)
    double y = rand() % 300; // Random y-coordinate (adjust as needed)

    // Create a larger circle representing the city
    QGraphicsEllipseItem *city = new QGraphicsEllipseItem(x, y, 60, 60); // Circle size: 60x60
    city->setBrush(Qt::white); // Set circle color to white

    scene->addItem(city);

    // Store the city's name and position in the map
    QPointF center(x + 30, y + 30); // Center point of the circle
    cityMap[cityName] = center;

    // Add city name inside the circle
    QGraphicsTextItem *cityLabel = new QGraphicsTextItem(cityName);
    cityLabel->setPos(center.x() - 20, center.y() - 10); // Adjust position to fit in circle
    cityLabel->setDefaultTextColor(Qt::black); // Set text color to black
    cityLabel->setFont(QFont("Arial", 12)); // Set font size to 12

    scene->addItem(cityLabel);

    ui->cityNameInput->clear(); // Clear input field after adding
}

void MainWindow::on_addRouteButton_clicked() {
    QString city1Name = ui->city1Input->text().trimmed(); // Get first city name
    QString city2Name = ui->city2Input->text().trimmed(); // Get second city name
    QString distanceStr = ui->distanceInput->text().trimmed(); // Get distance

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

    // Draw a line between the two cities with dark green color and increased thickness
    QPointF pos1 = cityMap[city1Name];
    QPointF pos2 = cityMap[city2Name];

    QGraphicsLineItem *route = new QGraphicsLineItem(QLineF(pos1, pos2));

    QPen pen(Qt::darkGreen);
    pen.setWidth(3); // Set line thickness to 3 pixels
    route->setPen(pen);

    scene->addItem(route);

    // Add distance label on top of the route with larger font size
    QGraphicsTextItem *distanceLabel = new QGraphicsTextItem(QString("%1 km").arg(distance));

    // Calculate midpoint for placing distance label
    QPointF midPoint((pos1.x() + pos2.x()) / 2, (pos1.y() + pos2.y()) / 2);

    distanceLabel->setPos(midPoint.x(), midPoint.y() - 10); // Position it slightly above midpoint of route
    distanceLabel->setDefaultTextColor(Qt::black); // Set text color to black
    distanceLabel->setFont(QFont("Arial", 12)); // Set font size to 12

    scene->addItem(distanceLabel);
}

void MainWindow::on_resetButton_clicked() {
    // Clear all items from the scene and reset data structures
    scene->clear();          // Clear all graphical items from the view
    cityMap.clear();         // Clear all stored cities

    // Clear input fields for user convenience
    ui->cityNameInput->clear();
    ui->city1Input->clear();
    ui->city2Input->clear();
    ui->distanceInput->clear();
}
