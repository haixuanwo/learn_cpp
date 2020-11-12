#include <iostream>
using namespace std;

// 完美转发：函数模板可以将自己的参数保证左右值属性不变，转发给内部调用的其他函数

// 重载被调用函数，查看完美转发的效果
void otherdef(int &t)
{
    cout<<"lvalue\n";
}

void otherdef(const int &t)
{
    cout<<"rvalue\n";
}

// 实现完美转发的函数模板
template <typename T>
void function(T &&t)
{
    otherdef(forward<T>(t));
}

int main(int argc, char * argv [ ])
{
    function(5);

    int x = 1;
    function(x);
    return 0;
}

