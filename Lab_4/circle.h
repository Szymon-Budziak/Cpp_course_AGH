#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

namespace Shapes {
    class Circle : public Shapes::Shape {
    private:
        int x_center, y_center, radius;
    public:
        Circle(int xCenter, int yCenter, int radius) noexcept;

        [[nodiscard]] bool isIn(int x, int y) const override;

        [[nodiscard]] int x() const;

        [[nodiscard]] int y() const;

        [[nodiscard]] int getRadius() const;
    };
}
#endif // CIRCLE_H