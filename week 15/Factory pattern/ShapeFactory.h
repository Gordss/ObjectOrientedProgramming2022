#ifndef __SHAPE_FACTORY_H
#define __SHAPE_FACTORY_H

#include "Shape.h"

class ShapeFactory
{
public:
    static Shape *createShape(const std::string &shapeType);
};

#endif