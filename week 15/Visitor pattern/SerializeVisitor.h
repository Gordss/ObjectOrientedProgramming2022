#ifndef __SERIALIZE_VISITOR_H
#define __SERIALIZE_VISITOR_H

#include "Visitor.h"
#include <fstream>

class SerializeVisitor : public Visitor {
private:
	std::ostream& mOut;
	size_t mDepth;
public:
	SerializeVisitor(std::ostream& outStream);

	void visitRectangle(Rectangle* rectangle) override;
	void visitCircle(Circle* circle) override;
	void visitGroup(Group* group) override;
};

#endif