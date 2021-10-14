/**
 * 1、派生类继承了基类所有非私有方法和变量，除构造函数、析构函数、重载运算符、友元
 *
 * 2、公有继承：继承公有和保护成员且属性不变
 * 3、保护继承：继承公有和保护成员且属性都为保护
 * 4、私有继承：继承公有和保护成员且属性都为私有
 *
 * 5、多继承：可继承多个父类，不同父类中有相同函数时需用父类名
 * 6、虚继承：在创建对象时会创建一个虚表，解决环状继承问题
 *
 * 7、先构造基类再构造派生类
 * 8、多继承按继承顺序构造
 */

#include <iostream>
using namespace std;

class base
{
public:
	int value;
};

class A:virtual public base
{
public:
	A()
	{

	}

	void func()
	{
		cout<<"A::func"<<endl;
	}
};


class B:virtual public base
{
public:
	B()
	{

	}

	void func()
	{
		cout<<"B::func"<<endl;
	}
};


class C:public A, public B
{
public:
	C()
	{

	}
};


int main()
{
	C c;
	// c.func();
	c.A::func();

	c.value = 110;
	cout<<"value:"<<c.value<<endl;
	return 0;
}

