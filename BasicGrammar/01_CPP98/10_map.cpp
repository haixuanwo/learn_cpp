#include <iostream>
#include <map>
using namespace std;

class CMP
{
public:
	bool operator ()(string s1, string s2)
	{
		return (s1 > s2);
	}
};

void show(map<int,char> &M)
{
	map<int,char>::iterator it;
	for(it=M.begin(); it!=M.end(); it++)
		cout<<(*it).first<<'\t'<<(*it).second<<endl;
}

void show2(map<string,int,CMP> &M)
{
	map<string,int,CMP>::iterator it;
	for(it=M.begin(); it!=M.end(); it++)
		cout<<(*it).first<<'\t'<<(*it).second<<endl;
}

static void test1()
{
	map<int,char> M1;
	M1.insert(pair<int,char>(21, 'a')); // 头部插入

	// map类的静态成员函数
	M1.insert(map<int,char>::value_type(10,'r'));

	M1[200] = 'e';						// 尾部插入
	M1[300] = 'f';
	show(M1);
}

static void test2()
{
	map<string,int,CMP> M1;
	M1["ABC"] = 12;		// 比较字符串，大的放前面
	M1["DEF"] = 24;
	M1["ABF"] = 24;
	show2(M1);

	// 返回插入元素
	pair<map<string,int>::iterator,bool> p = M1.insert(pair<string,int>("THF",1000));
	show2(M1);
}

static void test3()
{
	map<string,int,CMP> M1;
	M1["ABC"] = 12;
	M1["DEF"] = 24;
	M1["ABF"] = 24;
	show2(M1);

	map<string,int>::iterator it = M1.find("DEF");
	cout<<it->first<<'\t'<<it->second<<endl;

	M1.erase(it);	// 删除元素
	show2(M1);
}

void test4()
{
	map<string,int,CMP> M1;
	M1["ABC"] = 12;
	M1["DEF"] = 24;
	M1["ABF"] = 24;
	show2(M1);

	// 返回大于或等于key值第一个元素的位置
	map<string,int,CMP>::iterator it = M1.lower_bound("ABC");
	cout<<it->first<<'\t'<<it->second<<endl;

	// 返回小于key值第一个元素的位置
	it = M1.upper_bound("DEF");
	cout<<it->first<<'\t'<<it->second<<endl;
}

int main()
{
	test4();
	return 0;
}

