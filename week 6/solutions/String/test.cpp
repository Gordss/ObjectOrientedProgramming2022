#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "String.h"

TEST_SUITE("String methods")
{
    TEST_CASE("Creating string") {
        // Act
        String str;

        // Check
        CHECK(str.isEmpty() == true);
        CHECK(str.size() == 0);
        CHECK(str.capacity() == DEFAULT_CAPACITY);
    }
    
    TEST_CASE("Copy constructor and operator[]") {
        // Arrange
        const char *temp = "Guns n Roses";

        // Act
        String str(temp);

        // Check
        CHECK(str.isEmpty() == false);
        CHECK(str.size() == 12);
        CHECK(str.capacity() == 16);
        CHECK(str[3] == 's');
        CHECK(str[5] == 'n');
        CHECK(str[6] == ' ');
        CHECK(str[11] == 's');
    }

    TEST_CASE("operator=") {
        // Arrange
        const char *temp = "Guns n Roses";
        String str(temp), result;

        // Act
        result = temp;

        // Check
        CHECK(result.isEmpty() == false);
        CHECK(result.size() == 12);
        CHECK(result.capacity() == 16);
        CHECK(result[3] == 's');
        CHECK(result[5] == 'n');
        CHECK(result[6] == ' ');
        CHECK(result[11] == 's');
    }

    TEST_CASE("Append with const char*")
    {
        // Arrange
        String str("Hello");

        // Act
        str.append(" world");

        // Check
        CHECK(str.size() == 11);
        CHECK(str[0] == 'H');
        CHECK(str[10] == 'd');
        CHECK(str[5] == ' ');
    }

    TEST_CASE("Append with other String")
    {
        // Arrange
        String str("Hello"), str2(" world");

        // Act
        str.append(str2);

        // Check
        CHECK(str.size() == 11);
        CHECK(str[0] == 'H');
        CHECK(str[10] == 'd');
        CHECK(str[5] == ' ');
    }

    TEST_CASE("Push Back") {
        // Arrange
        const char *temp = "zelevi";
        const char *temp2 = "zelevi sarmi";

        String str(temp), str2(temp2);

        // Act
        str.pushBack(' ');
        str.pushBack('s');
        str.pushBack('a');
        str.pushBack('r');
        str.pushBack('m');
        str.pushBack('i');

        // Check
        CHECK(str == str2);
    }

    TEST_CASE("Erase")
    {
        // Arrange
        String str("hakuna");

        // Act
        str.erase();

        // Check
        CHECK(str.isEmpty());
        CHECK(str.size() == 0);
        CHECK(str.capacity() == DEFAULT_CAPACITY);
    }
    
    TEST_CASE("Swap") {
        // Arrange
        const char *temp = "hakuna";
        const char *temp2 = "matata";

        String str(temp), str2(temp2);
        String str3(temp), str4(temp2);

        // Act
        str.swap(str2);

        // Check
        CHECK(str == str4);
        CHECK(str2 == str3);
    }

    TEST_CASE("Substring") {
        // Arrange
        const char *temp = "I like sour candy";
        const char *temp2 = "sour";

        String str(temp), str2(temp2);

        // Act
        String* str3 = str.substring(7, 11);

        // Check
        CHECK(str2 == *str3);

        delete str3;
    }
}

TEST_SUITE("String predefined operators")
{
    TEST_CASE("operator+") {
        // Arrange
        String str("bql"), str2("hlqb"), str3("bqlhlqb");

        // Act
        String result = str + str2;

        // Check
        CHECK(result == str3);
    }

    TEST_CASE("operator+=") {
        // Arrange
        String str("bql"), str2("hlqb"), str3("bqlhlqb");

        // Act
        str += str2;

        // Check
        CHECK(str == str3);
    }

    TEST_CASE("operator+= with the same object") {
        // Arrange
        String str("bql"), str2("bqlbql");

        // Act
        str += str;

        // Check
        CHECK(str == str2);
    }

    TEST_CASE("operator== and operator!=")
    {
        // Arrange
        const char *temp = "Guns n Roses";
        const char *temp2 = "Guns-n-Roses";
        String str(temp), str2(temp2);

        // Act
        bool result = str == str2;

        str[4] = '-';
        str[6] = '-';

        // Check
        CHECK(result == false);
        CHECK(result != true);
        CHECK(str == str2);
    }
}