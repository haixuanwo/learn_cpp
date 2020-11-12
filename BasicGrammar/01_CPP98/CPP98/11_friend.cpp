
/**
 *
 * 1、友元函数：friend 类型 函数名(形参);
 *	可直接访问类的私有成员
 *
 * 2、友元类：friend class 类名;
 *	可直接访问类的私有成员
 */

#include <iostream>
using namespace std;

class A
{
friend void show();
friend class B;

private:
	void func()
	{
		cout<<"A::func:"<<a<<endl;
	}

	int a;
};

class B
{
public:
	B()
	{
		A a;
		a.func();
		cout<<"B:a:"<<a.a<<endl;
	}
};

void show()
{
	A a;
	a.func();
	cout<<"show:a:"<<a.a<<endl;
}

int main()
{
	show();
	B b;
	return 0;
}

