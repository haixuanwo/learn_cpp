#include <iostream>
#include <set>
using namespace std;

static void show(multiset<int> &MS)
{
	multiset<int>::iterator it;
	for (it=MS.begin(); it!=MS.end(); it++)
		cout<<*it<<'\t';
	cout<<endl;
}

static void test()
{
	multiset<int> MS;
	MS.insert(100);					// 尾部插入
	MS.insert(200);
	MS.insert(300);
	MS.insert(400);
	show(MS);

	int count = MS.count(200);
	cout<<"count:"<<count<<endl;	// 统计出现次数

	multiset<int>::iterator it = MS.find(300);
	cout<<*it<<endl;				// 查找元素

	MS.erase(it);					// 删除元素
	show(MS);

	cout<<"size:"<<MS.size()<<endl;	// 元素数量

	multiset<int> MS1;
	MS.swap(MS1);					// 交换元素
	show(MS1);

	//返回大于或等于指定值的第一个元素的位置
	//set<int>::iterator it=s1.lower_bound(50);

	//返回大于指定值的第一个元素的位置
	//set<int>::iterator it2=s1.upper_bound(50);

	//返回容器中等于指定值的元素的上下限位置
	//pair<set<int>::iterator,set<int>::iterator>p1=s1.equal_range(50);

}

int main()
{
	test();
	return 0;
}

