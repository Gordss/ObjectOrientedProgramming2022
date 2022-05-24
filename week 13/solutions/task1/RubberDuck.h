#ifndef __RUBBER_DUCK_H
#define __RUBBER_DUCK_H

#include "Duck.h"

class RubberDuck : public Duck
{
private:
	int mFlexibility;
	bool mCanDebug;

public:
	RubberDuck();
	RubberDuck(const int &, const double &, const std::string &, const int &, const bool &);

	Duck *clone() const override;
	void print() const override;
	void quack() override;

	void setFlexibility(const int);
	void setCanDebug(const bool);

	int getFlexibility() const;
	bool getCanDebug() const;

	std::istream &read(std::istream &) override;
	std::ostream &write(std::ostream &) const override;
};

#endif // !__RUBBER_DUCK_H
