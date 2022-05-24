#ifndef __LAKE_H
#define __LAKE_H

#include "Duck.h"
#include <vector>

class Lake {
private:
	std::string mName;
	std::vector<Duck*> mDucks;
public:
	Lake();
	Lake(const std::string&);
	Lake(const std::string&, const std::vector<Duck*>&);
	Lake& addDuck(const Duck*);

	void print() const;

	std::istream& read(std::istream&);
	std::ostream& write(std::ostream&) const;
	friend std::istream& operator>>(std::istream&, Lake&);
	friend std::ostream& operator<<(std::ostream&, const Lake&);
};

#endif // !_LAKE_H