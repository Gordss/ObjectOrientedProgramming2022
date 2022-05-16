#include <iostream>
#include "Singleton.h"

int main() {
	
	/*
	Some example usages are to represent your project app.
	Something like a class Engine that has a method run()
	and this will start the app.
	This makes the main function simple (good practise).
	Also everything which makes sense to exist only once in your app.
	*/

	// Singleton* singleton = new Singleton();
	// Singleton* singleton = Singleton::mInstance;
	// Singleton d = std::move(*Singleton::getInstance());
	// d.print();

	Singleton* s = Singleton::getInstance();
	s->increase();
	s->increase();
	s->increase();
	s->print();
	s->getInstance();
	s->getInstance();
	std::cout << "Counter: " << s->getCounter() << '\n';
	s->free();

	return 0;
}