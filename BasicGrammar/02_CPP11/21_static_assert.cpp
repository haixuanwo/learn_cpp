#include <iostream>
using namespace std;

/*
用来做编译期间的断言，因此叫做静态断言
*/

int main(int argc, char * argv [ ])
{
    static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");
    return 0;
}

