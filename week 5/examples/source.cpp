#include <iostream>

class A {
    public:
    A() {
        std::cout << "Contructor\n";
    }

    A(const A& other) {
        std::cout << "Copy constructor\n";
    }

    A& operator=(const A& other) {
        if (this != &other)
        {
            std::cout << "operator=\n";
        }

        return *this;
    }

    ~A() {
        std::cout << "Destructor\n";
    }
};

class B {
    public:
    B() = default;
    B(int);
    B& operator=(const B& other) = delete;
    ~B() = default;
};

int main()
{
    {
        // A obj = A();
        // A obj = A{};
        // A obj;
        // A obj();
        // A obj{};
    }

    // A* obj2 = new A();
    // A* obj3 = new A(*obj2);
    
    // A* obj4;
    // obj4 = obj2;
    // *obj4 = *obj2; // obj4.operator(obj2); -> obj4
    // *obj2 = *obj2;

    // B obj5, obj6;
    // obj5 = obj6;

    // What will be the output?

    // delete obj2;
    // delete obj4;

    return 0;
}