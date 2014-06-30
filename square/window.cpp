#include "window.h"

//#include "glwidget.h"
#include "widget.h"

#include "window.h"

#include <QHBoxLayout>


#include <QTimer>


#include <QResizeEvent>

//! [0]
Window::Window()
{
    setWindowTitle(tr("Vilder square"));


//    openGL = new GLWidget(&renderer, this);
    openGL = new Widget(&renderer, this);


    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), openGL, SLOT(animate()));
    timer->start(100);
    QTimer::singleShot(1000, this, SLOT(showFullScreen()));
}

void Window::resizeEvent(QResizeEvent *evt){
    QMainWindow::resizeEvent(evt);
    openGL->resize(evt->size().width(), evt->size().height());
}
