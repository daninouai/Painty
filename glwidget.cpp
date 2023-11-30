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
#include "toolSelection.h"
#include <string.h>
#include <QString>

#include <fstream>
#include <nlohmann/json.hpp>


#include <QInputDialog>
#include <QDebug>


#include <thread>
#include <chrono>

using namespace std;


float red = 1.0, green = 0.0, blue = 0.0;
bool isPen = true;
bool isCircle = false;
bool isSquare = false;
bool isLine = false;
bool isEraser = false;
bool isSpray = false;
bool isText = false;
bool isSelection = false;
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
std::vector<toolSelection> pSelect;

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    this->setMouseTracking(true);
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

void GLWidget::Selection(float x, float y) {
    toolSelection newSelect(x, y);
    pSelect.push_back(newSelect);

    newSelect.getSelectionPosition(pSelect);
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
    glClear(GL_COLOR_BUFFER_BIT);

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


    glColor3f(previewSquare.getR(), previewSquare.getG(), previewSquare.getB());
    Point pos1;
    pos1.x = previewSquare.getP1();
    pos1.y = previewSquare.getP2();
    Point pos2;
    pos2.x = previewSquare.getP3();
    pos2.y = previewSquare.getP4();

    previewSquare.createSquare(pos1, pos2);


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


    for (unsigned int i = 0; i < pSelect.size(); i++) {
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(pSelect[i].getX(), pSelect[i].getY(), 0.0);
        glEnd();
    }


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

toolSquare::toolSquare() {

}


void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    QPoint clickPos = event->pos();

    if (event->buttons() & Qt::LeftButton) {
        if (isPen == true || isEraser == true || isSpray == true) {
            drawPoint(clickPos.x(), clickPos.y());
        }

        if (isSelection) {
            X1 = clickPos.x();
            Y1 = 550 - clickPos.y();

            Selection(X1, Y1);
        }
    } else {
        if (event->buttons() == Qt::NoButton) {
            if (isSquare == true and X1 != 0 and X2 == 0) {
                X2 = clickPos.x();
                Y2 = 550 - clickPos.y();

                drawSquare(X1, Y1, X2, Y2);

                if (!square.empty()) {
                    square.erase(square.end() - 1);
                    update();
                }

                previewSquare = toolSquare(X1, Y1, X2, Y2, red, green, blue);
                update();

                X2 = 0;
                Y2 = 0;
            }
        }
    }

}


void GLWidget::changeColor(float r, float g, float b) {
    red = r;
    green = g;
    blue = b;
}

void GLWidget::chanageMode(bool pen = false, bool circle = false, bool square = false, bool line = false,
                           bool eraser = false, bool spray = false, bool text = false, bool selection = false) {
    if (pen == true) {
        isPen = true;
        isCircle = false;
        isSquare = false;
        isLine = false;
        isSpray = false;
        isEraser = false;
        isText = false;
        isSelection = false;
    } else if (circle == true) {
        isCircle = true;
        isPen = false;
        isSquare = false;
        isLine = false;
        isSpray = false;
        isEraser = false;
        isText = false;
        isSelection = false;
    } else if (square == true) {
        isSquare = true;
        isCircle = false;
        isPen = false;
        isLine = false;
        isSpray = false;
        isEraser = false;
        isText = false;
        isSelection = false;
    } else if (line == true) {
        isLine = true;
        isSquare = false;
        isCircle = false;
        isPen = false;
        isSpray = false;
        isEraser = false;
        isText = false;
        isSelection = false;
    } else if (eraser == true) {
        isEraser = true;
        isLine = false;
        isSquare = false;
        isCircle = false;
        isPen = false;
        isSpray = false;
        isText = false;
        isSelection = false;
    } else if (spray == true) {
        isSpray = true;
        isEraser = false;
        isLine = false;
        isSquare = false;
        isCircle = false;
        isPen = false;
        isText = false;
        isSelection = false;
    } else if (text == true) {
        isText = true;
        isSpray = false;
        isEraser = false;
        isLine = false;
        isSquare = false;
        isCircle = false;
        isPen = false;
        isSelection = false;
    } else if (selection == true) {
        isSelection = true;
        isText = false;
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

using json = nlohmann::json;

void GLWidget::SaveExportFile(const std::string &filename) {
    json jsonData;


    for (unsigned int i = 0; i < circle.size(); i++) {
        json circleData;
        circleData["type"] = "circle";
        circleData["getX1"] = circle[i].getX1();
        circleData["getY1"] = circle[i].getY1();
        circleData["getX2"] = circle[i].getX2();
        circleData["getY2"] = circle[i].getY2();

        circleData["r"] = circle[i].getR();
        circleData["g"] = circle[i].getG();
        circleData["b"] = circle[i].getB();

        jsonData.push_back(circleData);
    }

    for (unsigned int i = 0; i < square.size(); i++) {
        json squareData;
        squareData["type"] = "square";
        squareData["getP1"] = square[i].getP1();
        squareData["getP2"] = square[i].getP2();
        squareData["getP3"] = square[i].getP3();
        squareData["getP4"] = square[i].getP4();

        squareData["r"] = square[i].getR();
        squareData["g"] = square[i].getG();
        squareData["b"] = square[i].getB();

        jsonData.push_back(squareData);
    }

    for (unsigned int i = 0; i < line.size(); i++) {
        json lineData;
        lineData["type"] = "line";
        lineData["getX1"] = line[i].getX1();
        lineData["getY1"] = line[i].getY1();
        lineData["getX2"] = line[i].getX2();
        lineData["getY2"] = line[i].getY2();
        lineData["r"] = line[i].getR();
        lineData["g"] = line[i].getG();
        lineData["b"] = line[i].getB();

        jsonData.push_back(lineData);
    }

    for (unsigned int i = 0; i < text.size(); i++) {
        json textData;
        textData["type"] = "text";
        textData["getX"] = text[i].getX();
        textData["getY"] = text[i].getY();
        textData["getText"] = text[i].getText();

        textData["r"] = text[i].getR();
        textData["g"] = text[i].getG();
        textData["b"] = text[i].getB();

        jsonData.push_back(textData);
    }

    for (unsigned int i = 0; i < spray.size(); i++) {
        json sprayData;
        sprayData["type"] = "spray";
        sprayData["getX"] = spray[i].getX();
        sprayData["getY"] = spray[i].getY();

        sprayData["r"] = spray[i].getR();
        sprayData["g"] = spray[i].getG();
        sprayData["b"] = spray[i].getB();

        jsonData.push_back(sprayData);
    }

    for (unsigned int i = 0; i < pixel.size(); i++) {
        json pixelData;
        pixelData["type"] = "pixel";
        pixelData["x"] = pixel[i].getX();
        pixelData["y"] = pixel[i].getY();
        pixelData["r"] = pixel[i].getR();
        pixelData["g"] = pixel[i].getG();
        pixelData["b"] = pixel[i].getB();

        jsonData.push_back(pixelData);
    }

    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open the file for writing." << std::endl;
        return;
    }

    outputFile << std::setw(4) << jsonData;

    outputFile.close();
}


void GLWidget::ImportFile(const std::string &filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file: " << filename << std::endl;
        return;
    }

    json jsonData;
    inputFile >> jsonData;


    for (unsigned long int i = 0; i < jsonData.size(); i++) {

        if (jsonData[i]["type"] == "circle") {
            toolCircle newCircle(jsonData[i]["getX1"], jsonData[i]["getY1"], jsonData[i]["getX2"], jsonData[i]["getY2"],
                                 jsonData[i]["r"], jsonData[i]["g"], jsonData[i]["b"]);
            circle.push_back(newCircle);
        }

        if (jsonData[i]["type"] == "square") {
            toolSquare newSquare(jsonData[i]["getP1"], jsonData[i]["getP2"], jsonData[i]["getP3"], jsonData[i]["getP4"],
                                 jsonData[i]["r"], jsonData[i]["g"], jsonData[i]["b"]);
            square.push_back(newSquare);
        }

        if (jsonData[i]["type"] == "line") {
            toolLine newLine(jsonData[i]["getX1"], jsonData[i]["getY1"], jsonData[i]["getX2"], jsonData[i]["getY2"],
                             jsonData[i]["r"], jsonData[i]["g"], jsonData[i]["b"]);
            line.push_back(newLine);
        }

        if (jsonData[i]["type"] == "pixel" || "spray") {
            if (jsonData[i]["type"] == "pixel") {
                Pixel newDot(jsonData[i]["x"], jsonData[i]["y"], jsonData[i]["r"], jsonData[i]["g"], jsonData[i]["b"]);
                pixel.push_back(newDot);
            } else if (jsonData[i]["type"] == "spray") {
                Pixel sprayDot(jsonData[i]["getX"], jsonData[i]["getY"], jsonData[i]["r"], jsonData[i]["g"],
                               jsonData[i]["b"]);
                spray.push_back(sprayDot);
            }
        }


        if (jsonData[i]["type"] == "text") {
            toolText newText(jsonData[i]["getX"], jsonData[i]["getY"], jsonData[i]["r"], jsonData[i]["g"],
                             jsonData[i]["b"], jsonData[i]["getText"]);
            text.push_back(newText);
        }


    }


    inputFile.close();
}
