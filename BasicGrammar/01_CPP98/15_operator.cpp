#include <iostream>
using namespace std;

class Complex
{
	friend ostream& operator <<(ostream& out, Complex &C);
	friend istream& operator >>(istream& in, Complex &C);
public:
	Complex(int _r = 0, int _i = 0):real(_r), image(_i) {}

	void show()
	{
		cout<<real<<"+"<<image<<"i"<<endl;
	}

	Complex operator +(Complex C)
	{
		Complex result;
		result.real = this->real + C.real;
		result.image = this->image + C.image;
		return result;
	}

	Complex operator -(Complex C)
	{
		Complex result;
		result.real = this->real - C.real;
		result.image = this->image - C.image;
		return result;
	}

	int operator ()(int x)
	{
		return x;
	}

	int operator [](int x)
	{
		return x;
	}

	bool operator == (Complex &C)
	{
		if (this->real == C.real && this->image == C.image)
			return true;
		else
			return false;
	}

	bool operator >(Complex &C)
	{
		return (this->real > C.real);
	}

	bool operator <(Complex &C)
	{
		return (this->real < C.real);
	}

	operator int() 					// 强制类型转换
	{
		return this->real;
	}

	Complex operator ++()			// 后置++
	{
		this->real += 1;
		this->image += 1;
		return (*this);
	}

	Complex operator ++(int a)	// 前置++
	{
		Complex C = *this;
		this->real += 1;
		this->image += 1;
		return C;
	}
private:
	int real;
	int image;
};

ostream& operator <<(ostream& out, Complex &C)
{
	out<<C.real<<'\t'<<C.image<<endl;
	return out;
}

istream& operator >>(istream& in, Complex &C)
{
	in>>C.real>>C.image;
	return in;
}

int main()
{
	Complex C1(1, 2);
	Complex C2(3, 4);
	Complex C3 = C1 + C2;
	C3.show();

	cout<<C3(1000)<<endl;
	cout<<C3[2000]<<endl;

	if (C1 == C1)
	{
		cout<<"C1 == C2"<<endl;
	}
	else
	{
		cout<<"C1 != C2"<<endl;
	}

	if (C1 > C2)
	{
		cout<<"C1 > C2"<<endl;
	}
	else
	{
		cout<<"C1 !> C2"<<endl;
	}

	cout<<(int)C1<<endl;
	cout<<"C1:"<<C1<<endl;

	Complex C4;
	cin>>C4;
	cout<<C4<<endl;
	++C4;
	cout<<C4<<endl;
	//cout<<C4++<<endl;
	return 0;
}

