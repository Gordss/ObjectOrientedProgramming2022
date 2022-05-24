#ifndef __PLASTIC_DUCK_H
#define __PLASTIC_DUCK_H

#include "Duck.h"

class PlasticDuck : public Duck
{
private:
	int mElementsNumber;

public:
	PlasticDuck();
	PlasticDuck(const int &, const double &, const std::string &, const int &);

	Duck *clone() const override;
	void print() const override;
	void quack() override;

	void setElementsNumber(const int);
	int getElementsNumber() const;

	std::istream &read(std::istream &) override;
	std::ostream &write(std::ostream &) const override;
};

#endif // !__PLASTIC_DUCK_H