#include <iostream>
#define MAX_SIZE 1024

enum Taste {SOUR, SWEET, BITTER, SPICY};
const char* tastes[] = {
	"SOUR", "SWEET", "BITTER", "SPICY"
};

struct Vegetable {
	char* mName;
	Taste mTaste;
	double mWeight;

	void init() {
		std::cout << "Enter vegetable name: ";
		char input[MAX_SIZE] ;
		std::cin.getline(input, MAX_SIZE);
		mName = new char[strlen(input) + 1];
		strcpy(mName, input);

		std::cout << "Enter taste: \n";
		std::cout << "0 - SOUR, 1 - SWEET, 2 - BITTER, 3 - SPICY: ";
		int taste;
		std::cin >> taste;
		mTaste = (Taste)taste;

		std::cout << "Enter veggie weight: ";
		std::cin >> mWeight;
		std::cout << std::endl;
		std::cin.ignore();
	}

	void throwAway() {
		delete[] mName;
	}
};

struct Dressing {
	char* mName;
	Taste mTaste;
	double mQuantity;
	char** mAlergens;
	size_t mNumberOfAlergens;

	void init() {
		std::cout << "Enter dressing name: ";
		char input[MAX_SIZE] ;
		std::cin.getline(input, MAX_SIZE);
		mName = new char[strlen(input) + 1];
		strcpy(mName, input);

		std::cout << "Enter taste: \n";
		std::cout << "0 - SOUR, 1 - SWEET, 2 - BITTER, 3 - SPICY: ";
		int taste;
		std::cin >> taste;
		mTaste = (Taste)taste;

		std::cout << "Enter dressing quantity: ";
		std::cin >> mQuantity;

		std::cout << "Enter number of alergens: ";
		std::cin >> mNumberOfAlergens;
		mAlergens = new char*[mNumberOfAlergens];
		std::cin.ignore();
		for(int i = 0; i < mNumberOfAlergens; i++) {
			std::cout << "Enter alergen name: ";
			char input[MAX_SIZE];
			std::cin.getline(input, MAX_SIZE);
			mAlergens[i] = new char[strlen(input) + 1];
			strcpy(mAlergens[i], input);
		}
	}

	void throwAway() {
		delete[] mName;
		for(int i = 0; i < mNumberOfAlergens; i++) {
			delete[] mAlergens[i];
		}
		delete[] mAlergens;
	}
};

struct Salad {
	char* mName;
	size_t mNumberVeggies;
	Vegetable* veggies;
	size_t mNumberDressings;
	Dressing* dressings;

	void init() {
		std::cout << "Let's make salad! \n";
		std::cout << "Enter salad name: ";
		char input[MAX_SIZE] ;
		std::cin.getline(input, MAX_SIZE);
		mName = new char[strlen(input) + 1];
		strcpy(mName, input);

		std::cout << "Enter number of vegetables: ";
		std::cin >> mNumberVeggies;
		veggies = new Vegetable[mNumberVeggies];
		std::cin.ignore();

		for(int i = 0; i < mNumberVeggies; i++) {
			veggies[i].init();
		}

		std::cout << "Enter number of dressings: ";
		std::cin >> mNumberDressings;
		dressings = new Dressing[mNumberDressings];
		std::cin.ignore();

		for(int i = 0; i < mNumberDressings; i++) {
			dressings[i].init();
		}
	}

	double getWeight() {
		double total = 0.0;
		for (int i = 0; i < mNumberVeggies; i++) {
			total += veggies[i].mWeight;
		}

		for(int i = 0; i < mNumberDressings; i++) {
			total += dressings[i].mQuantity;
		}

		return total;
	}

	Taste getTaste() {
		int taste[4] = {0};
		for (int i = 0; i < mNumberVeggies; i++) {
			taste[veggies[i].mTaste]++;
		}

		for(int i = 0; i < mNumberDressings; i++) {
			taste[dressings[i].mTaste]++;
		}

		int max = taste[0];
		int maxInd = 0;
		for (int i = 1; i < 4; i++) {
			if (max < taste[i]) {
				max = taste[i];
				maxInd = i;
			}
		}

		return (Taste) maxInd;
	}

	void printAlergens() {
		for (int i = 0; i < mNumberDressings; i++) {
			for(int j = 0; j < dressings[i].mNumberOfAlergens; j++) {
				std::cout << dressings[i].mAlergens[j] << std::endl;
			}
		}
	}

	void print() {
		std::cout << "-----------------------" << mName << "-----------------------\n";
		std::cout << "Contents: ";
		for(int i = 0; i < mNumberVeggies; i++) {
			std::cout << veggies[i].mName << ", ";
		}
		std::cout << std::endl;
		for(int i = 0; i < mNumberDressings; i++) {
			std::cout << dressings[i].mName;
			if (i != mNumberDressings - 1) {
				std::cout << ", ";
			}
		}

		std::cout << std::endl << std::endl;
		std::cout << "Quantity: " << getWeight() << "\n";
		std::cout << std::endl;

		std::cout << "Description: " << tastes[getTaste()] << "\n";
		std::cout << std::endl;

		std::cout << "Alergens: ";
		printAlergens();
		std::cout << std::endl;
		std::cout << "----------------------- Bon appetit! -----------------------\n";
	}

	void throwAway() {
		delete[] mName;

		for(int i = 0; i < mNumberVeggies; i++) {
			veggies[i].throwAway();
		}
		
		for(int i = 0; i < mNumberDressings; i++) {
			dressings[i].throwAway();
		}

		delete[] veggies;
		delete[] dressings;
	}
};

int main() {
	Salad salad;
	salad.init();

	salad.print();

	salad.throwAway();

	return 0;
}