#ifndef __REAL_DUCK_CPP
#define __REAL_DUCK_CPP

#include "RealDuck.h"
#include <iostream>
#include <string>

RealDuck::RealDuck() : Duck(), mName(""), mAge(0)
{
}

RealDuck::RealDuck(const int &_h, const double &_w, const std::string &_c, const std::string &_n, const int &_a) : Duck(_h, _w, _c), mName(_n), mAge(_a)
{
}

Duck *RealDuck::clone() const
{
	return new RealDuck(*this);
}

void RealDuck::print() const
{
	std::cout << "==========Real Duck==========\n"
			  << "Name: "
			  << this->mName
			  << '\n'
			  << "Age: "
			  << this->mAge
			  << '\n'
			  << "Height: "
			  << this->getHeight()
			  << '\n'
			  << "Weight: "
			  << this->getWeight()
			  << '\n'
			  << "Color: "
			  << this->getColor()
			  << '\n'
			  << "=============================\n";
}

void RealDuck::setName(const std::string &_n)
{
	this->mName = _n;
}

void RealDuck::setAge(const int _a)
{
	this->mAge = _a;
}

std::string RealDuck::getName() const
{
	return this->mName;
}

int RealDuck::getAge() const
{
	return this->mAge;
}

void RealDuck::quack()
{
	std::cout << "Quack! I'm " << this->mName << " and I'm " << this->mAge << " years old!\n";
}

std::istream &RealDuck::read(std::istream &in)
{
	Duck::read(in);
	getline(in, this->mName);
	in >> this->mAge;
	return in;
}

std::ostream &RealDuck::write(std::ostream &out) const
{
	out << "L\n";
	Duck::write(out);
	out << this->mName
		<< '\n'
		<< this->mAge
		<< '\n';
	return out;
}

#endif // !__REAL_DUCK_CPP
