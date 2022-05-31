/*

Interface Segregation Principle

A client should never be forced to implement an interface that it doesn't use
or clients shouldn't be forced to depend on methods they do not use.

many client specific interfaces are better than one general interface

*/

//don't 
struct Document;

struct IMachine {
    virtual void print(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
};

struct MultiFunctionPrinter : IMachine {
    void print(Document& doc) override {
        //do printing...
    }
    void scan(Document& doc) override { 
        //do scanning ...
    }
};

struct Scanner : IMachine {             
    void print(Document& doc) override {
        //do printing...
    }
    void scan(Document& doc) override {
        //do scanning ...
    }
};

//do
struct IPrinter {
    virtual void print(Document& doc) = 0;
};

struct IScanner {
    virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter {
    void print(Document& doc) override {
        //...
    }
};

struct Scanner : IScanner {
    void scan(Document& doc) override {
        //...
    }
};

struct IMachine : IPrinter, IScanner { };

struct Machine : IMachine {
    IPrinter& mPrinter;
    IScanner& mScanner;
public:
    Machine(IPrinter& p, IScanner& s);
    void print(Document& doc) override {
        //do printing...
    }
    void scan(Document& doc) override {
        //do scanning...
    }
};