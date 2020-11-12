#include <iostream>
using namespace std;

class A
{
public:
    A(int _i):i(_i) {}
    A(const A& a) { i = a.i; }

    void show()
    {
        cout<<i<<endl;
    }

private:
    int i;
};


class B
{
    // 1、空类只占一个字节
};

class C
{
public:
    C():value(100),value1(119) { }

    void outPut() const
    {
        //value = 200; 2、只读成员函数不能修改一般成员变量
        cout<<"value:"<<value<<endl;
        b = 110;       // 3、只读成员函数可以修改mutable修饰的成员变量
        cout<<"b:"<<b<<endl;
    }

    void modify()
    {
        value = 120;
    }

private:
    int value;
    const int value1; // 4、只读成员变量只能在构造函数的初始化列表中赋值
    mutable int b;
};

class D
{
public:
	D(int _x = 100):x(_x) {}

	~D() {}
private:
	int x;
};


int main(int argc, char *argv[])
{
    A a1(12);
    A a2 = a1;

    a1.show();
    a2.show();

    cout<<"空类大小："<<sizeof(B)<<endl;

    C c1;
    c1.modify();
    c1.outPut();

    const C c2;
    //c2.modify(); 5、只读对象不能修改成员变量值
    c2.outPut();

    return 0;
}

