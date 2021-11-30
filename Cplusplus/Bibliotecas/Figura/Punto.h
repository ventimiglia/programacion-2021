#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
private:
    double x;
    double y;

public:
    Punto(double x, double y);

    double getX() { return x; };
    void setX(double x) { this->x = x; };
    double getY() { return y; };
    void setY(double y) { this->y = y; };

    double operator -(const Punto & otro) const;
};

#endif // PUNTO_H
