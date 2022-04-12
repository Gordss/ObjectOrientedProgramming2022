#include <iostream>
#include <fstream>
#include "Dish.h"
#define MAX_LEN 1024

void init(Dish& dish) {
	std::cout << "Enter id: ";
	std::cin >> dish.mId;

	std::cout << "Enter name: ";
	char buff[MAX_LEN];
	std::cin >> buff;
	dish.mName = new char[strlen(buff) + 1];
	strcpy(dish.mName, buff);
}

void clear(Dish& dish) {
	delete[] dish.mName;
}

// Pass the filename as a parameter; file lifecycle is inside function
void write(const char* filename, Dish* dishes, size_t numberOfDishes) {

	// Open a binary file for writing
	std::ofstream file(filename, std::ios::binary);

	// Write the number of students we want to write inside the file
	file.write((char*)&numberOfDishes, sizeof(size_t));

	// We have dynamic memory, so just like inside binary files
	// we will have to write the size of the dish name inside file,
	// so we know how much memo to allocate when reading
	size_t bufferSize;

	for(size_t i = 0; i < numberOfDishes; i++) {

		// write id
		file.write((char*)&dishes[i].mId, sizeof(unsigned));

		// get size of name
		bufferSize = std::strlen(dishes[i].mName);

		// write the size name
		file.write((char*)&bufferSize, sizeof(size_t));

		// write the name
		file.write(dishes[i].mName, sizeof(char) * bufferSize); // we have #buffersize times a char
	}

	file.close(); // we don't forget to close a file
}

Dish* read(const char* filename, size_t& numberOfDishes) {

	// Open a binary file for reading
	std::ifstream file(filename, std::ios::binary);

	// Read the number of students and save it to number of dishes
	// we will need this parameter by reference, so we can return the array
	file.read((char*)&numberOfDishes, sizeof(size_t));

	// create the array
	Dish* dishes = new Dish[numberOfDishes];

	size_t bufferSize;

	for(size_t i = 0; i < numberOfDishes; i++) {

		// read id
		file.read((char*)&dishes[i].mId, sizeof(unsigned));

		// read size of name
		file.read((char*)&bufferSize, sizeof(size_t));

		// allocate memory for name
		dishes[i].mName =  new char[bufferSize + 1];

		// read name
		file.read(dishes[i].mName, sizeof(char) * bufferSize);
		dishes[i].mName[bufferSize] = 0; // don't forget terminating 0!
	}

	file.close();

	return dishes;
}

void print(Dish* dishes, size_t numberOfDishes) {
	for(size_t i = 0; i < numberOfDishes; i++) {
		std::cout << "------------------------------------\n";
		std::cout << "Id: " << dishes[i].mId << '\n';
		std::cout << "Name: " << dishes[i].mName << '\n';
		std::cout << "------------------------------------\n";
	}
}