#include "ShapeDeserializer.h"

ShapeDeserializer::ShapeDeserializer(std::istream &in) : mIn(in)
{
}

void ShapeDeserializer::visit(Circle *c)
{
    double r;
    mIn >> r;
    c->setRadius(r);
}

void ShapeDeserializer::visit(Rectangle *r)
{
    double w, h;
    mIn >> w >> h;
    r->setWidth(w);
    r->setHeight(h);
}

void ShapeDeserializer::visit(Square *s)
{
    double side;
    mIn >> side;
    s->setSide(side);
}