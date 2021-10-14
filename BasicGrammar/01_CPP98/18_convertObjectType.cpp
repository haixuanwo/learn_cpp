
#include <iostream>
using namespace std;

class Convert
{
public:

    Convert()
    {
        data = 500;
        p = "tanhuifang";
    }

    // 强制类型转换为int
    operator int()
    {
        return data;
    }

	// 强制类型转换为const char*
    operator const char*()
    {
		return p;
	}

private:
    int data;
    const char *p;
};

int main()
{
    Convert c;

    cout<<(int)c<<endl;
    cout<<(const char*)c<<endl;
    return 0;
}

