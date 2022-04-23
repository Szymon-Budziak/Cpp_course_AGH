#include "rectangle.h"

Shapes::Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) noexcept:
        xFrom_(xFrom), yFrom_(yFrom), xTo_(xTo), yTo_(yTo) {}

bool Shapes::Rectangle::isIn(int x, int y) const {
    if (x >= xFrom_ && x <= xTo_ && y >= yFrom_ && y <= yTo_)
        return true;
    return false;
}

int Shapes::Rectangle::x() const {
    return xFrom_;
}

int Shapes::Rectangle::xTo() const {
    return xTo_;
}

int Shapes::Rectangle::y() const {
    return yFrom_;
}

int Shapes::Rectangle::yTo() const {
    return yTo_;
}