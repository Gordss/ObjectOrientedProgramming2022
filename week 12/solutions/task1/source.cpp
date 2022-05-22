#include <vector>
#include <iostream>
#include "Manager.h"
#include "CEO.h"


int main()
{
    Employee empl1("Pesho", "Sofia", "IT", 1234567890, 800.50),
             empl2("Tosho", "Sofia", "IT", 987654321, 900.50),
             empl3("Ivaylo", "Sofia", "IT", 1134567890, 780.50);

    std::vector<Employee*> employees;
    employees.push_back(&empl1);
    employees.push_back(&empl2);
    employees.push_back(&empl3);

    Specialist spec1("Sofiya", "Sofia", "IT", "Tech Support", 1234567890, 1000.50),
               spec2("Stefan", "Sofia", "IT", "Full Stack", 987654321, 1600.50),
               spec3("Katerina", "Sofia", "IT", "Front end", 1134567890, 1480.50),
               spec4("Kalina", "Sofia", "IT", "Designer", 1134567890, 1380.50),
               spec5("Koleto", "Sofia", "IT", "Back end", 1134567890, 1480.50);

    std::vector<Employee*> specialists;
    employees.push_back((Employee*)&spec1);
    employees.push_back((Employee*)&spec2);
    employees.push_back((Employee*)&spec3);
    employees.push_back((Employee*)&spec4);
    employees.push_back((Employee*)&spec5);

    Manager manager1("Hristo", "Sofia", "IT", "Team leader", "Project X", 1234567890, 2000.50, employees),
            manager2("Kaloyan", "Sofia", "IT", "Team leader", "Project Y", 1234567890, 2100.50, specialists);

    std::vector<Employee*> managers;
    employees.push_back((Employee*)&manager1);
    employees.push_back((Employee*)&manager2);

    std::vector<std::string> languages;
    languages.push_back("English");
    languages.push_back("French");
    languages.push_back("Japanese");
    languages.push_back("Spanish");

    Secretary secretary("Ivana", "addr", "IT", 1234567890, 1700, languages);

    std::vector<Employee*> empls(employees);
    empls.insert(empls.end(), specialists.begin(), specialists.end());
    empls.insert(empls.end(), managers.begin(), managers.end());
    CEO ceo("Rosi", "adr", "IT", 1234567890, 3500.01, (Employee*)&secretary, empls);

    ceo.print();

    std::cout << "Total salary:" << ceo.calculateTotalSalary() << '\n';
}