#ifndef __RECTANGLE_CPP
#define __RECTANGLE_CPP

#include "Visitor.h"
#include "Rectangle.h"

Rectangle::Rectangle(
	int x,
	int y,
	int width,
	int height,
	const char *text)
	: Shape(x, y, text),
	  mWidth(width),
	  mHeight(height)
{
}

Shape *Rectangle::clone() const
{
	return new Rectangle(*this);
}

void Rectangle::accept(Visitor *visitor)
{
	visitor->visitRectangle(this);
}

void Rectangle::setWidth(int width)
{
	this->mWidth = width;
}

void Rectangle::setHeight(int height)
{
	this->mHeight = height;
}

int Rectangle::getWidth() const
{
	return this->mWidth;
}

int Rectangle::getHeight() const
{
	return this->mHeight;
}

#endif