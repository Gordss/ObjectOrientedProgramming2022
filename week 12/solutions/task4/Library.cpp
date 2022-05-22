#include "Library.h"
#include <utility>
#define MAX_READERS 1000
#define MAX_BOOKS 1000
#define MAX_EMPLOYEES 10

void Library::copyEmployees(size_t num, Employee** employees) {
    mNumEmployees = num;
    mEmployees = new Employee*[num];
    for(size_t i = 0; i < num; i++) {
        mEmployees[i] = new Employee(employees[i]->getEgn(), employees[i]->getName(), employees[i]->getPosition());
    }
}

void Library::copyReaders(size_t num, Reader** readers) {
    mNumReaders = num;
    mReaders = new Reader*[num];
    for(size_t i = 0; i < num; i++) {
        mReaders[i] = new Reader(readers[i]->getName(), readers[i]->getEgn());
    }
}

void Library::copyPrintedEditions(size_t num, PrintedEdition** editions) {
    mNumPrintedEditions = num;
    mPrintedEditions = new PrintedEdition*[num];
    for(size_t i = 0; i < num; i++) {
        mPrintedEditions[i] = new PrintedEdition(editions[i]->getName(), editions[i]->getSize());
    }
}

void Library::copy(const Library& other) {
    copyEmployees(other.mNumEmployees, other.mEmployees);
    copyReaders(other.mNumReaders, other.mReaders);
    copyPrintedEditions(other.mNumPrintedEditions, other.mPrintedEditions);
}

void Library::free() {
    for(size_t i = 0; i < mNumEmployees; i++) {
        delete mEmployees[i];
    }
    delete[] mEmployees;

    for(size_t i = 0; i < mNumReaders; i++) {
        delete mReaders[i];
    }
    delete[] mReaders;

    for(size_t i = 0; i < mNumPrintedEditions; i++) {
        delete mPrintedEditions[i];
    }
    delete[] mPrintedEditions;
}

void Library::initEmployees() {
    std::cout << "How many employees would you hire? ";
    std::cin >> mNumEmployees;
    mEmployees = new Employee*[mNumEmployees];
    for(size_t i = 0; i < mNumEmployees; i++) {
        std::cout << "Enter info for employee number " << i << ":";
        std::string name;
        std::cout << "Name: ";
        std::cin >> name;

        long egn;
        std::cout << "Egn: ";
        std::cin >> egn;

        std::string position;
        std::cout << "Position: ";
        std::cin >> position; 
        mEmployees[i] = new Employee(egn, name, position);
    }
}

void Library::initReaders() {
    std::cout << "How many readers do you have? ";
    std::cin >> mNumReaders;
    mReaders = new Reader*[mNumReaders];
    for(size_t i = 0; i < mNumReaders; i++) {
        std::cout << "Enter info for reader number " << i << ":";
        std::string name;
        std::cout << "Name: ";
        std::cin >> name;

        long egn;
        std::cout << "Egn: ";
        std::cin >> egn;
        mReaders[i] = new Reader(name, egn);
    }
}

void Library::initPrintedEditions() {
    std::cout << "How many printedEditions do you have? ";
    std::cin >> mNumPrintedEditions;
    mPrintedEditions = new PrintedEdition*[mNumPrintedEditions];
    for(size_t i = 0; i < mNumPrintedEditions; i++) {
        std::cout << "Enter info for printed edition number " << i << ":";
        std::string name;
        std::cout << "Name: ";
        std::cin >> name;

        size_t size;
        std::cout << "Size: ";
        std::cin >> size;
        mPrintedEditions[i] = new PrintedEdition(name, size);
    }
}

Library::Library() {
    std::cout << "Creating a library..." << std::endl;
    initEmployees();
    initReaders();
    initPrintedEditions();
    std::cout << "Library is created. \n";
}

Library::Library(const Library& other) {
    copy(other);
}

Library& Library::operator=(const Library& other) {
    if (this != &other) {
        free();
        copy(other);
    }

    return *this;
}

Library::~Library() {
    free();
}

bool Library::isAvailable(const PrintedEdition& what) {
    for (size_t i = 0; i < mNumPrintedEditions; i++) {
        if (mPrintedEditions[i]->getId() == what.getId()) {
            return true;
        }
    }

    return false;
}

bool Library::isRegistered(const Reader& who) {
    for (size_t i = 0; i < mNumReaders; i++) {
        if (mReaders[i]->getId() == who.getId()) {
            return true;
        }
    }

    return false;
}


void Library::borrow(PrintedEdition& what, 
                    const Employee& fromWhom,
                    const Reader& toWhom) {
    
    if (what.getIsBorrowed()) {
        std::cout << "Book is unavailable due to it being already being borrowed.";
        return; //todo THROW HERE
    }

    if (!isAvailable(what)) {
        std::cout << "Library does not have the book.";
        return; //todo THROW HERE
    }

    what.setBorrowed(true);
    std::cout << "Book is borrowed by " << toWhom.getName() << " with customer id " << toWhom.getId() << '\n';
    std::cout << "Borrowing is authorised by " << fromWhom.getName() << " (" << fromWhom.getPosition() << ") \n";
}

void Library::giveBack(PrintedEdition& what,
                       const Employee& toWhom,
                       const Reader& fromWhom) {
    if (!what.getIsBorrowed()) {
        std::cout << "Book is not borrowed.";
        return; //todo THROW HERE
    }

    if (!isAvailable(what)) {
        std::cout << "Library does not have the book.";
         return; //todo THROW HERE
    }

    if (!isRegistered(fromWhom)) {
        std::cout << "Reader is not registered.";
         return; //todo THROW HERE
    }

    what.setBorrowed(false);
    std::cout << "Book is returned by " << fromWhom.getName() << " with customer id " << fromWhom.getId() << '\n';
    std::cout << "Returning is authorised by " << toWhom.getName() << " (" << toWhom.getPosition() << ") \n";

}