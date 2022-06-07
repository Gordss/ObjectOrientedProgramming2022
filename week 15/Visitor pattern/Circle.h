#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:
	int mRadius;

public:
	Circle(int x, int y, int r, const char *text);

	Shape *clone() const override;

	void accept(Visitor *visitor) override;

	void setRadius(int radius);

	int getRadius() const;
};

#endif