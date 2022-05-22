#include "Newspaper.h"

Newspaper::Newspaper(std::string name, size_t size, size_t edition) : PrintedEdition(name, size) {
    mEdition = edition;
}

std::ostream& operator<<(std::ostream& out, const Newspaper& newspaper) {
    out << "-------- NEWSPAPER -------- \n";
    out << "Name: " << newspaper.mName << '\n';
    out << "Size: " << newspaper.mSize << '\n';
    out << "Id: " << newspaper.mId << '\n';
    out << "Edition number: " << newspaper.mEdition << '\n';
    out << "--------------------------- \n";
    return out;
}