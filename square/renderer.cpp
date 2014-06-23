#include "renderer.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

Renderer::Renderer()
{
    background = QBrush(QColor(255, 255, 255));
    color = QBrush(QColor(0, 0, 0));
    nRows = 20;
    nCols = 15;

    patternWidth = 50;
    patternHeight = 50;

    int s = nCols *  nRows;

    rectWidths1 = new double[s];
    rectWidths2 = new double[s];
    recWidthSpeed = new double[s];
    rectHeight1 = new double[s];
    rectHeight2 = new double[s];
    recHeightSpeed = new double[s];

    rectWidthsDirection1 = new int[s];
    rectWidthsDirection2 = new int[s];

    rectHeightDirection1 = new int[s];
    rectHeightDirection2 = new int[s];

    for (int ci = 0 ; ci < nCols ; ci++){
        for (int ri = 0 ; ri < nRows ; ri++){
            int i = indexAt(ci,ri);
            double r = 0.0;
            r = (double)rand() / (double)RAND_MAX;
            rectWidths1[i] = patternWidth * r;
            if (r > 0.5) rectWidthsDirection1[i]=1;
            else rectWidthsDirection1[i]=-1;
            recWidthSpeed[i] = 1.0 + r;

            r = (double)rand() / (double)RAND_MAX;
            rectWidths2[i] = patternWidth * r;
            if (r > 0.5) rectWidthsDirection2[i]=1;
            else rectWidthsDirection2[i]=-1;

            r = (double)rand() / (double)RAND_MAX;
            rectHeight1[i] = patternHeight * r;
            if (r > 0.5) rectHeightDirection1[i]=1;
            else rectHeightDirection1[i]=-1;
            recHeightSpeed[i] = 1.0 + r;

            r = (double)rand() / (double)RAND_MAX;
            rectHeight2[i] = patternHeight * r;
            if (r > 0.5) rectHeightDirection2[i]=1;
            else rectHeightDirection2[i]=-1;
        }
    }

}

int Renderer::indexAt(int col, int row){
    return col * nRows + row;
}

void Renderer::initialize(Options *opt){
    options = opt;
    background = QBrush(QColor(255, 255, 255));
    color = QBrush(QColor(0, 0, 0));
}

void Renderer::incr(double * rectSizes, int * rectSizesDirection, double * speed, double maxValue){
    int s = nRows*nCols;
    for (int i = 0 ; i < s ; i++){
        rectSizes[i] = rectSizes[i] +  (rectSizesDirection[i] * speed[i]);
        if (rectSizes[i] > maxValue){
            rectSizes[i] = maxValue;
            rectSizesDirection[i] = -1;
        }
        if (rectSizes[i] < 0.0){
            rectSizes[i] = 0.0;
            rectSizesDirection[i] = 1;
        }
    }
}



void Renderer::paint(QPainter *painter, QPaintEvent *event, int elapsed){
    painter->fillRect(event->rect(), background);
//    painter->translate(100, 100);
//! [1]

//! [2]
    painter->save();
    painter->setBrush(color);

    double x;
    double y;
    double w;
    double h;

    incr(rectWidths1, rectWidthsDirection1,recWidthSpeed,patternWidth);
    incr(rectWidths2, rectWidthsDirection2,recWidthSpeed,patternWidth);

    incr(rectHeight1, rectHeightDirection1,recHeightSpeed,patternHeight);
    incr(rectHeight2, rectHeightDirection2,recHeightSpeed,patternHeight);


    for (int ci = 0 ; ci < nCols ; ci++){
        double xoff = ci * patternWidth * 2;
        for (int ri = 0 ; ri < nRows ; ri++){

            int i = indexAt(ci,ri);


            double yoff = ri * patternHeight * 2;

            x = xoff;
            y = yoff;


            h = patternHeight;
            w = rectWidths1[i];


            painter->fillRect(x, y, w, h, color);

//////////////////////////////////////////////////////////////////////////

            w = rectWidths2[i];

            y = (yoff) + patternHeight;
            x = (xoff) +  patternWidth + (patternWidth - w);

            painter->fillRect(x, y, w+1, h, color);

//////////////////////////////////////////////////////////////////////////

            x = (xoff) + patternWidth;
            y = yoff;
            w = patternWidth;
            h = rectHeight1[i];

            painter->fillRect(x, y, w, h, color);

//////////////////////////////////////////////////////////////////////////
            h = rectHeight2[i];
            w = patternWidth;
            x = xoff;
            y = (yoff) + patternHeight + (patternHeight - h);

            painter->fillRect(x, y, w, h+1, color);

        }
    }

    painter->restore();
}
