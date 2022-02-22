#include <iostream>
double MULTIPLICATION_NULL_VALUE = 1;

typedef unsigned int POSITIVE_NUMBERS;
typedef double (*type1)(double);
typedef double (*type2)(double, double);

double next(double i) {
    return i + 3;
}

double square(double a) {
    return a * a;
}

double multiply(double a, double b) {
    return a * b;
}

double cube(double a) {
    return a * a * a;
}

double plusOne(double a) {
    return a + 1;
}

double product(double a, double b, double (*next)(double), double (*f)(double)) {
    double nullValue = 1;
    double eps = 0.0001;

    for (double i = a; i < b + eps; i = next(i))
    {
        //nullValue = nullValue * f(i);
        nullValue *= f(i);
    }

    // 1 * 2 * 5 * 8 * 11

    return nullValue;
}


double sum(double a, double b, double (*next)(double), double (*f)(double)) {
    double sum = 0;
    double eps = 0.0001;

    for (double i = a; i < b + eps; i = next(i))
    {
        // sum = sum + f(i);
        sum += f(i);
    }

    // 0 + 9 + 36 + 81
    // 0^3 + 3^3 + 6^3 + 9^3
    
    return sum;
}

double reduce(double a, double b, double initialValue,
              double (*next)(double), double (*f)(double),
              double (*operation)(double, double))
{
    double result = initialValue;
    double eps = 0.0001;

    for (double i = a; i < b + eps; i = next(i))
    {
        result = operation(result, f(i));
    }
    
    return result;
}

double plus(double a, double b)
{
    return a + b;
}

double prod(double a, double b)
{
    return a * b;
}

int main() {

    double (*ptrToFunct)(double) = next;
    // is the same
    // double (*ptrToFunct)(double) = &next;

    // What will be the output?
    // Which lines we expect to be equal?
    // printf("%p\n", next);

    // std::cout << &ptrToFunct << '\n';
    
    // (*ptrToFunc) -> &next -> address of next
    //printf("%p\n", &(*ptrToFunct));

    // What will be the output?
    // std::cout << ptrToFunct(5) << std::endl;

    

    // What will be the output?
    std::cout << reduce(0, 10, 0, next, square, plus) << std::endl;

    // What will be the output?
    std::cout << reduce(0, 10, 0, next, cube, plus) << std::endl;

    // What will be the output?
    std::cout << reduce(1, 10, 1, next, plusOne, prod) << std::endl;

    POSITIVE_NUMBERS a = 5;

    return 0;
    }