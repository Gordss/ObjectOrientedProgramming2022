#ifndef __GROUP_CPP
#define __GROUP_CPP

#include <iostream>
#include "Visitor.h"
#include "Group.h"

void Group::erase()
{
	for (Shape *s : this->mChildren)
	{
		delete s;
	}

	mChildren.clear();
}

Group::Group(int x, int y, const char *text)
	: Shape(x, y, text)
{
}

Group::Group(const Group &other) : Shape(other)
{
	for (Shape *s : other.mChildren)
	{
		this->mChildren.push_back(s->clone());
	}
}

Group &Group::operator=(const Group &other)
{
	if (this != &other)
	{
		Shape::operator=(other);

		this->erase();

		for (Shape *s : other.mChildren)
		{
			this->mChildren.push_back(s->clone());
		}
	}

	return *this;
}

Shape *Group::clone() const
{
	return new Group(*this);
}

void Group::accept(Visitor *visitor)
{
	visitor->visitGroup(this);
}

void Group::addShape(Shape *shape)
{
	this->mChildren.push_back(shape->clone());
}

size_t Group::get_numberOfChildren() const
{
	return this->mChildren.size();
}

Shape *Group::getChild(size_t index) const
{
	if (index >= this->mChildren.size())
	{
		std::cout << "Wrong index!\n";
		return nullptr;
	}

	return this->mChildren[index];
}

Group::~Group()
{
	this->erase();
}

#endif