#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vector.h"

template <typename T>
void memberValidation(const Vector<T>& a, const Vector<T>& b)
{
	for (size_t i = 0; i < a.getSize(); i++)
	{
		CHECK(a[i] == b[i]);
	}
}

TEST_SUITE("Vector Tests")
{
	TEST_CASE("Default constructor")
	{
		// Act
		Vector<int> v;
		
		// Check
		CHECK(v.isEmpty());
		CHECK(v.getSize() == 0);
		CHECK(v.getCapacity() == DEFAULT_CAPACITY);
	}

	TEST_CASE("Constructor with param")
	{
		// Arrange
		size_t cap = 9;

		// Act
		Vector<int> v(cap);
		
		// Check
		CHECK(v.isEmpty());
		CHECK(v.getSize() == 0);
		CHECK(v.getCapacity() == cap);
	}

	TEST_CASE("Copy constructor")
	{
		// Arrange
		Vector<int> v1;
		v1.pushBack(1);
		v1.pushBack(3);
		v1.pushBack(6);
		v1.pushBack(10);


		// Act
		Vector<int> v2(v1);
		
		// Check
		memberValidation(v1, v2);
	}

	TEST_CASE("Operator=")
	{
		// Arrange
		Vector<int> v1, v2;
		v1.pushBack(1);
		v1.pushBack(3);
		v1.pushBack(6);
		v1.pushBack(10);


		// Act
		v2 = v1;
		
		// Check
		memberValidation(v1, v2);
	}

	TEST_CASE("Get at")
	{
		// Arrange
		Vector<double> v1, results;
		v1.pushBack(1.01);
		v1.pushBack(4.25);
		v1.pushBack(6.69);
		v1.pushBack(101.90);


		// Act
		results.pushBack(v1.getAt(0));
		results.pushBack(v1.getAt(1));
		results.pushBack(v1.getAt(2));
		results.pushBack(v1.getAt(3));
		
		// Check
		memberValidation(v1, results);
	}

	TEST_CASE("Get at modify")
	{
		// Arrange
		Vector<double> v1;
		v1.pushBack(1.01);

		// Act
		v1.getAt(0) = 11.1;
		
		// Check
		CHECK(v1[0] == 11.1);
	}

	TEST_CASE("Get at throw exception")
	{
		// Arrange
		Vector<double> v1;
		v1.pushBack(1.01);

		// Act
		try
		{
			v1.getAt(1) = 11.1;
		}
		catch(const char* ex)
		{
			CHECK(strcmp(ex, "Index out of bounds!\n") == 0);
		}
	}

	TEST_CASE("Get First")
	{
		// Arrange
		Vector<double> v1;
		v1.pushBack(1.01);

		// Act
		double result = v1.getFirst();
		
		// Check
		CHECK(result == v1[0]);
	}

	TEST_CASE("Get First Throw Exception")
	{
		// Arrange
		Vector<double> v1;
		char* exceptionMessage;

		// Act
		try
		{
			double result = v1.getFirst();
		}
		catch(const char* ex)
		{
			CHECK(strcmp(ex, "Index out of bounds!\n") == 0);
		}
	}

	TEST_CASE("Get Last")
	{
		// Arrange
		Vector<double> v1;
		v1.pushBack(1.01);
		v1.pushBack(2.04);

		// Act
		double result = v1.getLast();
		
		// Check
		CHECK(result == v1[1]);
	}

	TEST_CASE("Get Last Throw Exception")
	{
		// Arrange
		Vector<double> v1;
		char* exceptionMessage;

		// Act
		try
		{
			double result = v1.getLast();
		}
		catch(const char* ex)
		{
			CHECK(strcmp(ex, "Index out of bounds!\n") == 0);
		}
	}

	TEST_CASE("Assign")
	{
		// Arrange
		Vector<char> v1;

		// Act
		v1.assign(3, 'a');

		// Check
		CHECK(v1[0] == 'a');
		CHECK(v1[1] == 'a');
		CHECK(v1[2] == 'a');
	}

	TEST_CASE("PopBack")
	{
		// Arrange
		Vector<char> v1;
		v1.assign(3, 'a');

		// Act
		v1.popBack();

		// Check
		CHECK(v1.getSize() == 2);
		CHECK(v1[0] == 'a');
		CHECK(v1[1] == 'a');
	}

	TEST_CASE("Remove At")
	{
		// Arrange
		Vector<char> v1;
		v1.pushBack('a');
		v1.pushBack('b');
		v1.pushBack('c');
		v1.pushBack('d');

		// Act
		v1.removeAt(2);

		// Check
		CHECK(v1.getSize() == 3);
		CHECK(v1[0] == 'a');
		CHECK(v1[1] == 'b');
		CHECK(v1[2] == 'd');
	}

	TEST_CASE("Operator=")
	{
		// Arrange
		Vector<char> v1;
		v1.pushBack('a');
		v1.pushBack('b');
		v1.pushBack('c');
		v1.pushBack('d');

		Vector<char> v2;
		v2.pushBack('a');
		v2.pushBack('b');
		v2.pushBack('c');
		v2.pushBack('d');

		// Act
		CHECK(v1 == v2);
	}

	TEST_CASE("Operator+")
	{
		// Arrange
		Vector<char> v1;
		v1.pushBack('a');
		v1.pushBack('b');

		Vector<char> v2;
		v2.pushBack('c');
		v2.pushBack('d');

		Vector<char> v3;
		v3.pushBack('a');
		v3.pushBack('b');
		v3.pushBack('c');
		v3.pushBack('d');

		// Act
		Vector<char> v4 = v1 + v2;

		// Check
		memberValidation(v3, v4);
	}
}