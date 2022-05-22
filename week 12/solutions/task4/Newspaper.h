#ifndef __NEWSPAPER_H
#define __NEWSPAPER_H

#include <iostream>
#include <cstring>
#include "PrintedEdition.h"

class Newspaper : public PrintedEdition {
    size_t mEdition;
public:
    Newspaper(std::string, size_t, size_t);

    friend std::ostream& operator<<(std::ostream&, const Newspaper&);
};

std::ostream& operator<<(std::ostream&, const Newspaper&);

#endif