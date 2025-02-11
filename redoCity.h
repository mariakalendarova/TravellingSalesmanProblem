#include <QUndoCommand>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPointF>
#include <QString>

class CityRouteCommand : public QUndoCommand {
public:
    CityRouteCommand(QGraphicsScene* scene, const QString& cityName, const QPointF& position, QGraphicsEllipseItem* cityItem, QGraphicsTextItem* cityLabel)
        : scene(scene), cityName(cityName), position(position), cityItem(cityItem), cityLabel(cityLabel) {
        setText("Add City");
    }

    void undo() override {
        scene->removeItem(cityItem);
        scene->removeItem(cityLabel);
    }

    void redo() override {
        scene->addItem(cityItem);
        scene->addItem(cityLabel);
    }

private:
    QGraphicsScene* scene;
    QString cityName;
    QPointF position;
    QGraphicsEllipseItem* cityItem;
    QGraphicsTextItem* cityLabel;
};
