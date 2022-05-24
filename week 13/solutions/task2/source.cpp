#include <iostream>
#include "StringStream.h"
#include "MergeStreams.h"

int main()
{
    StringStream *s = new StringStream("Hello World!");
    std::cout << s->take(10); // Hello Worl
    std::cout << '\n';
    std::cout << s->take(10); // d!
    std::cout << '\n';

    StringStream *s1 = new StringStream("ABCABC"),
                 *s2 = new StringStream("123123"),
                 *s3 = new StringStream("=,=,=!");
    MergeStreams *m1 = new MergeStreams(s1, s2), *m2 = new MergeStreams(m1, s3);
    std::cout << m1->take(6);  // A1B2C3
    std::cout << '\n';
    std::cout << m2->take(12); // A=1,B=2,C=3!
    std::cout << '\n';

    delete s, s1, s2, s3;
    delete m1, m2;
}