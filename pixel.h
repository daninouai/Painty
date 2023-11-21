#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    Pixel();
    Pixel(int, int, float, float, float);
    ~Pixel();

    int getX();
    int getY();
    float getR();
    float getG();
    float getB();

    void setPosition(int, int);
    void setColor(float, float, float);

private:
    int newX;
    int newY;
    float newR;
    float newG;
    float newB;
};

#endif // PIXEL_H
