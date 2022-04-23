#include "circle.h"

Shapes::Circle::Circle(int xCenter, int yCenter, int radius) noexcept:
        x_center(xCenter), y_center(yCenter), radius(radius) {}

bool Shapes::Circle::isIn(int x, int y) const {
    if (pow(x - x_center, 2) + pow(y - y_center, 2) <= pow(radius, 2))
        return true;
    return false;
}

int Shapes::Circle::x() const {
    return x_center;
}

int Shapes::Circle::y() const {
    return y_center;
}

int Shapes::Circle::getRadius() const {
    return radius;
}