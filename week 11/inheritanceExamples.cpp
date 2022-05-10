#include <iostream>

class Base
{ 
    int x;
    public:

    Base(int i) { 
        x = i;
        std::cout << "Base Parameterized Constructor x = " << x << '\n';
    }

    ~Base() {
        std::cout << "Base's destructor \n";
    }

    void print() const {
        std::cout << "Base's x = " << x << '\n';
    }
};

class Derived : public Base
{ 
    int y;
    public:

    Derived(int j = 1):Base(j) { 
        y = j;
        std::cout << "Derived Parameterized Constructor " << " y = " << y << '\n';
    }

    Derived(int i, int j) : Base(i) {
        y = j;
        std::cout << "Derived 2 Parameterized Constructor " << " y = " << y << '\n';
    }

    void print() const {
        Base::print();
        std::cout << "Derived's y = " << y << '\n';
    }
};

class Base1
{ 
    int x;
    public:
    // default constructor
    Base1() 
    { 
        std::cout << "Base1 default constructor x = " << x << '\n'; 
    }

    void print() const {
        std::cout << "Base1's x = " << x << '\n';
    }
};

class Derived1 : public Base1
{ 
    int y;
    public:
    // default constructor
    Derived1() 
    { 
        std::cout << "Derived1 default constructor y = " << y << '\n'; 
    }
    // parameterized constructor
    Derived1(int i) 
    { 
        std::cout << "Derived1 parameterized constructor y = " << y << '\n'; 
    }

    ~Derived1() {
        std::cout << "Derived1 destructor...\n";
    }
};

int main()
{
    // What is the output of the following lines?
    std::cout << "creating b...\n";
    // Base b;   

    std::cout << "creating b1...\n";
    // Base b1(10);

    std::cout << "creating bp...\n";
    Base* bp;
    std::cout << "initializing bp...\n";
    // bp = new Base(20);
    // bp = &b1;
    //bp.print();

    std::cout << "creating d1...\n";
    // Derived d1;    // add + remove initialization list; what happens now?
    
    std::cout << "creating d2...\n";
    // Derived d2(10);    

    // bp = &d2;
    bp->print();

    std::cout << "creating dp...\n";
    Derived* dp;
    std::cout << "init dp...\n";
    // dp = &b1;
    std::cout << "reassign dp...\n";
    // dp = &d2;
    dp->print();

    std::cout << "creating d3...\n";
    Derived1 d3(10);   
    std::cout << "reassigning bp...\n";
    // bp = &d3; 
    // bp->print();
    //((Base)bp)->print();
    //((Base1)*bp).print();
    //((Derived1)*bp).print();

    std::cout << "creating d4...\n";
    // Derived1* d4 = new Derived1;

    std::cout << "deleting bp...\n";
    delete bp;

    std::cout << "deleting d4...\n";
    // delete d4;
    return 0;
}