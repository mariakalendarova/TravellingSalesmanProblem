#include "tsp_solver.h"
#include <QDebug>
#include <QList>
#include <QPair>
#include <QMap>
#include <QtMath>

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

QList<QString> TSPsolver::solveTSP(const QString& startCity) {
    QList<QString> tour;  // The tour being built
    QSet<QString> visited; // Set of visited cities
    QString currentCity = startCity;

    // Add the starting city to the tour and mark it as visited
    tour.append(currentCity);
    visited.insert(currentCity);

    while (visited.size() < cities.size()) {            // Continue until all cities are visited
        QString nearestCity;
        double minDistance = -1.0;

        // Iterate through all cities to find the nearest unvisited city
        for (const QString& city : cities.keys()) {
            if (!visited.contains(city)) {              // Only consider unvisited cities
                double dist = distance(currentCity, city);
                if (dist >= 0 && (minDistance < 0 || dist < minDistance)) {
                    minDistance = dist;
                    nearestCity = city;
                }
            }
        }

        if (!nearestCity.isEmpty()) {
            // Add the nearest unvisited city to the tour
            tour.append(nearestCity);
            visited.insert(nearestCity);                // Mark it as visited
            currentCity = nearestCity;                  // Move to this city
        } else {
            // If no unvisited connected cities are found, something went wrong
            qDebug() << "Error: No unvisited connected cities found.";
            return tour;                                // Return the partial tour
        }
    }

    // After visiting all cities, return to the starting city to complete the cycle
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
