#ifndef __LIBRARY_H
#define __LIBRARY_H
#include "Employee.h"
#include "Reader.h"
#include "Book.h"
#include "Newspaper.h"
#include "PrintedEdition.h"

class Library {
    Employee** mEmployees;
    size_t mNumEmployees;

    Reader** mReaders;
    size_t mNumReaders;

    PrintedEdition** mPrintedEditions;
    size_t mNumPrintedEditions;

    bool isAvailable(const PrintedEdition&);
    bool isRegistered(const Reader&);

    void free();
    void copy(const Library&);
   
    void copyEmployees(size_t, Employee**);
    void copyReaders(size_t, Reader**);
    void copyPrintedEditions(size_t, PrintedEdition**);

    void initEmployees();
    void initReaders();
    void initPrintedEditions();
public:
    Library();
    Library(const Library&);
    Library& operator=(const Library&);
    ~Library();

    void borrow(PrintedEdition&, const Employee&, const Reader&);
    void giveBack(PrintedEdition&, const Employee&, const Reader&);
};

#endif