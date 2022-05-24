#ifndef __LAKE_CPP
#define __LAKE_CPP

#include "Lake.h"
#include "PlasticDuck.h"
#include "RealDuck.h"
#include "RubberDuck.h"
#include <string>
#include <iostream>

Lake::Lake() : mName(""), mDucks(std::vector<Duck*>()) {
}

Lake::Lake(const std::string& _name) : mDucks(std::vector<Duck*>()) {
	this->mName = _name;
}

Lake::Lake(const std::string& _a, const std::vector<Duck*>& _d) {
	this->mName = _a;
	this->mDucks = _d;
}

Lake& Lake::addDuck(const Duck* duck) {
	this->mDucks.push_back(duck->clone());
	return *this;
}

void Lake::print() const {
	std::cout << "-----------LAKE-----------\n"
			  << "Name : "
			  << this->mName
			  << '\n'
			  << "-----------DUCKS----------\n";

	for (Duck* duck : this->mDucks) {
		duck->print();
	}
	std::cout << "-------------------------\n";
}

std::istream& Lake::read(std::istream& in) {
	getline(in, this->mName);
	int size;
	char ducktype;
	PlasticDuck plastic;
	RealDuck real;
	RubberDuck rubber;
	in >> size;
	for (int i = 0; i < size; i++)
	{
		in >> ducktype;
		switch (ducktype)
		{
			case 'P':  plastic.read(in);
					   this->mDucks.push_back(plastic.clone()); break;
			case 'L':  real.read(in);
					   this->mDucks.push_back(real.clone()); break;
			case 'R':  rubber.read(in);
					   this->mDucks.push_back(rubber.clone()); break;
		}
	}
	return in;
}

std::ostream& Lake::write(std::ostream& out) const {
	out << this->mName
		<< '\n'
		<< this->mDucks.size()
		<< '\n';
	for (Duck* duck : this->mDucks) {
		duck->write(out);
	}
	return out;
}

std::istream& operator>>(std::istream& in, Lake& l) {
	l.read(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Lake& l) {
	l.write(out);
	return out;
}

#endif // !__LAKE_CPP
