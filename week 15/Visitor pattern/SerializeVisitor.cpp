#ifndef __SERIALIZEVISITOR_CPP
#define __SERIALIZEVISITOR_CPP

#include "SerializeVisitor.h"
#include <cstring>
#include <iomanip>

SerializeVisitor::SerializeVisitor(std::ostream &outStream)
    : mOut(outStream), mDepth(0)
{
}

void SerializeVisitor::visitRectangle(Rectangle *rectangle)
{
    mOut << std::setw(mDepth * 2 + 1) << " ";

    mOut << "R "
         << rectangle->getX()
         << " "
         << rectangle->getY()
         << " "
         << rectangle->getWidth()
         << " "
         << rectangle->getHeight()
         << " "
         << strlen(rectangle->getText())
         << " "
         << rectangle->getText()
         << "\n";
}

void SerializeVisitor::visitCircle(Circle *circle)
{
    mOut << std::setw(mDepth * 2 + 1) << " ";

    mOut << "C "
         << circle->getX()
         << " "
         << circle->getY()
         << " "
         << circle->getRadius()
         << " "
         << strlen(circle->getText())
         << " "
         << circle->getText()
         << "\n";
}

void SerializeVisitor::visitGroup(Group *group)
{
    mOut << std::setw(mDepth * 2 + 1) << " ";

    mOut << "G "
         << strlen(group->getText())
         << " "
         << group->getText()
         << " "
         << group->get_numberOfChildren()
         << "\n";

    this->mDepth++;

    for (size_t i = 0; i < group->get_numberOfChildren(); i++)
    {
        group->getChild(i)->accept(this);
    }

    mDepth--;
}

#endif