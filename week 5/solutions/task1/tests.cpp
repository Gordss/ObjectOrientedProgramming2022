#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "matrix.h"

TEST_SUITE("Matrix Tests")
{
    TEST_CASE("Default constructor and getAt")
    {
        // Arrange
        Matrix mat;

        // Act

        // Check
        // size is as expected by default
        CHECK(mat.getSize() == 3);

        // elements are as expected by default
        CHECK(mat.getAt(0, 0) == 0);
        CHECK(mat.getAt(0, 1) == 0);
        CHECK(mat.getAt(0, 2) == 0);

        CHECK(mat.getAt(1, 0) == 0);
        CHECK(mat.getAt(1, 1) == 0);
        CHECK(mat.getAt(1, 2) == 0);

        CHECK(mat.getAt(2, 0) == 0);
        CHECK(mat.getAt(2, 1) == 0);
        CHECK(mat.getAt(2, 2) == 0);
    }

    TEST_CASE("Copy constructor and operator=")
    {
        // Arrange
        Matrix mat1;

        // Act
        Matrix mat2(mat1), mat3;
        mat3 = mat1;

        // Check
        // size is the same
        CHECK(mat1.getSize() == mat2.getSize());

        // elements are the same
        size_t i = 1, j = 0;
        CHECK(mat1.getAt(i, j) == mat2.getAt(i, j));

        // operator=
        CHECK(mat1.getSize() == mat3.getSize());
        CHECK(mat1.getAt(i, j) == mat3.getAt(i, j));
    }

    TEST_CASE("Getters and constructor w/h parameters")
    {
        const size_t size = 4;
        int** matrixBody = new int*[size];
        for(size_t i = 0; i < size; i++) {
            matrixBody[i] = new int; 
            for (size_t j = 0; j < size; j++) {
                matrixBody[i][j] = i + j;
            }
        }

        Matrix mat(size, matrixBody);

        CHECK(mat.getSize() == size);

        for (size_t i = 0; i < size; i++) {
            for(size_t j = 0; j < size; j++) {
                CHECK(mat.getMatrix()[i][j] == matrixBody[i][j]);
            }
        }
        
        for(size_t i = 0; i < size; i++) {
            delete[] matrixBody[i];
        }
        delete[] matrixBody;
    }

    TEST_CASE("Add matrices")
    {
        Matrix mat1;

        const size_t size = 3;
        int** matrixBody = new int*[size];
        for(size_t i = 0; i < size; i++) {
            matrixBody[i] = new int; 
            for (size_t j = 0; j < size; j++) {
                matrixBody[i][j] = i + j;
            }
        }

        Matrix mat2(size, matrixBody);

        Matrix mat3 = mat1.add(mat2);

        CHECK(mat3.getSize() == size);

        // we are adding zero matrix to a non-zero matrix, so the resulting matrix should be same as the latter
        for (size_t i = 0; i < size; i++) {
            for(size_t j = 0; j < size; j++) {
                CHECK(mat3.getMatrix()[i][j] == matrixBody[i][j]);
            }
        }

        for(size_t i = 0; i < size; i++) {
            delete[] matrixBody[i];
        }
        delete[] matrixBody;
    }
}
