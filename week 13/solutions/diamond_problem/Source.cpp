#include <iostream>
#include "FMITeachingAssistant.h"
#include "SelfHelpBook.h"

int main() {
	std::string name("joro");
	std::vector<std::string> subjectsHeTeaches;
	subjectsHeTeaches.push_back("OOP");
	subjectsHeTeaches.push_back("UP");
	std::vector<std::string> subjectsHeAdvises;
	subjectsHeAdvises.push_back("BD");
	FMITeachingAssistant joro(name, 111111, 222222, 5, subjectsHeTeaches, subjectsHeAdvises);

	//joro.printInfo();

	std::vector<Advisor*> advisors;
	advisors.push_back(&joro);

	SelfHelpBook book("How to live mindfully", subjectsHeAdvises, 12345, "Rosi");
	advisors.push_back(&book);
	for (Advisor* advisor : advisors) {
		advisor->printInfo();
	}

	return 0;
}
