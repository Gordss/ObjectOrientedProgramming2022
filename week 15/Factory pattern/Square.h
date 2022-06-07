#ifndef __SQUARE_H
#define __SQUARE_H

#include "Shape.h"

class Square : public Shape
{
private:
	double mSide;

public:
	Square(double side = 0);

	void setSide(const double& side);
	double getSide() const;

	void accept(Visitor *v) override;
	double surface() const override;
};

#endif