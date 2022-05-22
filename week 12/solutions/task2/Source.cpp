#include <iostream>
#include "Newspaper.h"
#include "Book.h"
#include "PrintedEdition.h"

#define NAME_MAX_LEN 64
#define SERIAL_NAX_LEN 2
#define DECIMAL 10

int main() {
	PrintedEdition** editions = new PrintedEdition*[20];
	for (size_t i = 0; i < 20; i++) {
		char* name = new char[NAME_MAX_LEN];
		name[0] = '\0';
		strcat(name, "Press-");
		char* number = new char[SERIAL_NAX_LEN];
		strcat(name, itoa(i, number, DECIMAL));

		size_t numPages = 2 * i + 20;
		if (i % 2 == 0) {
			char* authName = new char[NAME_MAX_LEN];
			authName[0] = '\0';
			strcat(authName, "John Doe Jr.");
			strcat(authName, number);
			strcat(authName, "-th");

			editions[i] = new Book(name, numPages, authName);
		}
		else {
			size_t numEd = i + 1;
			editions[i] = new Newspaper(name, numPages, numEd);
		}
	}

	for (size_t i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			std::cout << *((Book*)(editions[i]));
		}
		else {
			std::cout << *((Newspaper*)(editions[i]));
		}
	}

	for (size_t i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			std::swap(editions[i], editions[i + 1]);
			/*PrintedEdition* temp = editions[i];
			editions[i] = editions[i + 1];
			editions[i + 1] = temp;*/
		}
	}

	for (size_t i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			std::cout << *((Newspaper*)(editions[i]));
		}
		else {
			std::cout << *((Book*)(editions[i]));
		}
	}

	return 0;
}