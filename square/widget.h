#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

//! [0]
class Renderer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(Renderer *rnd, QWidget *parent);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Renderer *renderer;
    int elapsed;
};
//! [0]

#endif // WIDGET_H
