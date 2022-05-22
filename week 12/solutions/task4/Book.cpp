#include "Book.h"


Book::Book(std::string name, size_t size, std::string author) : PrintedEdition(name, size) {
    mAuthor = author;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << "----------- BOOK ---------- \n";
    out << "Name: " << book.mName << '\n';
    out << "Size: " << book.mSize << '\n';
    out << "Id: " << book.mId << '\n';
    out << "Author: " << book.mAuthor << '\n';
    out << "--------------------------- \n";
    return out;
}