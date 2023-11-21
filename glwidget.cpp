#include "glwidget.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <QMouseEvent>
#include <iostream>
#include "pixel.h"
#include "toolCircle.h"
#include "toolSquare.h"
#include "toolLine.h"
#include "tools.h"
#include "toolText.h"
#include <string.h>
#include <QString>
#include <QInputDialog>
#include <QDebug>

using namespace std;

float red = 1.0, green = 0.0, blue = 0.0;
bool isPen = true;
bool isCircle = false;
bool isSquare = false;
bool isLine = false;
bool isEraser = false;
bool isSpray = false;
bool isText = false;
int fontSize = 5;

float X1 = 0;
float Y1 = 0;
float X2 = 0;
float Y2 = 0;

using namespace std;

std::vector<Pixel> pixel;
std::vector<toolCircle> circle;
std::vector<toolSquare> square;
std::vector<toolLine> line;
std::vector<Pixel> spray;
std::vector<toolText> text;

GLWidget::GLWidget(QWidget *parent) :
        QGLWidget(parent) {
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 1);
}

void GLWidget::drawPoint(int x, int y) {

    if (isSpray) {
        int sprayCount = 50;

        for (int i = 0; i < sprayCount; ++i) {
            int sprayX = x + rand() % 11 - 5;
            int sprayY = y + rand() % 11 - 5;

            Pixel sprayDot(sprayX, height() - sprayY, isEraser ? 0.0 : red, isEraser ? 0.0 : green,
                           isEraser ? 0.0 : blue);
            spray.push_back(sprayDot);
        }
    } else {
        Pixel newDot(x, height() - y, isEraser ? 0.0 : red, isEraser ? 0.0 : green, isEraser ? 0.0 : blue);
        pixel.push_back(newDot);
    }

    update();
}


void GLWidget::drawCircle(float x1, float y1, float x2, float y2) {
    toolCircle newCircle(x1, y1, x2, y2, red, green, blue);
    circle.push_back(newCircle);
    Point pos1;
    pos1.x = x1;
    pos1.y = y1;
    Point pos2;
    pos2.x = x2;
    pos2.y = y2;
    newCircle.calculateCircle(pos1, pos2);

    Point centerflo = newCircle.calculateCircle(pos1, pos2).center;
    double distanceflo = newCircle.calculateCircle(pos1, pos2).distance;

    newCircle.creatCircle(centerflo.x, centerflo.y, distanceflo);

    update();
}

void GLWidget::drawSquare(float p1, float p2, float p3, float p4) {
    toolSquare newSquare(p1, p2, p3, p4, red, green, blue);
    square.push_back(newSquare);
    Point pos1;
    pos1.x = p1;
    pos1.y = p2;
    Point pos2;
    pos2.x = p3;
    pos2.y = p4;
    newSquare.createSquare(pos1, pos2);
    update();
}

void GLWidget::drawLine(float x1, float y1, float x2, float y2) {
    toolLine newLine(x1, y1, x2, y2, red, green, blue);
    line.push_back(newLine);
    newLine.createLine(newLine.getX1(), newLine.getY1(), newLine.getX2(), newLine.getY2());
    update();
}

void GLWidget::drawText(float x, float y, string txt) {
    toolText newText(x, y, red, green, blue, txt);
    text.push_back(newText);
    newText.createText(newText.getX(), newText.getY(), txt);
    update();
}

void GLWidget::paintGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    for (unsigned int i = 0; i < circle.size(); i++) {
        glColor3f(circle[i].getR(), circle[i].getG(), circle[i].getB());
        Point pos1;
        pos1.x = circle[i].getX1();
        pos1.y = circle[i].getY1();
        Point pos2;
        pos2.x = circle[i].getX2();
        pos2.y = circle[i].getY2();

        Point centerflo = circle[i].calculateCircle(pos1, pos2).center;
        double distanceflo = circle[i].calculateCircle(pos1, pos2).distance;
        circle[i].creatCircle(centerflo.x, centerflo.y, distanceflo);
    }

    for (unsigned int i = 0; i < square.size(); i++) {
        glColor3f(square[i].getR(), square[i].getG(), square[i].getB());
        Point pos1;
        pos1.x = square[i].getP1();
        pos1.y = square[i].getP2();
        Point pos2;
        pos2.x = square[i].getP3();
        pos2.y = square[i].getP4();

        square[i].createSquare(pos1, pos2);
    }

    for (unsigned int i = 0; i < line.size(); i++) {
        glColor3f(line[i].getR(), line[i].getG(), line[i].getB());
        line[i].createLine(line[i].getX1(), line[i].getY1(), line[i].getX2(), line[i].getY2());
    }


    for (unsigned int i = 0; i < text.size(); i++) {
        glColor3f(text[i].getR(), text[i].getG(), text[i].getB());
        text[i].createText(text[i].getX(), text[i].getY(), text[i].getText());
    }

    glPointSize(1);
    glBegin(GL_POINTS);
    for (unsigned int i = 0; i < spray.size(); i++) {
        glColor3f(spray[i].getR(), spray[i].getG(), spray[i].getB());
        glVertex2i(spray[i].getX(), spray[i].getY());
    }
    glEnd();

    glPointSize(fontSize);
    glBegin(GL_POINTS);
    for (unsigned int i = 0; i < pixel.size(); i++) {
        glColor3f(pixel[i].getR(), pixel[i].getG(), pixel[i].getB());
        glVertex2i(pixel[i].getX(), pixel[i].getY());
    }
    glEnd();

    glFlush();
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    QPoint clickPos = event->pos();

    if (isPen == true) {
        drawPoint(clickPos.x(), clickPos.y());
    }

    if (isCircle == true) {
        if (X1 == 0) {
            X1 = clickPos.x();
            Y1 = 550 - clickPos.y();
        } else {
            X2 = clickPos.x();
            Y2 = 550 - clickPos.y();
        }
        if (X2 != 0) {
            drawCircle(X1, Y1, X2, Y2);
            X1 = 0;
            Y1 = 0;
            X2 = 0;
            Y2 = 0;
        }
    }

    if (isSquare == true) {
        if (X1 == 0) {
            X1 = clickPos.x();
            Y1 = 550 - clickPos.y();
        } else {
            X2 = clickPos.x();
            Y2 = 550 - clickPos.y();
        }
        if (X2 != 0) {
            drawSquare(X1, Y1, X2, Y2);
            X1 = 0;
            Y1 = 0;
            X2 = 0;
            Y2 = 0;
        }
    }

    if (isLine == true) {
        if (X1 == 0) {
            X1 = clickPos.x();
            Y1 = 550 - clickPos.y();
        } else {
            X2 = clickPos.x();
            Y2 = 550 - clickPos.y();
        }
        if (X2 != 0) {
            drawLine(X1, Y1, X2, Y2);
            X1 = 0;
            Y1 = 0;
            X2 = 0;
            Y2 = 0;
        }
    }

    if (isText) {
        bool ok;
        QString inputText = QInputDialog::getText(this, tr("Input Text"), tr("Enter your text:"), QLineEdit::Normal,
                                                  QString(), &ok);

        if (ok && !inputText.isEmpty()) {
            drawText(clickPos.x(), 550 - clickPos.y(), inputText.toStdString());
        } else {
            qDebug() << "Text input canceled.";
        }
    }

}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    QPoint clickPos = event->pos();

    if (isPen == true || isEraser == true || isSpray == true) {
        drawPoint(clickPos.x(), clickPos.y());
    }
}


void GLWidget::changeColor(float r, float g, float b) {
    red = r;
    green = g;
    blue = b;
}

void GLWidget::chanageMode(bool pen = false, bool circle = false, bool square = false, bool line = false,
                           bool eraser = false, bool spray = false, bool text = false) {
    if (pen == true) {
        isPen = true;
        isCircle = false;
        isSquare = false;
        isLine = false;
        isSpray = false;
        isEraser = false;
        isText = false;
    } else if (circle == true) {
        isCircle = true;
        isPen = false;
        isSquare = false;
        isLine = false;
        isSpray = false;
        isEraser = false;
        isText = false;
    } else if (square == true) {
        isSquare = true;
        isCircle = false;
        isPen = false;
        isLine = false;
        isSpray = false;
        isEraser = false;
        isText = false;
    } else if (line == true) {
        isLine = true;
        isSquare = false;
        isCircle = false;
        isPen = false;
        isSpray = false;
        isEraser = false;
        isText = false;
    } else if (eraser == true) {
        isEraser = true;
        isLine = false;
        isSquare = false;
        isCircle = false;
        isPen = false;
        isSpray = false;
        isText = false;
    } else if (spray == true) {
        isSpray = true;
        isEraser = false;
        isLine = false;
        isSquare = false;
        isCircle = false;
        isPen = false;
        isText = false;
    } else if (text == true) {
        isText = true;
        isSpray = false;
        isEraser = false;
        isLine = false;
        isSquare = false;
        isCircle = false;
        isPen = false;
    }
}

void GLWidget::changeFontSize(int size) {
    fontSize = size;
}