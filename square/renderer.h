#ifndef RENDERER_H
#define RENDERER_H

#include <QBrush>
//#include <QFont>
//#include <QPen>
#include <QWidget>


#include "options.h"


class Renderer
{
public:
    Renderer();

public:
    void initialize(Options *opt);
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);
    int indexAt(int col, int row);
    void incr(double * rectSizes, int * rectSizesDirection, double * speed, double maxValue);

public:
    Options *options;
private:
    QBrush background;
    QBrush color;

    int nRows;
    int nCols;
    double patternWidth;
    double patternHeight;

    double * rectWidths1;
    double * rectWidths2;
    double * recWidthSpeed;

    double * rectHeight1;
    double * rectHeight2;
    double * recHeightSpeed;

    int * rectWidthsDirection1;
    int * rectWidthsDirection2;

    int * rectHeightDirection1;
    int * rectHeightDirection2;


};

#endif // RENDERER_H
