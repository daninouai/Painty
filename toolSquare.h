#ifndef TOOLSQUARE_H
#define TOOLSQUARE_H

#include "tools.h"
#include <GL/glut.h>
#include <iostream>


toolSquare::toolSquare(float p1, float p2, float p3, float p4, float r, float g, float b) {
    newP1 = p1;
    newP2 = p2;
    newP3 = p3;
    newP4 = p4;

    newR = r;
    newG = g;
    newB = b;
};

toolSquare::~toolSquare() {}

float toolSquare::getP1() {
    return newP1;
}

float toolSquare::getP2() {
    return newP2;
}

float toolSquare::getP3() {
    return newP3;
}

float toolSquare::getP4() {
    return newP4;
}

float toolSquare::getR() {
    return newR;
}

float toolSquare::getG() {
    return newG;
}

float toolSquare::getB() {
    return newB;
}

void toolSquare::setColor(float r, float g, float b) {
    newR = r;
    newG = g;
    newB = b;
}

void toolSquare::createSquare(Point point1, Point point2) {

    double centerX = (point1.x + point2.x) / 2.0;
    double centerY = (point1.y + point2.y) / 2.0;
    double width = abs(point2.x - point1.x);
    double height = abs(point2.y - point1.y);

    glBegin(GL_LINE_LOOP);
    glVertex3f(centerX - width / 2.0, centerY - height / 2.0, 0.0);
    glVertex3f(centerX + width / 2.0, centerY - height / 2.0, 0.0);
    glVertex3f(centerX + width / 2.0, centerY + height / 2.0, 0.0);
    glVertex3f(centerX - width / 2.0, centerY + height / 2.0, 0.0);
    glEnd();
}


#endif // TOOLSQUARE_H
