#ifndef _LINE_H
#define _LINE_H

#include "Point.h"
#define EPS 0.000001

class Line
{
private:
	Point mA;
	Point mB;

public:
	Line(const Point&, const Point&);

	Point getPoint(bool) const;

	bool isParallelWith(const Line& otherLine) const;
	bool contains(const Point& point) const;
	Point* intersection(const Line& otherLine) const;
	void write(std::ostream& out) const;
};

#endif