#ifndef __SQUARE_CPP
#define __SQUARE_CPP

#include "Square.h"
#include "Visitor.h"

Square::Square(double side)
	: Shape("square"), mSide(side)
{
}

void Square::setSide(const double& side)
{
	this->mSide = side;
}

double Square::getSide() const
{
	return this->mSide;
}

void Square::accept(Visitor *v)
{
	v->visit(this);
}

double Square::surface() const
{
	return this->mSide * this->mSide;
}

#endif