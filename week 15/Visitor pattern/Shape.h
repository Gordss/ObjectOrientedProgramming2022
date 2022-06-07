#ifndef __SHAPE_H
#define __SHAPE_H

class Visitor;

class Shape
{
protected:
	int mX;
	int mY;
	char *mText;

public:
	Shape();
	Shape(int x, int y, const char *text);
	Shape(const Shape &other);
	Shape &operator=(const Shape &other);

	virtual void accept(Visitor *visitor) = 0;

	virtual Shape *clone() const = 0;

	void setX(int x);
	void setY(int y);
	void setText(const char *text);

	int getX() const;
	int getY() const;
	char *getText() const;
	virtual ~Shape();
};

#endif