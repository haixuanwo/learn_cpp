#include <iostream>
using namespace std;

/**
 * expicit关键字只能修饰只有一个参数的构造函数或其他都是默认值
 * implicit显式，默认
 *
 * 1、A a=1,编译时有一个缺省的转换操作，将整型转换为A类对象
 */

class A
{
public:
	A()
	{
		cout<<"default constructor"<<endl;
	}

	explicit A(int num)
	{
		cout<<"num:"<<num<<endl;
	}
};

int main(int argc, char * argv [ ])
{
	A a;
	//A a1 = 1;  // 不允许

	return 0;
}

