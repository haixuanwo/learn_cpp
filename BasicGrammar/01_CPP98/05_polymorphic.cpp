#include <iostream>
using namespace std;

class A
{
public:
	virtual void func()=0;	 //1、纯虚函数，此为虚类不能实例化。虚函数被子类重写

	virtual ~A()			 // 2、必须为虚析构才会调用子类析构函数
	{
		cout<<"A::disconstructor"<<endl;
	}
};

class B:public A
{
public:
	void func()
	{
		cout<<"B::func"<<endl;
	}

	~B()
	{
		cout<<"B::disconstructor"<<endl;
	}
};

class C:public A
{
public:
	void func()
	{
		cout<<"C::func"<<endl;
	}

	~C()
	{
		cout<<"C::disconstructor"<<endl;
	}
};

int main(int argc, char * argv [ ])
{
	A *a = NULL;

	if (1)
	{
		a = new B;
	}
	else
	{
		a = new C;
	}

	a->func();

	delete a;
}

