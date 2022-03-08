# Coding convensions

## Multiple-word identifier formats

|     name      |  example   |
| :-----------: | :--------: |
|   flat case   |  twowords  |
|  upper case   |  TWOWORDS  |
| **camelCase** |  twoWords  |
|  PaskalCase   |  TwoWords  |
|  snake_case   | two_words  |
|  kebab-case   | two-words  |
|  döner\|case  | two\|words |

## Example for struct/class

```c++
class SomeClass {
    int mCapacity;

    void capacity();
};
```

## Example for enum

```c++
enum { MAX_VALUE, BQL_HLQB };
```

# Multiple file compilation

> The "compilation" of a program actually consitsts of two major stages.

1. Compile stage

- Syntax checked for correctness.
- Variables and function calls checked to insure that correct declarations were made and that they match. (Note:& The compiler doesn't need to match function definitions to their calls at this point).
- Translation into object code. Object code is just a translation of your code file -- it is not an executable program, at this point. (Note: the word "object" in object code does not refer to the definition of "object" that we use to define object-oriented programming. These are different terms.)

2. Linking stage

- Links the object code into an executable program.
- May involve one or more object code files.
- The linking stage is the time when function calls are matched up with their definitions, and the compiler checks to make sure it has one, and only one, definition for every function that is called.
- The end result of linking is usually an executable program.

## Commands for compiling c++ code via terminal with g++ 

> First -> create .o (object files) from every .cpp
```bash
g++ -c mycpp.cpp
g++ -c main.cpp

or 

g++ -c *.cpp # compiles every .cpp file in the directory and creates .o
```

> Second -> compile all the .o files together
```bash
g++ mycpp.o main.o -o myProgram

or

g++ *.o -o myProgram # compiles every .o file together and creates executable
```

> if there are no errors, you will have `myProgram` as executable file :)

**Rule of thumb:** Only include the header files, not the .cpp files (in the code)

# Задачи

> Задача 1

1. Да се създаде структура **Animal**, която съдържа следните полета:
   - вид на животното (mammal, reptile, fish, bird, amphibian, ivertebrates or insect)
   - име на животното
   - години на животното
   - ... може да добавите още
  
2. Създайте следните методи на структурата Animal:
   - initialize() - инициализира полетата на структурата, чрез вход от клавиатурата, като извежда подходящи съобщения на потребителя
   - deleteDynamic() - няма нужда от пояснение :)
   - loadFromStream(std::istream& in) - инициализира полетата от потока in /*предполагаме, че това е отворен файл за четене*/
   - writeToStream(std::ostream& out) - записва структурата в потока /*предполагаме, че това е отворен файл за писане*/
  
  <details>
  <summary>
  <b>Подсказка как да запишем структурата в потока</b>
  </summary>
  
  - Всяко поле на структурата може да го разположим на отделен ред или може всяко поле да го разделим с един ' ' (**това работи, само когато файлът не е двоичен**)
  
  - ако имаме поле, което е масив, може да го съхраним по следния начин

```
<брой елементи на масива> <елемент1><елемент2>...
```

    При необходимост може да използвате някакъв символ за разделител между различните елементи!

  </details>

3. Създайте структура Zoo, която има:
   - име
   - списък от животни
   - брой на животните
   - максимален брой животни, който може да побере (капацитет)

4. Създайте следните методи за структурата Zoo:
   - initialize() - инициализира полетата на структурата от клавиатурата
   - deleteDynamic()
   - loadFromStream(std::istream in) - инициализира полетата на структурата от поток за вход
   - writeToStream(std::ostream out) - записва структурата в поток за изход

5. Създайте метод, който проверява дали в зоологическата градина има животно от даден вид.

```c++
bool hasType(char* type);
или
bool hasType(AnimalType type);
```

> Задача 2 

1. Да се създаде структура, с която да се представя времето в следния формат:
#### dd MMM YYYY, hh:mm

```c++
Пример: 28 Feb 2021, 14:22
```

2. За целта първо ще ни трябва структура Time със следните полета:
- mHours
- mMinutes

3. После и структурата Date с полета:
- mYear
- mMonth
- mDay
- mTime

4. Да се реализират следните функции:
- Date readDate(ifstream& in) – прочита датата от поток и я връща
- void writeDate(ofstream& out) – записва датата в потока