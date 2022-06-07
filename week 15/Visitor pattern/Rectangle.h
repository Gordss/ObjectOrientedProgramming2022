#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
	int mWidth;
	int mHeight;

public:
	Rectangle(int x, int y, int width, int height, const char *text);
	Shape *clone() const override;

	void accept(Visitor *visitor) override;

	void setWidth(int width);
	void setHeight(int height);

	int getWidth() const;
	int getHeight() const;
};

#endif