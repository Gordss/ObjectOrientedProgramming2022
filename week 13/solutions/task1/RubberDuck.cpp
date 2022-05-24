#ifndef __RUBBER_DUCK_CPP
#define __RUBBER_DUCK_CPP

#include "RubberDuck.h"
#include <iostream>

RubberDuck::RubberDuck() : Duck(), mFlexibility(0), mCanDebug(false)
{
}

RubberDuck::RubberDuck(const int &_h, const double &_w, const std::string &_c, const int &_f, const bool &_d) : Duck(_h, _w, _c)
{
	this->mFlexibility = _f;
	this->mCanDebug = _d;
}

Duck *RubberDuck::clone() const
{
	return new RubberDuck(*this);
}

void RubberDuck::print() const
{
	std::cout << "==========Rubber Duck==========\n"
			  << "Height: "
			  << this->getHeight()
			  << '\n'
			  << "Weight: "
			  << this->getWeight()
			  << '\n'
			  << "Color: "
			  << this->getColor()
			  << '\n'
			  << "Flexibility: "
			  << this->mFlexibility
			  << '\n'
			  << "Debugging skills: "
			  << std::boolalpha
			  << this->mCanDebug
			  << '\n'
			  << "===============================\n";
}

void RubberDuck::setFlexibility(const int _f)
{
	this->mFlexibility = _f;
}

void RubberDuck::setCanDebug(const bool _d)
{
	this->mCanDebug = _d;
}

int RubberDuck::getFlexibility() const
{
	return this->mFlexibility;
}

bool RubberDuck::getCanDebug() const
{
	return this->mCanDebug;
}
void RubberDuck::quack()
{
	if (this->mCanDebug)
	{
		std::cout << "Quack! I'm a mighty rubber duck!\n";
	}
	else
	{
		std::cout << "Quack! Herp a derp, I'm a rubber duck!\n";
	}
}
std::istream &RubberDuck::read(std::istream &in)
{
	Duck::read(in);
	in >> this->mFlexibility;
	in >> this->mCanDebug;
	return in;
}
std::ostream &RubberDuck::write(std::ostream &out) const
{
	out << "R\n";
	Duck::write(out);
	out << this->mFlexibility
		<< '\n'
		<< this->mCanDebug
		<< '\n';
	return out;
}

#endif // !__RUBBER_DUCK_CPP
