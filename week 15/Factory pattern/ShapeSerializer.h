#ifndef __SHAPE_SERIALIZER_H
#define __SHAPE_SERIALIZER_H

#include "Visitor.h"
#include <iostream>

class ShapeSerializer : public Visitor
{
private:
    std::ostream& mOut;

public:
    ShapeSerializer(std::ostream& out);

    virtual void visit(Rectangle* rectangle) override;
	virtual void visit(Circle* circle) override;
	virtual void visit(Square* group) override;
};

#endif