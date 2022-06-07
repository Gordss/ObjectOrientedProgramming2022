#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
    double mWidth;
    double mHeight;

public:
    Rectangle(double width = 0, double height = 0);

    void setWidth(const double& w);
    void setHeight(const double& h);

    double getWidth() const;
    double getHeight() const;

    void accept(Visitor* v) override;
    double surface() const override;
};

#endif