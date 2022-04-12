#ifndef __DISH_H
#define __DISH_H

struct Dish {
	char* mName;
	unsigned mId;
	int* mAlergens;
};

void init(Dish& dish);
void clear(Dish& dish);
void write(const char* filename, Dish* dishes, size_t numberOfDishes);
Dish* read(const char* filename, size_t& numberOfDishes);
void print(Dish* dishes, size_t numberOfDishes);

#endif