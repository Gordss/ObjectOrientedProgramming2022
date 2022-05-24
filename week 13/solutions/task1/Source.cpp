#include <iostream>
#include <fstream>
#include "RubberDuck.h"
#include "PlasticDuck.h"
#include "RealDuck.h"
#include "Lake.h"

int main()
{
	Lake lake("Duck Mania");
	lake.addDuck(new RubberDuck(14, 120, "yellow", 69, true))
		.addDuck(new RubberDuck(25, 450, "orange", 5, false))
		.addDuck(new PlasticDuck(120, 1000, "pink", 8))
		.addDuck(new PlasticDuck(60, 500, "white", 3))
		.addDuck(new RealDuck(80, 20000, "white", "Chocho", 5))
		.addDuck(new RealDuck(90, 25000, "black", "Becky", 7));

	std::ofstream writeFile;
	writeFile.open("myLake.data");
	if (writeFile.is_open() == false)
	{
		std::cout << "Couldn't open file for writing!\n";
		return -1;
	}
	writeFile << lake;
	writeFile.close();
	std::cout << "File created successfully!\n";

	std::ifstream readFile;
	Lake lake02;

	readFile.open("myLake.data");
	if (readFile.is_open() == false)
	{
		std::cout << "Couldn't open file for reading\n";
		return -1;
	}
	readFile >> lake02;
	lake02.print();
	readFile.close();

	return 0;
}