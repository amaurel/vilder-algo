#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "renderer.h"

//! [0]
class Renderer;

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(Renderer *rend, QWidget *parent);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Renderer *renderer;
    int elapsed;
};
//! [0]

#endif
