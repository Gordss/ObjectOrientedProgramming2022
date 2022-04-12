#include <iostream>
#include "Dish.h"
#define NUM_DISHES 3
#define FILENAME "dishes.bin"

// Create 3 dishes and write them to a binary file
void writeDishes() {
	Dish* dishes = new Dish[NUM_DISHES];

	for (size_t i = 0; i < NUM_DISHES; i++) {
		init(dishes[i]);
	}

	write(FILENAME, dishes, NUM_DISHES);
	print(dishes, NUM_DISHES);
}

int main() {
	writeDishes();

	size_t numDishes;

	Dish* dishes = read(FILENAME, numDishes);
	print(dishes, numDishes);

	for(size_t i = 0; i < NUM_DISHES; i++) {
		clear(dishes[i]);
	}
	delete[] dishes;

	return 0;
}