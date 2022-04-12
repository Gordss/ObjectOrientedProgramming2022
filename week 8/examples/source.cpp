#include <iostream>
#include <cstring>

char *copyDynamic(const char *source)
{
	char *temp = new char[strlen(source) + 1];
	strcpy(temp, source);

	return temp;
}

void counter()
{
	int count = 0;

	std::cout << ++count << " ";
}

void counterVar()
{
	static int count = 0;

	std::cout << ++count << " ";
}

class TheCoolClass
{
	int mTheCoolData;

public:
	TheCoolClass() : mTheCoolData(0)
	{
		std::cout << "constructor\n";
	}

	~TheCoolClass()
	{
		std::cout << "destructor\n";
	}
};

void foo()
{
	static TheCoolClass obj;
}

double getValue()
{
	return 4.5;
}

double &getValueVar2()
{
	// static vs const
	static double a = 3.5;

	return a;
}

void setValue(int value)
{
	// TODO: implement some logic
}

void setValueVar1(int &value)
{
	// TODO: implement some logic
}

class A
{
public:
	static void print(std::string &name)
	{
		std::cout << "By reference\n";
		std::cout << name << std::endl;
	}

	static void print(const std::string &name)
	{
		std::cout << "By const reference\n";
		std::cout << name << std::endl;
	}

	static void print(std::string &&name)
	{
		std::cout << "By move semantic\n";
		std::cout << name << std::endl;
	}
};

class B
{
public:
	static void print(char *name)
	{
		std::cout << "By reference\n";
		std::cout << name << std::endl;
	}

	static void print(const char *name)
	{
		std::cout << "By const reference\n";
		std::cout << name << std::endl;
	}

	static void print(char &&name)
	{
		std::cout << "By move semantic\n";
		std::cout << name << std::endl;
	}
};

class C
{
private:
	char *mData;

	static size_t instances;

public:
	C() : mData(nullptr)
	{
		std::cout << "Default ctor\n";
		instances++;
	}

	C(char *data) : mData(copyDynamic(data))
	{
		std::cout << "Constructor with params\n";
		instances++;
	}

	C(const char *data) : mData(copyDynamic(data))
	{
		std::cout << "Constructor with const params\n";
		instances++;
	}

	C(const C &other) : mData(copyDynamic(other.mData))
	{
		std::cout << "Copy constructor\n";
		instances++;
	}

	C(C &&other)
	noexcept
	{
		std::cout << "Move constructor\n";
		this->mData = other.mData;
		other.mData = nullptr;
		instances++;
	}

	C &operator=(const C &other)
	{
		std::cout << "operator=\n";
		if (this != &other)
		{
			delete[] this->mData;
			copyDynamic(other.mData);
		}

		return *this;
	}

	C &operator=(C &&other) noexcept
	{
		std::cout << "move operator=\n";
		if (this != &other)
		{
			this->mData = other.mData;
			other.mData = nullptr;
		}

		return *this;
	}

	~C()
	{
		std::cout << "Destructor\n";
		delete[] this->mData;
	}

	char *getData() const
	{
		return mData;
	}

	size_t getNumberOfInstances() const
	{
		return this->instances;
	}

	static size_t getNumberOfInstancesVar2()
	{
		return instances;
	}
};

size_t C::instances = 0;

int main()
{
	// deep vs shallow
	// 1. Which is the rvalue and which is the lvalue here?

	int variable = 42;

	// int a = variable;

	// 42 = variable;

	// 2. What will be printed here?

	// if (true)
	// {
	// 	foo();
	// }

	// std::cout << "END OF PROGRAM?\n";

	// 3. What will be printed here?

	double x = getValue(); // 4.5
	// x++;  // 5.5
	// getValueVar2() = x; // a = 5.5

	// std::cout << x << '\n';
	// std::cout << getValueVar2() << '\n';

	// 4. What will be the output?

	// for(int i = 0; i < 5; i++)
	// {
	// 	counter();
	// }
	//
	// std::cout << '\n';
	//
	// for (int i = 0; i < 5; i++)
	// {
	// 	counterVar();
	// }

	// 5. Which of the following are alright and which won't compile?

	int a;
	int b = 44;

	// setValue(a);
	// setValue(b);
	// setValue(42);
	// setValueVar1(a);
	// setValueVar1(b);
	// setValueVar1(5);

	// ((b < 4) ? b : a) = 7;
	// std::cout << "a: " << a << '\n';
	// std::cout << "b: " << b << '\n';

	// rvalue   const int&
	// int& ref1 = 10;
	// const int& ref2 = 10;
	// std::cout << &ref1 << '\n';
	// std::cout << &ref2 << '\n';

	// 6. What will be the output from the following lines?

	std::string one = "pine";
	std::string two = "apple";

	A::print(one);
	// A::print(one + two);
	// A::print("Fake");
	// A::print(std::move("Make"));

	// 7. What will be the output from the following lines?
	char temp[]{'a', 'b', 'c', 0};
	char *three = temp;

	// B::print(three);
	// B::print("Gotcha");
	// B::print(std::move("Gotcha"));

	// 8. What will be the output from the following lines?

	C instanceOne;
	C instanceTwo("test");
	C instanceThree(three);
	C instanceFour(instanceTwo);
	C instanceFive;
	instanceFive = instanceTwo;
	C instanceSix(std::move(instanceThree));
	(instanceThree.getData() == nullptr) ? std::cout << "Yes\n" : std::cout << "No\n";

	{
		C temp;
	}

	std::cout << "Objects counter: " << C::getNumberOfInstancesVar2() << '\n';
}