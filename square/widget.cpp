#include "widget.h"

#include "renderer.h"

#include <QPainter>
#include <QTimer>

//! [0]
Widget::Widget(Renderer *rnd, QWidget *parent)
    : QWidget(parent), renderer(rnd)
{
    elapsed = 0;
//    setFixedSize(200, 200);
}
//! [0]

//! [1]
void Widget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    repaint();
}
//! [1]

//! [2]
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    renderer->paint(&painter, event, elapsed);
    painter.end();
}
//! [2]
