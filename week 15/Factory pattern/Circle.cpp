#ifndef __CIRCLE_CPP
#define __CIRCLE_CPP

#include "Visitor.h"
#include "Circle.h"

Circle::Circle(double radius) : Shape("circle"), mRadius(radius)
{
}

void Circle::setRadius(const double &r)
{
    this->mRadius = r;
}

double Circle::getRadius() const
{
    return this->mRadius;
}

void Circle::accept(Visitor *v)
{
    v->visit(this);
}

double Circle::surface() const
{
    return this->mRadius * this->mRadius * 3.14;
}

#endif