#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include <memory>
#include "shape.h"

namespace Shapes {
    enum class ShapeOperation {
        INTERSECTION,
        SUM,
        DIFFERENCE
    };

    class ShapeComposite : public Shape {
    private:
        std::shared_ptr<Shape> shape1, shape2;
        ShapeOperation operation;
    public:
        ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                       Shapes::ShapeOperation operation);

        [[nodiscard]] bool isIn(int x, int y) const override;
    };
}
#endif // SHAPECOMPOSITE_H