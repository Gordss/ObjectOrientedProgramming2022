#include "Validator.h"
#include <cstring>

bool Validator::validateNotNull(const char* str)
{
    return !(str == nullptr);
}

bool Validator::validateNotEmpty(const char* str)
{
    return !(strcmp(str, "") == 0);
}
