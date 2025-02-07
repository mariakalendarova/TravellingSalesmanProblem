#ifndef TSPSOLVER_H
#define TSPSOLVER_H

#include <QMap>
#include <QPointF>
#include <QString>
#include <QPair>
#include <QList>
#include <QSet>


class TSPsolver {
public:
    TSPsolver(const QMap<QString, QPointF>& cities, const QMap<QPair<QString, QString>, double>& routes);
    QList<QString> solveTSP(const QString& startCity);

private:
    const QMap<QString, QPointF>& cities;
    const QMap<QPair<QString, QString>, double>& routes;
    double distance(const QString& city1, const QString& city2) const;
};

#endif // TSPSOLVER_H
