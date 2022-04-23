#include "shapecomposite.h"

Shapes::ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                                       Shapes::ShapeOperation operation) : shape1(shape1), shape2(shape2),
                                                                           operation(operation) {}

bool Shapes::ShapeComposite::isIn(int x, int y) const {
    switch (operation) {
        case ShapeOperation::INTERSECTION: {
            return shape1->isIn(x, y) and shape2->isIn(x, y);
        }
        case ShapeOperation::SUM: {
            return shape1->isIn(x, y) or shape2->isIn(x, y);
        }
        case ShapeOperation::DIFFERENCE: {
            return shape1->isIn(x, y) and !shape2->isIn(x, y);
        }
        default:
            return true;
    }
}