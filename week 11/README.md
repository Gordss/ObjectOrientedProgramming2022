# Topics from last time

> Restrict templates to accept only certain types

This typically is unwarranted in C++. In C++ we tend to define generic types based on other constraints other than "inherits from this class". If you really wanted to do that, it's quite easy to do in C++11 and <type_traits>

Example:

```c++
#include <type_traits>

template<typename T>
class observable_list {
    static_assert(std::is_base_of<list, T>::value, "T must inherit from list");
    // code here..
};
```

This breaks a lot of the concepts that people expect in C++ though. It's better to use tricks like defining your own traits. For example, maybe observable_list wants to accept any type of container that has the typedefs const_iterator and a begin and end member function that returns const_iterator. If you restrict this to classes that inherit from list then a user who has their own type that doesn't inherit from list but provides these member functions and typedefs would be unable to use your observable_list.

There are two solutions to this issue, one of them is to not constrain anything and rely on duck typing. A big con to this solution is that it involves a massive amount of errors that can be hard for users to grok. Another solution is to define traits to constrain the type provided to meet the interface requirements. The big con for this solution is that involves extra writing which can be seen as annoying. However, the positive side is that you will be able to write your own error messages for the static_assert.

> Generic pointers in C++

generic pointers in C++ are presented like this:
```c++
void* gp;
```
for dereference they have to be cast to some type.

this works also:
```c++
template <typename T>
void func(T* a);
```

[Link for more info](https://www.ooportal.com/programming-cplus/module4/generic-pointer-type.php)

> There can be a default type for the template

```c++
#include <iostream>

template<typename T = char>
class Container
{
private:
    T mData;
public:
    Container(T data) : mData(data) {}

    void print()
    {
        std::cout << this->mData << '\n';
    }
};

main()
{
    //works from c++17 and above
    //Container a(97);
    Container<> a(97);
    a.print();
}
```

# Design patterns

Design patterns represent the best practices used by experienced object-oriented software developers. Design patterns are solutions to general problems that software developers faced during software development. These solutions were obtained by trial and error by numerous software developers over quite a substantial period of time.

## Usage of design patterns

### Common platform for developers

Design patterns provide a standard terminology and are specific to particular scenario. For example, a singleton design pattern signifies use of single object so all developers familiar with single design pattern will make use of single object and they can tell each other that program is following a singleton pattern.

### Best Practices

Design patterns have been evolved over a long period of time and they provide best solutions to certain problems faced during software development. Learning these patterns helps unexperienced developers to learn software design in an easy and faster way.

## Types of Design Patterns

|№|Pattern & Description|Examples|
|--|:--|--|
|1|**Creational Patterns** <br> These design patterns provide a way to create objects while hiding the creation logic, rather than instantiating objects directly using new operator. This gives program more flexibility in deciding which objects need to be created for a given use case.|Factory pattern, Singleton|
|2|**Structural Patterns** <br> These design patterns concern class and object composition. Concept of inheritance is used to compose interfaces and define ways to compose objects to obtain new functionalities.|Facade pattern|
|3|**Behavioral Patterns** <br> These design patterns are specifically concerned with communication between objects.|Command pattern, Visitor pattern|

> [Link for more info](https://www.tutorialspoint.com/design_pattern/design_pattern_overview.htm)

# Singleton

This pattern involves a single class which is responsible to create an object while making sure that only single object gets created. This class provides a way to access its only object which can be accessed directly without need to instantiate the object of the class.

> Implementation

Provide static method as a getter for a static instance of the class

# Задачи

> Задача 1

- Да се реализира клас Служител. Един служител се представя чрез:
  - име
  - адрес
  - ЕГН
  - отдел, в който работи
  - заплата
- Да се реализира клас Специалист, който наследява служител, но притежава като допълнение описание на специалността си.
- Да се реализира клас Ръководител на отдел, който наследява специалист и притежава информация за отдела, който ръководи и указатели към всички служители в този отдел.
- Да се реализира клас Секретарка, за която имаме списък от езици, които говори.
- Да се реализира клас Директор, който има секретарка и указатели към всички служители във фирмата.
- Да се реализира програма, която да дава възможност да се въведе информация за една фирма. Да се реализира метод за изчисление на необходимата за заплатите сума.

> Задача 2

- Да се реализират класове:
    - Печатно издание (PrintedEdition) – има за член-данни име, обем (брой страници) и идентификационен номер;
    - Книга (Book) – наследява печатно издание и добавя името на автора;
    - Вестник (Newspaper) – наследява печатно издание и добавя номера на броя.
За класовете да се реализират Голямата петица, гетъри и сетъри. Да се предефинира operator<<. При подаване на невалидни данни в конструктора, обработете грешките чрез std::exception.

- Създайте масив от 20 печатни издания, в който на всяка четна позиция стои книга, а на всяка нечетна – вестник. За печатните издания в масива:
    - имената се образуват като „Press-i“;
    - обемът на е 2*i + 20;
    - името на автора на книгите е “John Doe Jr. i-th”;
    - номерът на броя на вестниците е i+1, където i е поредният номер на печатното издание в масива.
Изведете масива. Променете масива, като размените елемента от всяка четна позиция и елемента вдясно от него. Изведете масива отново.