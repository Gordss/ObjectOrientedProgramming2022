#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "dictionary.h"

TEST_SUITE("Record Tests")
{
    TEST_CASE("init record")
    {
        // Arrange
        Record rec;

        // Act
        rec.init("test word", "test meaning");

        // Check
        CHECK(strcmp("test word", rec.mWord) == 0);
        CHECK(strcmp("test meaning", rec.mMeaning) == 0);
    }

    TEST_CASE("copy record")
    {
        // Arrange
        Record rec;
        rec.init("test word", "test meaning");

        // Act
        Record result = rec.copy();

        // Check
        CHECK(strcmp(result.mWord, rec.mWord) == 0);
        CHECK(strcmp(result.mMeaning, rec.mMeaning) == 0);
    }
}


TEST_SUITE("Dictionary Tests")
{
    TEST_CASE("init dictionary and find meaning")
    {
        // Arrange
        Record rec1, rec2, rec3;
        rec1.init("computer", "Similar to air conditioners. Works fine until you open up windows.");
        rec2.init("programmer", "A person who is paid to professionally scream at a computer.");
        rec3.init("cofveve", "It literally means covfefe.");
        Record records[] = {rec1, rec2, rec3};
        Dictionary dict;

        // Act
        dict.init(records, sizeof(records) / sizeof(Record));

        // Check
        CHECK(strcmp(dict.findMeaning("computer"), "Similar to air conditioners. Works fine until you open up windows.") == 0);
        CHECK(strcmp(dict.findMeaning("programmer"), "A person who is paid to professionally scream at a computer.") == 0);
        CHECK(strcmp(dict.findMeaning("cofveve"), "It literally means covfefe.") == 0);
    
        // Free
        rec1.deleteDynamic();
        rec2.deleteDynamic();
        rec3.deleteDynamic();
        dict.deleteDynamic();
    }

    TEST_CASE("add item to dictionary")
    {
        // Arrange
        Record rec1;
        rec1.init("server", "Person who takes your order and brings you food at a restaurant.");
        
        Dictionary dict;

        // Act
        bool result = dict.add(rec1);

        // Check
        CHECK(result == true);
        CHECK(strcmp(dict.findMeaning("server"), "Person who takes your order and brings you food at a restaurant.") == 0);
    
        // Free
        rec1.deleteDynamic();
        dict.deleteDynamic();
    }

    TEST_CASE("remove item from dictionary and item exists")
    {
        // Arrange
        Record rec1;
        rec1.init("Ubuntu", "Ubuntu is an ancient african word, meaning \"I can't configure Debian\"");
        Record records[] = {rec1};
        Dictionary dict;
        dict.init(records, sizeof(records) / sizeof(Record));

        // Act
        bool result = dict.remove("Ubuntu");

        // Check
        CHECK(result == true);
        CHECK(dict.findMeaning("Ubuntu") == nullptr);

        // Free
        rec1.deleteDynamic();
        dict.deleteDynamic();
    }

    TEST_CASE("remove item from dictionary and item does not exist")
    {
        // Arrange
        Record rec1;
        rec1.init("Ubuntu", "Ubuntu is an ancient african word, meaning \"I can't configure Debian\"");
        Record records[] = {rec1};
        Dictionary dict;
        dict.init(records, sizeof(records) / sizeof(Record));

        // Act
        bool result = dict.remove("computer");

        // Check
        CHECK(result == false);
        CHECK(dict.findMeaning("computer") == nullptr);
        CHECK(strcmp(dict.findMeaning("Ubuntu"), "Ubuntu is an ancient african word, meaning \"I can't configure Debian\"") == 0);

        // Free
        rec1.deleteDynamic();
        dict.deleteDynamic();
    }

    TEST_CASE("sort dictionary")
    {
        // Arrange
        Record rec1, rec2;
        rec1.init("cofveve", "It literally means covfefe.");
        rec2.init("chick", "The nicest way to refer to any female");
        Record records[] = {rec1, rec2};

        Dictionary dict;
        dict.init(records, sizeof(records) / sizeof(Record));

        // Act
        dict.sort();

        // Check
        CHECK(strcmp(dict.getByIndex(0), "The nicest way to refer to any female") == 0);
        CHECK(strcmp(dict.getByIndex(1), "It literally means covfefe.") == 0);

        // Free
        rec1.deleteDynamic();
        rec2.deleteDynamic();
        dict.deleteDynamic();
    }
}