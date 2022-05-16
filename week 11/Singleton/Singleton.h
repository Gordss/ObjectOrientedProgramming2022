#ifndef __SINGLETON_H
#define __SINGLETON_H

#include <iostream>
class Singleton
{
private:
	static Singleton* mInstance;
	
	int mCounter;
	Singleton();

public:
	Singleton(const Singleton& other) = delete;
	Singleton(Singleton&& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;
	Singleton& operator=(Singleton&& other) = delete;
	static Singleton* getInstance();
	static void free();
	
	void increase();
	void print() const;
	int getCounter() const;
};

#endif