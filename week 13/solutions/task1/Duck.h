#ifndef __DUCK_H
#define __DUCK_H

#include <fstream>

class Duck
{
private:
	int mHeight;
	double mWeight;
	std::string mColor;

public:
	Duck();
	Duck(const int &, const double &, const std::string &);

	virtual Duck *clone() const = 0;
	virtual void print() const;
	virtual void quack() = 0;

	void setHeight(const int &);
	void setWeight(const double &);
	void setColor(const std::string &);

	int getHeight() const;
	double getWeight() const;
	std::string getColor() const;

	virtual std::istream &read(std::istream &);
	virtual std::ostream &write(std::ostream &) const;
	friend std::istream &operator>>(std::istream &, Duck &);
	friend std::ostream &operator<<(std::ostream &, const Duck &);
};

#endif // !__DUCK_H