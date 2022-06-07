#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
	double mRadius;
public:
	Circle(double radius = 0);

	void setRadius(const double& r);
	double getRadius() const;

	void accept(Visitor *v) override;
	double surface() const override;
};

#endif