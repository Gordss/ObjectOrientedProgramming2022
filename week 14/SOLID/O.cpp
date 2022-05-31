/*

Open-Closed Principle

classes should be open for extension but closed for modification

*/

#include <vector>

#define PI 3.14

class IShape;

class AreaCalculator
{
private:
    std::vector<IShape *> shapes;

public:
    AreaCalculator(const std::vector<IShape *> _shapes = std::vector<IShape *>()) : shapes(_shapes)
    {
    }

    // what if we had to add more figures?
    /*
    double sum() const {
        double result = 0;
        for (IShape* shape : this->shapes) {
            if (shape->is_a() == "Square") {
                result += shape->length * shape->length;
            }
            else if (shape->is_a() == "Circle") {
                result += shape->radius * shape->radius * PI;
            }
        }
        return result;
    }
    */

    // the right way is make calculateArea method in every class
    /*

    double sum() const {
        double result = 0;
        for (size_t i = 0; i < this->shapes.size(); i++) {
            result += this->shapes[i]->calculate();
        }
        return result;
    }


    double sum() const {
        double result = 0;
        for (IShape* shape : this->shapes) {
            result += shape->calculate();
        }
        return result;
    }
    */
};
