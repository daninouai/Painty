#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include <string.h>

using namespace std;


class GLWidget : public QGLWidget {
Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();

    void paintGL();

    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void changeColor(float r, float g, float b);

    void changeFontSize(int);

    void chanageMode(bool, bool, bool, bool, bool, bool, bool);

    void drawPoint(int x, int y);

    void drawCircle(float x1, float y1, float x2, float y2);

    void drawSquare(float p1, float p2, float p3, float p4);

    void drawLine(float x1, float y1, float x2, float y2);

    void drawText(float x, float y, string txt);
};

#endif // GLWIDGET_H
