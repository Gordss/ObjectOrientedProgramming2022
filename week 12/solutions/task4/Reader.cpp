#include "Reader.h"

long Reader::id = 1;

Reader::Reader(std::string name, long egn) : Person(egn, name) {
    id++;
}

long Reader::getId() const {
    return mId;
}
