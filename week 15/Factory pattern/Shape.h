#ifndef __FIGURE_H
#define __FIGURE_H

#include <fstream>
#include <cstring>

class Visitor;

class Shape
{
private:
	std::string mType;

public:
	Shape(const std::string& type);
	virtual ~Shape();

	virtual void accept(Visitor *v) = 0;
	virtual double surface() const = 0;

	void setType(const std::string& type);
	std::string getType() const;
};

#endif