
#include <iostream>
#include <string.h>
using namespace std;

/**
 * @brief 浅拷贝
 */
class CShallowCopy
{
public:
	CShallowCopy(int _len)
	{
		p = new int[_len];
		len = _len;
		memset(p, 0, len);
	}

	CShallowCopy(CShallowCopy &c)
	{
		p 	= c.p;
		len = c.len;
	}

	~CShallowCopy()
	{
		if (p)
		{
			delete p; // 浅拷贝导致一个地址在多处释放
			p = NULL;
		}
	}

private:
	int *p;
	int len;
};


/**
 * @brief 深拷贝
 */
class CDeepCopy
{
public:
	CDeepCopy(int _len)
	{
		p = new int[_len];
		len = _len;
	}

	CDeepCopy(CDeepCopy &c)
	{
		p 	= new int[c.len];
		len = c.len;
		memcpy(p, c.p, len);
	}

	CDeepCopy()
	{
		if (p)
		{
			delete p;
			p = NULL;
		}
	}

private:
	int *p;
	int len;
};

int main()
{
	CShallowCopy sc(100);
	// CShallowCopy sc1(sc);	报错double free or corruption

	CDeepCopy dc(100);
	CDeepCopy dc1(dc);
	return 0;
}

