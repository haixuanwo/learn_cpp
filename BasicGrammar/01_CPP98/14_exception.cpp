#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout<<"fuck the exception A happened"<<endl;
	}
};

class B
{
public:
	B()
	{
		cout<<"fuck the exception B happened"<<endl;
	}
};

int fuck()
{
	if (1)
		throw A();	// 1、抛出异常
	else
		throw B();
}

int main(int argc, char * argv [ ])
{
	try
	{
		fuck();	// 2、捕获异常
	}
	catch(A a)	// 3、处理异常A
	{
		cout<<"deal with fuck A exception"<<endl;
	}
	catch(B a)	// 4、处理异常B
	{
		cout<<"deal with fuck B exception"<<endl;
	}

	return 0;
}
