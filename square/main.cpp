#include "window.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
//    qDebug() << "Debug Message";
    QApplication a(argc, argv);
    a.setOverrideCursor( QCursor( Qt::BlankCursor ) );
    Window window;
    window.resize(640, 480);
    window.show();
//qDebug() << "Debug Message2";
    return a.exec();
}
