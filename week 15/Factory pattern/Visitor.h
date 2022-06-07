#ifndef __VISITOR_H
#define __VISITOR_H

#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

class Visitor {
public:
	virtual void visit(Rectangle* rectangle) = 0;
	virtual void visit(Circle* circle) = 0;
	virtual void visit(Square* square) = 0;
};

#endif