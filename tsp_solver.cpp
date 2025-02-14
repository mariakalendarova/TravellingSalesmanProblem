#include "tsp_solver.h"
#include <QDebug>
#include <QList>
#include <QPair>
#include <QMap>
#include <QtMath>
#include <QRandomGenerator>

TSPsolver::TSPsolver(const QMap<QString, QPointF>& cities, const QMap<QPair<QString, QString>, double>& routes)
    : cities(cities), routes(routes) {
    for (const QString& city1 : cities.keys()) {
        for (const QString& city2 : cities.keys()) {
            if (city1 != city2) {
                QPair<QString, QString> route(city1, city2);
                if (!routes.contains(route) && !routes.contains(qMakePair(city2, city1))) {
                    qDebug() << "Warning: No route defined between " << city1 << " and " << city2;
                }
            }
        }
    }
}

QList<QString> TSPsolver::solveTSP() {
    QList<QString> tour;
    QSet<QString> visited;

    if (cities.isEmpty()) {
        qDebug() << "Error: No cities available.";
        return tour;
    }

    // Select a random starting city
    QStringList cityList = cities.keys();
    QString startCity = cityList.at(QRandomGenerator::global()->bounded(cityList.size()));

    QString currentCity = startCity;
    tour.append(currentCity);
    visited.insert(currentCity);

    while (visited.size() < cities.size()) {
        QString nearestCity;
        double minDistance = -1.0;

        for (const QString& city : cities.keys()) {
            if (!visited.contains(city)) {
                double dist = distance(currentCity, city);
                if (dist >= 0 && (minDistance < 0 || dist < minDistance)) {
                    minDistance = dist;
                    nearestCity = city;
                }
            }
        }

        if (!nearestCity.isEmpty()) {
            tour.append(nearestCity);
            visited.insert(nearestCity);
            currentCity = nearestCity;
        } else {
            qDebug() << "Error: No unvisited connected cities found.";
            return tour;
        }
    }

    // Return to the starting city
    tour.append(startCity);
    return tour;
}


double TSPsolver::distance(const QString& city1, const QString& city2) const {
    QPair<QString, QString> route(city1, city2);
    if (routes.contains(route)) {
        return routes[route];
    } else {
        // Check the reverse direction in case the route was added in the opposite order
        route = QPair<QString, QString>(city2, city1);
        if (routes.contains(route)) {
            return routes[route];
        } else {
            return -1.0;                            // Indicate no direct route exists
        }
    }
}
