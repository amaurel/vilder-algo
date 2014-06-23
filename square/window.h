#ifndef WINDOW_H
#define WINDOW_H

#include "renderer.h"

#include <QGLWidget>
#include <QMainWindow>

//! [0]
class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window();

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    QGLWidget *openGL;
    Renderer renderer;
};
//! [0]

#endif // WINDOW_H
