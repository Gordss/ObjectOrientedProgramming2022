#ifndef __REAL_DUCK_H
#define __REAL_DUCK_H

#include "Duck.h"

class RealDuck : public Duck
{
private:
	std::string mName;
	int mAge;

public:
	RealDuck();
	RealDuck(const int &, const double &, const std::string &, const std::string &, const int &);

	Duck *clone() const override;
	void print() const override;
	void quack() override;

	void setName(const std::string &);
	void setAge(const int);

	std::string getName() const;
	int getAge() const;

	std::istream &read(std::istream &) override;
	std::ostream &write(std::ostream &) const override;
};

#endif // !__REAL_DUCK_H
