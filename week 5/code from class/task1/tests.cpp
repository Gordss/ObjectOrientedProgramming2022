#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "matrix.h"

TEST_SUITE("Matrix tests")
{
    TEST_CASE("Contructor test")
    {
        // Act
        Matrix m;

        // Check
        CHECK(m.getAt(0, 0) == 0);
        CHECK(m.getAt(0, 1) == 0);
        CHECK(m.getAt(0, 2) == 0);

        CHECK(m.getAt(1, 0) == 0);
        CHECK(m.getAt(1, 1) == 0);
        CHECK(m.getAt(1, 2) == 0);

        CHECK(m.getAt(2, 0) == 0);
        CHECK(m.getAt(2, 1) == 0);
        CHECK(m.getAt(2, 2) == 0);
    }

    // TODO: add cases for the other methods
}