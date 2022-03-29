#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Line.h"

TEST_SUITE("Line Tests")
{
	TEST_CASE("Line creation")
	{
		// Arrange
		Point f{1, 0}, s{0, 1};

		// Act
		Line l(f, s);
		
		// Check
		CHECK(l.getPoint(false).mX == f.mX);
		CHECK(l.getPoint(false).mY == f.mY);

		CHECK(l.getPoint(true).mX == s.mX);
		CHECK(l.getPoint(true).mY == s.mY);
	}

	TEST_CASE("IsParallelWith method")
	{
		// Arrange
		Line l1({1, 0}, {0, 1}),
		     l2({2 ,0}, {0, -2}),
			 l3({3, 0}, {0, 3});

		// Act
		bool result1 = l1.isParallelWith(l2);
		bool result2 = l1.isParallelWith(l3);

		// Check
		CHECK(result1 == false);
		CHECK(result2 == true);
	}

	TEST_CASE("Contains method")
	{
		// Arrange
		Line l1({1, 0}, {0, 1});

		// Act
		bool result1 = l1.contains({1, 1});
		bool result2 = l1.contains({-1, 2});

		// Check
		CHECK(result1 == false);
		CHECK(result2 == true);
	}

	TEST_CASE("Intersection method")
	{
		// Arrange
		Line l1({1, 0}, {0, 1}),
		     l2({2 ,0}, {0, -2}),
			 l3({3, 0}, {0, 3});

		// Act
		Point *result1 = l1.intersection(l2);
		Point *result2 = l1.intersection(l3);

		// Check
		CHECK(result1 != nullptr);
		CHECK(result1->mX - 1.5 < EPS);
		CHECK(result1->mY + 0.5 < EPS);
		CHECK(result2 == nullptr);

		// Free
		delete result1;
	}
}