#include <iostream>
using namespace std;

// 移动语义：指以移动而非深拷贝的方式初始化含有指针成员的类对象
/*
在实际开发中，通常在类中自定义移动构造函数的同时，会再为其自定义一个适当的拷贝构造函数。
由此当用户利用右值初始化类对象时，会调用移动构造函数。左值时会调用拷贝构造函数
*/

class demo
{
public:
    demo():num(new int(0))
    {
        cout<<"construct!"<<endl;
    }

    // 拷贝构造函数
    demo(const demo &d):num(new int(*d.num))
    {
        cout<<"copy construct!"<<endl;
    }

    // 移动构造函数
    demo(demo &&d):num(d.num)
    {
        d.num = NULL;
        cout<<"move construct!"<<endl;
    }

    ~demo()
    {
        cout<<"dis construct!"<<endl;
    }
private:
    int *num;
};

demo get_demo()
{
    return demo();
}

int main(int argc, char * argv [ ])
{
    demo a = get_demo();
    return 0;
}

