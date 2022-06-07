#ifndef __VISITOR_H
#define __VISITOR_H

#include "Rectangle.h"
#include "Circle.h"
#include "Group.h"

class Visitor {
public:
	virtual void visitRectangle(Rectangle* rectangle) = 0;
	virtual void visitCircle(Circle* circle) = 0;
	virtual void visitGroup(Group* group) = 0;
};

#endif