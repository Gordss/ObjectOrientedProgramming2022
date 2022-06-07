#ifndef __SHAPE_CPP
#define __SHAPE_CPP

#include "Shape.h"
#include <cstring>

char *copyDynamic(const char *source)
{
    char *result = new char[strlen(source) + 1];
    strcpy(result, source);
    return result;
}

Shape::Shape() : mX(0), mY(0), mText(nullptr)
{
}

Shape::Shape(int x, int y, const char *text) : mX(x), mY(y)
{
    this->mText = copyDynamic(text);
}

Shape::Shape(const Shape &other)
{
    this->mX = other.mX;
    this->mY = other.mY;
    this->mText = copyDynamic(other.mText);
}

Shape &Shape::operator=(const Shape &other)
{
    if (this != &other)
    {
        delete[] this->mText;
        this->mX = other.mX;
        this->mY = other.mY;
        this->mText = copyDynamic(other.mText);
    }
    return *this;
}

void Shape::setX(int x)
{
    this->mX = x;
}

void Shape::setY(int y)
{
    this->mY = y;
}

void Shape::setText(const char *text)
{
    this->mText = copyDynamic(text);
}

int Shape::getX() const
{
    return this->mX;
}

int Shape::getY() const
{
    return this->mY;
}

char *Shape::getText() const
{
    return this->mText;
}

Shape::~Shape()
{
    delete[] this->mText;
}

#endif