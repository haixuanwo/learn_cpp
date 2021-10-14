#include <iostream>
using namespace std;

int a = 100;

int main()
{
	int a = 119;

	cout<<"local:"<<a<<endl;
	cout<<"global:"<<::a<<endl;

	return 0;
}

