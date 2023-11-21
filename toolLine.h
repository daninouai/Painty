#ifndef TOOLLINE_H
#define TOOLLINE_H

#include "tools.h"
#include <GL/glut.h>
#include <GL/freeglut.h>

toolLine::toolLine(float x1, float y1, float x2, float y2, float r, float g, float b) {
    newX1 = x1;
    newY1 = y1;
    newX2 = x2;
    newY2 = y2;

    newR = r;
    newG = g;
    newB = b;
}

float toolLine::getX1() {
    return newX1;
}

float toolLine::getY1() {
    return newY1;
}

float toolLine::getX2() {
    return newX2;
}

float toolLine::getY2() {
    return newY2;
}

float toolLine::getR() {
    return newR;
}

float toolLine::getG() {
    return newG;
}

float toolLine::getB() {
    return newB;
}

void toolLine::setColor(float r, float g, float b) {
    newR = r;
    newG = g;
    newB = b;
}

void toolLine::createLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);

    glVertex3f(x1, y1, 0.0);
    glVertex3f(x2, y2, 0.0);

    glEnd();
}

#endif // TOOLLINE_H
