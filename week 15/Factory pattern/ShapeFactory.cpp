#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

Shape *ShapeFactory::createShape(const std::string &shapeType)
{
    Shape* result = nullptr;
    if (shapeType == "circle")
	{
		result = new Circle();
	}
	if (shapeType == "rectangle")
	{
		result = new Rectangle();
	}
	if (shapeType == "square")
	{
		result = new Square();
	}

    if (result != nullptr)
    {
        result->setType(shapeType);
    }

	return result;
}