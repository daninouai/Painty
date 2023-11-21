#include "pixel.h"

Pixel::Pixel() {}

Pixel::Pixel(int x, int y, float r, float g, float b) {
    newX = x;
    newY = y;
    newR = r;
    newG = g;
    newB = b;
}

Pixel::~Pixel() {}

int Pixel::getX() {
    return newX;
}

int Pixel::getY() {
    return newY;
}

float Pixel::getR() {
    return newR;
}

float Pixel::getG() {
    return newG;
}

float Pixel::getB() {
    return newB;
}

void Pixel::setPosition(int x, int y) {
    newX = x;
    newY = y;
}

void Pixel::setColor(float r, float g, float b) {
    newR = r;
    newG = g;
    newB = b;
}
