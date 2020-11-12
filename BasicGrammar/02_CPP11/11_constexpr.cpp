#include <iostream>
#include <array>
using namespace std;

/**
 * constexpr关键字使指定的常量表达式获得在编译阶段计算结果的能力
 * 可用于修饰普通变量、函数
 * (1) 修饰变量
 * (2) 修饰函数：必须有定义。函数中除using、typedef、static_assert只能含return。必须有返回值且为常量表达式
 * (3) 修改类的构造函数：函数体必须为空，且采用初始化列表的方式为各个成员赋值时，必须使用常量表达式
 */

constexpr int display(int x)
{
    return 1 + 2 + x;
}


struct myType
{
    constexpr myType(const char *_name, int _age):name(_name),age(_age){};
    const char* name;
    int age;
};

template <typename T>
constexpr T display_(T t)
{
    return t;
}

constexpr int sqr1(int arg)
{
    return arg*arg;
}

const int sqr2(int arg)
{
    return arg*arg;
}


int main(int argc, char * argv [ ])
{
    // constexpr 修改普通变量时，变量必须经过初始化且初始值必须是一个常量表达式
    constexpr int num = 1 + 2 + 3;
    int arr[num] = {0};

    cout<<display(1000)<<endl;


    constexpr struct myType mt {"tanxiaohai", 10};

    cout<<display_(1000)<<endl;

    // 只读使用const，常量使用constexpr
    array<int, sqr1(10)> mylist1; // 可以constexpr
    //array<int, sqr2(10)> mylist1 // 不可以const
    return 0;
}

