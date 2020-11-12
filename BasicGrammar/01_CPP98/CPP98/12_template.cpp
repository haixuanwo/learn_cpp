#include <iostream>
#define PI 3.14
using namespace std;

template<class T>
class Circle
{
public:
    Circle(T _r):r(_r) {}

    double getArea()
    {
        return PI*r*r;
    }

    double getLength()
    {
        return 2*r*PI;
    }

private:
    T r;
};


template<class T, class T1>
class A
{
public:
	A(T _a, T1 _b):a(_a),b(_b)
	{

	}

	void show()
	{
		cout<<a<<b<<endl;
	}
private:
	T a;
	T1 b;
};

int main(int argc, char *argv[])
{
	A<int, char> a(100, 'A');
	a.show();

    return 0;
}

