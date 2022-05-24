#include "Stream.h"

std::string Stream::take(unsigned n)
{
    std::string result;
    while(n > 0)
    {
        char c = this->get();
        result.push_back(c);
        n--;

        if(c == '\0')
        {
            return result;
        }
    };

    return result;
}