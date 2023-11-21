#ifndef TOOLCIRCLE_H
#define TOOLCIRCLE_H

#include "tools.h"
#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/freeglut.h>

using namespace std;

toolCircle::toolCircle(float x1, float y1, float x2, float y2, float r, float g, float b) {
    newX1 = x1;
    newY1 = y1;
    newX2 = x2;
    newY2 = y2;

    newR = r;
    newG = g;
    newB = b;
}


toolCircle::~toolCircle() {}

int toolCircle::getX1() {
    return newX1;
}

int toolCircle::getY1() {
    return newY1;
}

int toolCircle::getX2() {
    return newX2;
}

int toolCircle::getY2() {
    return newY2;
}

float toolCircle::getR() {
    return newR;
}

float toolCircle::getG() {
    return newG;
}

float toolCircle::getB() {
    return newB;
}

void toolCircle::setColor(float r, float g, float b) {
    newR = r;
    newG = g;
    newB = b;
}

Result toolCircle::calculateCircle(const Point &point1, const Point &point2) {
    Result result;

    result.distance = std::sqrt(std::pow(point2.x - point1.x, 2) + std::pow(point2.y - point1.y, 2));

    result.center.x = (point1.x + point2.x) / 2.0;
    result.center.y = (point1.y + point2.y) / 2.0;

    return result;
}


void toolCircle::creatCircle(float x, float y, float r) {

    double PI = 3.14159265358979324;
    float t = 0;
    static int numVertices = 50;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numVertices; ++i) {
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * PI / numVertices;
    }
    glEnd();
}


#endif // TOOLCIRCLE_H
