#ifndef __DUCK_CPP
#define __DUCK_CPP

#include "Duck.h"
#include <string>
#include <iostream>

Duck::Duck() : mHeight(0), mWeight(0), mColor("")
{
}

Duck::Duck(const int &_h, const double &_w, const std::string &_color) : mHeight(_h), mWeight(_w), mColor(_color)
{
}

void Duck::print() const
{
	std::cout << "==========Duck==========\n"
			  << "Height: "
			  << this->mHeight
			  << '\n'
			  << "Weight: "
			  << this->mWeight
			  << '\n'
			  << "Color: "
			  << this->mColor
			  << '\n'
			  << "========================\n";
}

void Duck::setHeight(const int &_h)
{
	this->mHeight = _h;
}

void Duck::setWeight(const double &_w)
{
	this->mWeight = _w;
}

void Duck::setColor(const std::string &_c)
{
	this->mColor = _c;
}

int Duck::getHeight() const
{
	return this->mHeight;
}

double Duck::getWeight() const
{
	return this->mWeight;
}

std::string Duck::getColor() const
{
	return this->mColor;
}

std::istream &Duck::read(std::istream &in)
{
	in >> this->mHeight >> this->mWeight;
	in.ignore(1, '\n');
	getline(in, mColor);
	return in;
}

std::ostream &Duck::write(std::ostream &out) const
{
	out << this->mHeight
		<< '\n'
		<< this->mWeight
		<< '\n'
		<< this->mColor
		<< '\n';
	return out;
}

std::istream &operator>>(std::istream &in, Duck &d)
{
	d.read(in);
	return in;
}

std::ostream &operator<<(std::ostream &out, const Duck &d)
{
	d.write(out);
	return out;
}

#endif // !__DUCK_CPP