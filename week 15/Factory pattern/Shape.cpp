#ifndef __FIGURE_CPP
#define __FIGURE_CPP

#include "Shape.h"

Shape::Shape(const std::string &type) : mType(type)
{
}

Shape::~Shape()
{
}

void Shape::setType(const std::string &type)
{
	this->mType = type;
}

std::string Shape::getType() const
{
	return this->mType;
}

#endif