#include "Line.h"

#include <cmath>

Line::Line(const Point& a, const Point& b) : mA(a), mB(b)
{
}

Point Line::getPoint(bool isEnd) const
{
    if (isEnd) {
        return this->mB;
    }

    return this->mA;
}

bool Line::isParallelWith(const Line& otherLine) const
{
	double slope1 = (this->mB.mY - this->mA.mY) / (this->mB.mX - this->mA.mX);
	double slope2 = (otherLine.mB.mY - otherLine.mA.mY) / (otherLine.mB.mX - otherLine.mA.mX);
    
	return fabs(slope1 - slope2) < EPS;
}

bool Line::contains(const Point& point) const
{
	double coef_a = this->mB.mY - this->mA.mY,
		coef_b = this->mA.mX - this->mA.mY,
		coef_c = this->mB.mX * this->mA.mY -
		this->mA.mX * this->mB.mY;

	return fabs(coef_a * point.mX + coef_b * point.mY + coef_c) < EPS;
}

Point* Line::intersection(const Line& otherLine) const
{
	if(this->isParallelWith(otherLine))
	{
		return nullptr;
	}

    double first_a = this->mB.mY - this->mA.mY,
           first_b = this->mA.mX - this->mA.mY,
           first_c = this->mB.mX * this->mA.mY -
                     this->mA.mX * this->mB.mY,
           second_a = otherLine.mB.mY - otherLine.mA.mY,
           second_b = otherLine.mA.mX - otherLine.mA.mY,
           second_c = otherLine.mB.mX * otherLine.mA.mY -
                      otherLine.mA.mX * otherLine.mB.mY;
	
    Point* result = new Point();
	result->mX = - first_c / first_a -
                  (second_a * first_c -
                   first_a * second_c) /
                  (first_a * second_b -
                   second_a * first_b) *
                  (first_b / first_a);

    result->mY = (second_a * first_c - first_a * second_c) /
                 (first_a * second_b - second_a * first_b);

    return result;
}

void Line::write(std::ostream& out) const
{
    this->mA.write(out);

    out << ' ';

    this->mB.write(out);

    out << '\n';
}


