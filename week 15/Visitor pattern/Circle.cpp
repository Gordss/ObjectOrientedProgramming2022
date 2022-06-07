#ifndef __CIRCLE_CPP
#define __CIRCLE_CPP

#include "Visitor.h"
#include "Circle.h"

Circle::Circle(
	int x,
	int y,
	int radius,
	const char *text)
	: Shape(x, y, text),
	  mRadius(radius)
{
}

Shape *Circle::clone() const
{
	return new Circle(*this);
}

void Circle::accept(Visitor *visitor)
{
	visitor->visitCircle(this);
}

void Circle::setRadius(int radius)
{
	this->mRadius = radius;
}

int Circle::getRadius() const
{
	return this->mRadius;
}

#endif