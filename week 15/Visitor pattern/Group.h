#ifndef __GROUP_H
#define __GROUP_H

#include "Shape.h"
#include <vector>

class Group : public Shape
{
private:
	std::vector<Shape *> mChildren;


	void erase();
public:
	Group(int x, int y, const char *text);
	Group(const Group &other);
	Group &operator=(const Group &other);

	Shape *clone() const override;
	void accept(Visitor *visitor) override;

	void addShape(Shape *shape);
	size_t get_numberOfChildren() const;
	Shape *getChild(size_t) const;

	~Group();
};

#endif