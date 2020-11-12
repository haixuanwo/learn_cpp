#include <iostream>
#include <set>
using namespace std;

static void show(set<int> &S)
{
	set<int>::iterator it;
	for (it=S.begin(); it!=S.end(); it++)
		cout<<*it<<'\t';
	cout<<endl;
}

static void test1()
{
	set<int> S1;
	S1.insert(100);			// 从尾部插入
	S1.insert(200);
	S1.insert(300);
	show(S1);

	pair<set<int>::iterator,bool> p = S1.insert(400);
	if (true == p.second)	// 返回插入结果
		cout<<*(p.first)<<endl;

	int times = S1.count(100); // 元素出现次数
	cout<<"times:"<<times<<endl;

	set<int>::iterator it = S1.find(200);	// 查找元素
	cout<<*it<<endl;

	S1.erase(it);	// 删除元素
	show(S1);

	cout<<"size:"<<S1.size()<<endl; // 元素个数

	set<int> S2;
	S1.swap(S2);	// 交换元素
	show(S2);

	//返回大于或等于指定值的第一个元素的位置
	//set<int>::iterator it=s1.lower_bound(70);

	//返回大于指定值的第一个元素的位置
	//set<int>::iterator it2=s1.upper_bound(60);

	//返回容器中等于指定值的元素的上下限位置
	//pair<set<int>::iterator,set<int>::iterator>p1=s1.equal_range(50);
}

int main()
{
	test1();
	return 0;
}

