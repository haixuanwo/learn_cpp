#include <iostream>
using namespace std;

namespace name1
{
	static void show()
	{
		cout<<"I'm name1"<<endl;
	}
}

namespace name2
{
	static void show()
	{
		cout<<"I'm name2"<<endl;
	}
}

int main()
{
	name1::show();
	name2::show();
	return 0;
}

