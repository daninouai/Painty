#ifndef TOOLS_H
#define TOOLS_H

#include <string.h>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Result {
    double distance;
    Point center;
};

class toolCircle {
public:
    toolCircle();

    toolCircle(float x1, float y1, float x2, float y2, float r, float g, float b);

    ~toolCircle();

    int getX1();

    int getY1();

    int getX2();

    int getY2();

    Result calculateCircle(const Point &point1, const Point &point2);

    void creatCircle(float x, float y, float r);

    float getR();

    float getG();

    float getB();

    void setColor(float, float, float);

private:
    int newX1;
    int newY1;
    int newX2;
    int newY2;

    float newR;
    float newG;
    float newB;
};

class toolSquare {
public:
    toolSquare();

    toolSquare(float p1, float p2, float p3, float p4, float r, float g, float b);

    ~toolSquare();

    float getP1();

    float getP2();

    float getP3();

    float getP4();

    float getR();

    float getG();

    float getB();

    void setColor(float, float, float);

    void createSquare(Point point1, Point point2);

private:
    float newP1;
    float newP2;
    float newP3;
    float newP4;

    float newR;
    float newG;
    float newB;
};

class toolLine {
public:
    toolLine();

    toolLine(float x1, float y1, float x2, float y2, float r, float g, float b);

    float getX1();

    float getY1();

    float getX2();

    float getY2();

    void createLine(float x1, float y1, float x2, float y2);

    float getR();

    float getG();

    float getB();

    void setColor(float, float, float);

private:
    float newX1;
    float newY1;
    float newX2;
    float newY2;

    float newR;
    float newG;
    float newB;
};

class toolText {
public:
    toolText();

    toolText(float x, float y, float r, float g, float b, string txt);

    ~toolText();

    void writeBitmapString(void *font, const std::string &str);

    void createText(float posX, float posY, const std::string &txt);

    float getX();

    float getY();

    float getR();

    float getG();

    float getB();

    void setColor(float, float, float);

    string getText();

private:
    float newX;
    float newY;


    string text;
    float newR;
    float newG;
    float newB;
};

#endif // TOOLS_H
