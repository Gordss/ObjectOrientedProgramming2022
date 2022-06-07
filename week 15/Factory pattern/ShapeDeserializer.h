#ifndef __SHAPE_DESERIALIZER_H
#define __SHAPE_DESERIALIZER_H

#include "Visitor.h"
#include <iostream>

class ShapeDeserializer : public Visitor
{
private:
    std::istream &mIn;

public:
    ShapeDeserializer(std::istream &in);
    virtual void visit(Rectangle *rectangle) override;
    virtual void visit(Circle *circle) override;
    virtual void visit(Square *group) override;
};

#endif