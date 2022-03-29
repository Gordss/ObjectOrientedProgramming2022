#include "Point.h"

void Point::write(std::ostream& out) const
{
    out << '(' << this->mX << ", " << this->mY << ")";
}