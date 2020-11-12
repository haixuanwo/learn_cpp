#include <iostream>
using namespace std;

// 1、C++98/03支持类默认模板参数
template <typename T, typename U = int, U N = 0>
class Foo
{
    // ...
};

// 2、C++11支持函数默认模板参数
template <typename T = int>
void func(void)
{
    T a;
}

int main(int argc, char * argv [ ])
{

    return 0;
}

