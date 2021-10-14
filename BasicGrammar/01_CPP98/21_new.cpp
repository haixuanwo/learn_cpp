#include <iostream>
using namespace std;

int main()
{
	int *p = new int[10];
	delete []p;


	char *q = new char;
	delete q;

	return 0;
}

