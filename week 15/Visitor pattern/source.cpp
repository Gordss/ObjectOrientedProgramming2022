#include <iostream>
#include <fstream>

#include "Group.h"
#include "Rectangle.h"
#include "Circle.h"
#include "SerializeVisitor.h"

int main()
{
    Rectangle r1(15, 25, 200, 300, "first rectangle"),
              r2(450, 311, 100, 50, "second rectangle");
    Circle c(150, 350, 69, "just circle");

    Group g1(100, 150, "Some group"),
          g2(800, 1200, "High group");

    g1.addShape(&r1);
    g1.addShape(&c);

    g2.addShape(&r2);
    g2.addShape(&g1);

    std::ofstream file("shapes.drw", std::ios::app);
    Shape *groupPointer = &g2;

    if (file.is_open() == false)
    {
        std::cout << "Couldn't open file to write\n";
        return -1;
    }

    SerializeVisitor serializer(file);
    groupPointer->accept(&serializer);

    file.close();

    return 0;
}