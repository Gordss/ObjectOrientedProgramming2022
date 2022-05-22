#ifndef __BOOK_H
#define __BOOK_H

#include <iostream>
#include "PrintedEdition.h"

class Book : public PrintedEdition {
    std::string mAuthor;
public:
    Book(std::string, size_t, std::string);

    friend std::ostream& operator<<(std::ostream&, const Book&);
};

std::ostream& operator<<(std::ostream&, const Book&);

#endif