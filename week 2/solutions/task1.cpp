#include <iostream>
#include <cstring>
#define MAX_SIZE 1024

enum SaberType
{
    SINGLEBLADED = 1,
    DOUBLE_BLADED,
    CROSSGUARD
};

struct LightSaber
{
    char *color;
    SaberType type;
};

struct Jedi
{
    char *name;
    unsigned int age;
    int power;
    LightSaber lightSaber;
    double healthPoints;
};

void initializeSaber(Jedi &jedi)
{
    char input[MAX_SIZE];
    std::cout << "Input saber color:";
    std::cin >> input;

    jedi.lightSaber.color = new char[strlen(input) + 1];
    strcpy(jedi.lightSaber.color, input);

    std::cout << "Input saber type:\n";
    std::cout << "1 - SINGLEBLADED\n";
    std::cout << "2 - DOUBLE_BLADED\n";
    std::cout << "3 - CROSSGUARD\n";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        jedi.lightSaber.type = SaberType::SINGLEBLADED;
        break;
    case 2:
        jedi.lightSaber.type = SaberType::DOUBLE_BLADED;
        break;
    case 3:
        jedi.lightSaber.type = SaberType::CROSSGUARD;
        break;
    default:
        throw "Not supported blade type!";
    }
}

void initializeJedi(Jedi &jedi)
{
    char input[MAX_SIZE];
    std::cout << "Input jedi name:";
    std::cin >> input;

    jedi.name = new char[strlen(input) + 1];
    strcpy(jedi.name, input);

    std::cout << "Input jedi age:";
    std::cin >> jedi.age;

    std::cout << "Input jedi power:";
    std::cin >> jedi.power;

    initializeSaber(jedi);

    jedi.healthPoints = 100;
}

void printSaber(LightSaber &saber)
{
    std::cout << "Saber color: " << saber.color << '\n';

    const char *types[] = {
                            "SINGLEBLADED",
                            "DOUBLE_BLADED",
                            "CROSSGUARD" };

    std::cout << "Saber type: " << types[saber.type - 1] << '\n';
}

void printJedi(Jedi &jedi)
{
    std::cout << "Jedi: " << jedi.name << '\n';
    std::cout << "Age: " << jedi.age << '\n';
    std::cout << "Power:" << jedi.power << '\n';
    printSaber(jedi.lightSaber);
    std::cout << "HP: " << jedi.healthPoints << '\n';
}

void killJedi(Jedi& jedi)
{
    delete[] jedi.name;
    delete[] jedi.lightSaber.color;
}

void battle(Jedi& jedi1, Jedi& jedi2)
{
    std::cout << "Epic battle (" << jedi1.name << " vs. " << jedi2.name << " )\n";

    double jedi1Dmg = (jedi1.power * jedi1.lightSaber.type * strlen(jedi1.lightSaber.color))
                         / jedi1.age;
    double jedi2Dmg = (jedi2.power * jedi2.lightSaber.type * strlen(jedi2.lightSaber.color))
                        / jedi2.age;

    while (jedi1.healthPoints > 0 && jedi2.healthPoints > 0)
    {
        jedi1.healthPoints = jedi1.healthPoints - jedi2Dmg > 0 
                            ? jedi1.healthPoints - jedi2Dmg
                            : 0;
        jedi2.healthPoints = jedi2.healthPoints - jedi1Dmg > 0 
                            ? jedi2.healthPoints - jedi1Dmg
                            : 0;   
    }

    if (jedi1.healthPoints > 0 || jedi2.healthPoints > 0)
    {
        std::cout << "~~~~~Winner~~~~~\n";
        
        if (jedi1.healthPoints > 0)
        {
            printJedi(jedi1);   
        }

        if (jedi2.healthPoints > 0)
        {
            printJedi(jedi2);
        }
        
        std::cout << "~~~~~~~~~~~~~~~~\n";
    }
    else {
        std::cout << "No winner!\n";
    }
}

int main()
{
    Jedi jedi1, jedi2;
	initializeJedi(jedi1);
	printJedi(jedi1);

	initializeJedi(jedi2);
	printJedi(jedi2);

	battle(jedi1, jedi2);

	killJedi(jedi1);
	killJedi(jedi2);
}