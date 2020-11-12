#include <iostream>
using namespace std;

template <typename T>
struct Foo
{
    typedef T type;
};

template <typename T>
class A
{
    // ...
};

int main(int argc, char * argv [ ])
{
    Foo<A<int>>::type xx;  // c11以前会编译出错
    return 0;
}

