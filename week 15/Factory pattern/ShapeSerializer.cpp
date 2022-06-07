#include "ShapeSerializer.h"

ShapeSerializer::ShapeSerializer(std::ostream &out) : mOut(out)
{
}

void ShapeSerializer::visit(Circle *c)
{
    mOut << c->getType() << '\n'
         << c->getRadius() << '\n';
}

void ShapeSerializer::visit(Rectangle *r)
{
    mOut << r->getType() << '\n'
         << r->getWidth() << '\n'
         << r->getHeight() << '\n';
}

void ShapeSerializer::visit(Square *s)
{
    mOut << s->getType() << '\n'
         << s->getSide() << '\n';
}