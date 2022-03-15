# Unit testing

> Definition

The testing of individual software components (units).

> Какво представлява unit?

Unit е най-малката частица код, която може да се test-ва.(или си заслужава да се тества)
Обикновено това може да е цял модул, но обикновенно е функция или метод.
Има 1 или няколко входа и **един** изход.


|Language|Test framework|
|:--:|:--:|
|C++       |CppUnit, doctest|
|C#        |NUnit, csUnit   |
|Java      |JUnit, Jtest    |
|JavaScript|JSUnit, QUnit   |

*Here are listed some of the most famous frameworks*

> Какъв подход се използва за писане на unit тестове?

- най-използвания подход е test \- function \- expected value
- идеята е, че тестваме точно определена функционалност
- В помощ на unit test-овете влизат method stubs, mock objects, fakes и test harnesses, 
като идеята е, че те ни позволяват да се фокусираме над това, което тестваме
- Целта на unit test-овете е да изолират всяка една част на програмата и да покажат, че е коректна.
- Unit test-овете намират проблеми от рано в development процеса.
- Unit тестовете не гарантират, че кода ще работи на 100%, те дават някаква сигурност че отделния unit ще работи.
*(Иначе за тестването на цялата система се прави Integration testing.)*

## Code coverage

Code coverage is a measurement of how many lines/blocks/arcs of your code are executed while the automated tests are running.

## White vs Black box testing

- Black Box Testing is a software testing method in which the internal structure/design/implementation of the item being tested is not known to the tester.
- White Box Testing is a software testing method in which the internal structure/design/implementation of the item being tested is known to the tester.

## Кой пише unit тестове?

- Usually the software developers write the tests (the programmers that write the code).

## Benefits of unit testing

- Unit testing increases confidence in changing / maintaining code
- Codes are more reusable. Because the code is more modular due to being able to be unit tested.
- The cost of fixing a defect detected during unit testing is lesser in comparison to that of defects detected at higher levels.
- Debugging is easy.

## Some real life example

Lets say you have a program comprising of two units and the only test you perform is system testing. (You skip unit and integration testing.)
During testing, you find a bug. Now, how will you determine the cause of the problem?

Soo:

- Is the bug due to an error in unit 1?
- Is the bug due to an error in unit 2?
- Is the bug due to errors in both units?
- Is the bug due to an error in the interface between the units?
- Is the bug due to an error in the test or test case?

## [Doctest](https://github.com/doctest/doctest)
Линк към Doctest repo-то

# Задачи

> Задача 1

1. Да се дефинира клас Dictionary, който представлява тълковен речник. Нека речникът се състои от двойки дума\-тълкуване. В един речник не може да има повече от 500 такива двойки.
- да се дефинира подходяща структура, описваща една двойка дума тълкувание със следните методи
    - init(const char*, const char*) - инициализира структурата
    - copy() - връща нова структура, копие на оригиналната
    - print() - принтира двойката на екрана по подходящ начин
    - deleteDynamic() - зачиства динамичната памет
- за класа Dictionary да се дефинират:
    - init(Record*, int) - инициализира речника с масив от двойки
    - print() - принтира съдържанието на речника
    - add(const Record&) - добавя нова двойка към речника
    - remove(const char*) - премахва дадена двойка, като търсенето става по думата
    - findMeaning(const char*) - връща значението на дадена дума
    - getByIndex(int index) - връща значението на двойка с номер index
    - sort() - сортира двойките лексикографски по първи член на двойката (не по значението)
    - deleteDynamic() - обичайното :)

> Задача 2. 
Да се създаде
enum Position {JUNIOR_DEV, DEV, SENIOR_DEV, QA, MANAGER};

Да се създаде структура Developer със следните полета:
- mId - идентификационен номер в компанията. Представлява случайно генерирано 4-цифрено число.
- mFirstName;
- mLastName;
- mPosition - позиция, която заема. Една от константите Position.

Да се реализират функции:
- за инициализация на полетата на developer;
- за зачистване на диманичната памет  на developer;
- за записване на Developer във файл. При записване във файл developer-a да се добавя на края на съществуващия файл;
- за четене на полетата на Developer от файл;
- за принтиране на стандартния изход. Използвайте записването във файл.

Помислете как можете да добавите поле на Developer, което представлява прекия мениджър на developer-a и може да се заема само от друг Developer, чиято позиция е Manager.