#ifndef TOOLSELECTION_H
#define TOOLSELECTION_H

#include "tools.h"
#include <GL/glut.h>
#include <GL/freeglut.h>

toolSelection::toolSelection() {}

toolSelection::toolSelection(float x, float y) {
    newX = x;
    newY = y;
}


void toolSelection::getSelectionPosition(vector<toolSelection> &pSelect) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for (unsigned int i = 0; i < pSelect.size(); i++) {

        glVertex3f(pSelect[i].getX(), pSelect[i].getY(), 0.0);
    }
    glEnd();

}

float toolSelection::getX() {
    return newX;
}

float toolSelection::getY() {
    return newY;
}


#endif // TOOLSELECTION_H
