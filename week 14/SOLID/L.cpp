/*

Liskov Substitution Principle

parent classes should be easily substituted
with their child classes without blowing up the application

*/

#include <utility>
// don't
class Rectangle
{
	double mHeight;
	double mWidth;

public:
	void setHeigth(double heigth)
	{
		mHeight = heigth;
	}
	void setWidth(double width)
	{
		mWidth = width;
	}
};

class Square : public Rectangle
{
};

// do
class Rectangle
{
	double mHeight;
	double mWidth;

public:
	void setHeigth(double heigth)
	{
		mHeight = heigth;
	}
	void setWidth(double width)
	{
		mWidth = width;
	}
};

class Square
{
	double mSide;

public:
	void setSide(double side)
	{
		mSide = side;
	}
};