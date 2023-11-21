#ifndef TOOLTEXT_H
#define TOOLTEXT_H

#include "tools.h"
#include <GL/glut.h>
#include <iostream>

toolText::toolText(float x, float y, float r, float g, float b, string txt) {
    newX = x;
    newY = y;

    newR = r;
    newG = g;
    newB = b;

    text = txt;
}

toolText::~toolText() {}

float toolText::getX() {
    return newX;
}

float toolText::getY() {
    return newY;
}

float toolText::getR() {
    return newR;
}

float toolText::getG() {
    return newG;
}

float toolText::getB() {
    return newB;
}


string toolText::getText() {
    return text;
}

void toolText::setColor(float r, float g, float b) {
    newR = r;
    newG = g;
    newB = b;
}

void toolText::writeBitmapString(void *font, const std::string &str) {
    for (char c: str) {
        glutBitmapCharacter(font, c);
    }
}

void toolText::createText(float posX, float posY, const std::string &txt) {
    glRasterPos3f(posX, posY, 0.0);
    static long font = (long) GLUT_BITMAP_8_BY_13; // Font selection.
    writeBitmapString((void *) font, txt);
}

#endif // TOOLTEXT_H
