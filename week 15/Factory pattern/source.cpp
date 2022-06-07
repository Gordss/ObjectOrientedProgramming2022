#include <iostream>
#include <fstream>
#include <vector>

#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeFactory.h"
#include "ShapeSerializer.h"
#include "ShapeDeserializer.h"

std::ostream &operator<<(std::ostream &out, const std::vector<Shape *> &shapeContainer)
{
	ShapeSerializer serializer(out);

	out << shapeContainer.size() << '\n';
	for (Shape *shape : shapeContainer)
	{
		shape->accept(&serializer);
	}

	return out;
}

std::istream &operator>>(std::istream &in, std::vector<Shape *> &shapeContainer)
{
	shapeContainer.clear();
	ShapeDeserializer deserializer(in);

	size_t n;
	in >> n;

	for (size_t i = 0; i < n; ++i)
	{
		std::string shapeType;
		in >> shapeType;

		Shape *newShape = ShapeFactory::createShape(shapeType);
		if (newShape == nullptr)
		{

			std::cout << "Couldn't create new figure!\n";
			return in;
		}

		newShape->accept(&deserializer);
		shapeContainer.push_back(newShape);
	}

	return in;
}

void testCreateFile()
{
	std::vector<Shape *> shapeContainer;
	shapeContainer.push_back(new Circle(3));
	shapeContainer.push_back(new Rectangle(3, 4));
	shapeContainer.push_back(new Circle(4));
	shapeContainer.push_back(new Square(4));

	std::ofstream outdata("figures.data");

	if (outdata.is_open() == false)
	{
		std::cout << "Couldn't open file to write!\n";
		return;
	}

	outdata << shapeContainer;

	std::cout << "File created successfully!\n";

	outdata.close();

	for (Shape * s : shapeContainer)
	{
		delete s;
	}
}

void testLoadFile()
{
	std::vector<Shape *> shapeContainer;

	std::ifstream indata("figures.data");

	if (indata.is_open() == false)
	{
		std::cout << "Couldn't open file for reading!\n";
		return;
	}

	std::cout << "Reading data from file...\n";
	indata >> shapeContainer;
	indata.close();
	
	std::cout << "Success!!! Array values:\n";
	std::cout << shapeContainer;

	for (Shape * s : shapeContainer)
	{
		delete s;
	}
}

int main()
{
	testCreateFile();
	testLoadFile();

	return 0;
}