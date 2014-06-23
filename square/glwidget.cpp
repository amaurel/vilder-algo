#include "glwidget.h"
#include "renderer.h"

#include <QTimer>

//! [0]
GLWidget::GLWidget(Renderer *rend, QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent), renderer(rend)
{
    elapsed = 0;
    //setFixedSize(200, 200);
    setAutoFillBackground(false);
}
//! [0]

//! [1]
void GLWidget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    repaint();
}
//! [1]

//! [2]
void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    renderer->paint(&painter, event, elapsed);
    painter.end();
}
//! [2]
