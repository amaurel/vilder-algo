#ifndef WINDOW_H
#define WINDOW_H

#include "renderer.h"

#include <QWidget>
#include <QWindow>
#include <QMainWindow>

//! [0]
class Window : public QMainWindow
        //QMainWindow
{
    Q_OBJECT

public:
    Window();

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    QWidget *openGL;
    Renderer renderer;
};
//! [0]

#endif // WINDOW_H
