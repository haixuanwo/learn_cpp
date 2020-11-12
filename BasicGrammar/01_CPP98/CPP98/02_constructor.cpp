
#include <iostream>
using namespace std;

class CPerson
{
public:
	CPerson()
	{
		cout<<"structor 1"<<endl;
	}

	CPerson(int a)
	{
		cout<<"structor 2"<<endl;
	}

	~CPerson()
	{
		cout<<"~ structor"<<endl;
	}
};

int main(int argc, char * argv [ ])
{
	//CPerson P;	// 打印"structor 1"和"~ structor"

	//CPerson P1();	// 无打印,也就是说根本就没有在内存中创建对象，只是创建了一个“对象名”！只声明了对象，并没有实例化

	CPerson P2(2);	// 打印"structor 2"和"~ structor"
	
	return 0;
}

