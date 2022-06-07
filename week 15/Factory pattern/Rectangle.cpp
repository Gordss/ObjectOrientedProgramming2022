#ifndef __RECTANGLE_CPP
#define __RECTANGLE_CPP

#include "Rectangle.h"
#include "Visitor.h"

Rectangle::Rectangle(double width, double height)
    : Shape("rectangle"), mWidth(width),
      mHeight(height)
{
}

void Rectangle::setWidth(const double& w)
{
    this->mWidth = w;
}

void Rectangle::setHeight(const double& h)
{
    this->mHeight = h;
}

double Rectangle::getWidth() const
{
    return this->mWidth;
}

double Rectangle::getHeight() const
{
    return this->mHeight;
}

void Rectangle::accept(Visitor *v)
{
    v->visit(this);
}

double Rectangle::surface() const
{
    return this->mHeight * this->mWidth;
}

#endif