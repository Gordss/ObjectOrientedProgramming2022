# Задачи

> Задача 1.

Да се дефинира клас Matrix, реализиращ квадратна матрица от цели числа, разположена в динамичната памет. За класа дефинирайте:

- голямата четворка (конструктор по подразбиране, който създава нулева матрица 3х3; конструктор за копиране; деструктор; оператор=);
- конструктор с 2 параметъра - размерност и тяло на матрицата;
- гетъри;
- функция за принтиране на матрицата; (*)
- функция int getAt(size_t i, size_t j) const, която връща елемента на позиция [i][j], в случай, че i и j са в допустими граници. В противен случай програмата да хвърля exception; (*)
- функция Matrix add(const Matrix& B), която връща матрица сбор от текущия обект и параметъра на функцията. В случай, че двете матрици са с неподходящи размерности, програмата да хвърля exception.

- да се напишат unit тестове за всички public методи, освен този за принтиране
```c++
Пр.:
 
А = |2 3|
	|4 5|

B = |6 7|
	|8 9|

C = A.add(B); 

=> C = |8  10|
	   |12 14| 
```

#### За напредналите: Помислете как можете да направите подточките, отбелязани със (*), чрез предефинирани оператори. 


> Задача 2

1. Да се създаде структура/клас Point, представляващ точка в евклидовата равнина.

2. Да се дефинира структура/клас Line, описващата права в евклидовата равнина, зададена чрез 2 нейни точки.

Line трябва да поддържа следните методи:
 - isParallelWith(const Line& other) - проверява дали текущата линия е успоредна с other
 - bool contains(const Point& p) - проверява дали дадена точка лежи на правата
 - Point* intersection(const Line& other) - намира пресечната точка на двете прави. Ако двете прави да успоредни - връщаме nullptr.
 - void write(std::ostream& out) - сериализира класа в поток
 - да се направят unit тестове на всички методи, без този за сериализация