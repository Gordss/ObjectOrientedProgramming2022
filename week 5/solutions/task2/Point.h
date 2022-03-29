#ifndef _POINT_H
#define _POINT_H

#include <iostream>

struct Point
{
	double mX;
	double mY;

	void write(std::ostream& out) const;
};

#endif