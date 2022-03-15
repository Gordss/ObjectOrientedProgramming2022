#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#define MAX_SIZE 1024

enum Position
{
    JUNIOR_DEV,
    DEV,
    SENIOR_DEV,
    QA,
    MANAGER
};

struct Developer
{
    int mId;
    char *mFirstName;
    char *mLastName;
    Position mPosition;

    void init()
    {
        mId = rand() % 9000 + 1000; 

        std::cout << "Enter first name:";
        char firstName[MAX_SIZE];
        std::cin.getline(firstName, MAX_SIZE);
        mFirstName = new char[strlen(firstName) + 1];
        strcpy(mFirstName, firstName);

        std::cout << "Enter last name:";
        char lastName[MAX_SIZE];
        std::cin.getline(lastName, MAX_SIZE);
        mLastName = new char[strlen(lastName) + 1];
        strcpy(mLastName, lastName);

        std::cout << "Enter position: \n";
        std::cout << "0 -> JUNIOR_DEV \n";
        std::cout << "1 -> DEV \n";
        std::cout << "2 -> SENIOR_DEV \n";
        std::cout << "3 -> QA \n";
        std::cout << "4 -> MANAGER \n";
        unsigned position;
        std::cin >> position;
        mPosition = (Position)position;
    }

    void clear()
    {
        delete[] mFirstName;
        delete[] mLastName;
    }

    void write(std::ostream &out)
    {
        out << mId << '\n';
        out << strlen(mFirstName) << " " << mFirstName << '\n';
        out << strlen(mLastName) << " " << mLastName << '\n';
        out << mPosition << '\n';
    }

    void print()
    {
        std::cout << "------------- Developer -------------\n";
        write(std::cout);
        // write(std::cerr);
        std::cout << "-------------------------------------\n";
    }

    void read(std::ifstream &in)
    {
        in >> mId;

        int len;
        in >> len;
        mFirstName = new char[len + 1];
        in >> mFirstName;

        in >> len;
        mLastName = new char[len + 1];
        in >> mLastName;

        int position;
        in >> position;
        mPosition = (Position)position;
    }
};

int main()
{
    srand(time(NULL));

    Developer dev;

    try
    {
        dev.init();
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
        return 1;
    }

    std::ofstream outFile("developers.dev", std::ios::app);
    dev.write(outFile);

    outFile.close();

    dev.clear();

    Developer dev1;
    std::ifstream inFile("developers.dev");
    try
    {
        dev1.read(inFile);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
        return 1;
    }
    dev1.print();

    inFile.close();

    dev1.clear();
}