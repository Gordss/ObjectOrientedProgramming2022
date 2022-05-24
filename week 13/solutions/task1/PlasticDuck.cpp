#ifndef __PLASTIC_DUCK_CPP
#define __PLASTIC_DUCK_CPP

#include "PlasticDuck.h"
#include <iostream>

PlasticDuck::PlasticDuck() : Duck(), mElementsNumber(0)
{
}

PlasticDuck::PlasticDuck(const int &_h, const double &_w, const std::string &_c, const int &_n) : Duck(_h, _w, _c), mElementsNumber(_n)
{
}

Duck *PlasticDuck::clone() const
{
	return new PlasticDuck(*this);
}

void PlasticDuck::print() const
{
	std::cout << "==========Plastic Duck==========\n"
			  << "Height: "
			  << this->getHeight()
			  << '\n'
			  << "Weight: "
			  << this->getWeight()
			  << '\n'
			  << "Color: "
			  << this->getColor()
			  << '\n'
			  << "Parts: "
			  << this->mElementsNumber
			  << '\n'
			  << "===============================\n";
}

void PlasticDuck::setElementsNumber(const int _n)
{
	this->mElementsNumber = _n;
}
int PlasticDuck::getElementsNumber() const
{
	return this->mElementsNumber;
}

void PlasticDuck::quack()
{
	std::cout << "Quack! I'm a plastic duck with " << this->mElementsNumber << " parts!\n";
}

std::istream &PlasticDuck::read(std::istream &in)
{
	Duck::read(in);
	in >> this->mElementsNumber;
	return in;
}

std::ostream &PlasticDuck::write(std::ostream &out) const
{
	out << "P\n";
	Duck::write(out);
	out << this->mElementsNumber
		<< '\n';
	return out;
}

#endif // !__PLASTIC_DUCK_CPP
