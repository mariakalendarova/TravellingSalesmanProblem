#ifndef UNDOROUTE_H
#define UNDOROUTE_H

#include <QUndoCommand>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QLineF>
#include <QString>

class RouteCommand : public QUndoCommand {
public:
    RouteCommand(QGraphicsScene* scene, const QString& city1Name, const QString& city2Name, QGraphicsLineItem* routeLine, QGraphicsTextItem* distanceLabel)
        : scene(scene), city1Name(city1Name), city2Name(city2Name), routeLine(routeLine), distanceLabel(distanceLabel) {
        setText("Add Route");
    }

    void undo() override {
        scene->removeItem(routeLine);
        scene->removeItem(distanceLabel);
    }

    void redo() override {
        scene->addItem(routeLine);
        scene->addItem(distanceLabel);
    }

private:
    QGraphicsScene* scene;
    QString city1Name;
    QString city2Name;
    QGraphicsLineItem* routeLine;
    QGraphicsTextItem* distanceLabel;
};


#endif // UNDOROUTE_H
