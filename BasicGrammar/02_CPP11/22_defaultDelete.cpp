#include <iostream>
using namespace std;

/*
1、如果类中只定义了一个有参数的构造函数，默认构造函数编译器就不再生成了。
那么在外部创建类时，如果创建无参数的类就会出错：因为没有一个无参构造函数。
可以通过default关键字让构造函数恢复

2、delete去除不用的函数
*/
class A
{
public:
    A() = default;
    A(int _m_a):m_a(_m_a){}
    A(int _m_a, int b) = delete;
private:
    int m_a;
};


int main(int argc, char * argv [ ])
{
    A a(1);
    A b;
    // A c(1, 2); delete构造不能调用
    return 0;
}

