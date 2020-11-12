
#include <iostream>
#include <list>
using namespace std;

void show(list<int> &L)
{
	list<int>::iterator it;
	for (it=L.begin(); it!=L.end(); it++)
		cout<<*it<<'\t';
	cout<<endl;
}

void showReverse(list<int> &L)
{
	list<int>::reverse_iterator it;
	for (it=L.rbegin(); it!=L.rend(); it++)
		cout<<*it<<'\t';
	cout<<endl;
}


void test1()
{
	list<int> L1;
	L1.push_back(11);		// 放在容器后面
	L1.push_back(22);		// 放在容器后面
	L1.push_front(33);		// 放在容器前面
	L1.push_front(44);		// 放在容器前面
	show(L1);
	showReverse(L1);

	L1.reverse();			// 逆序元素
	show(L1);

	L1.remove(22);			// 删除一个元素
	show(L1);

	cout<<L1.back()<<endl;  // 取出最后一个元素
	cout<<L1.front()<<endl; // 取出第  一个元素

	L1.pop_back();			// 删除最后一个元素
	show(L1);
	L1.pop_front();			// 删除第一个元素
	show(L1);
}

void test2_swap()
{
	list<int> L1;
	list<int> L2;

	for (int i = 0; i < 5; i++)
	{
		L1.push_back(i);
		L2.push_back(i*10);
	}

	show(L1);
	show(L2);

	L1.swap(L2); // 交互两个链表
	show(L1);
	show(L2);
}

void test3_splice()
{
	list<int> L1;
	list<int> L2;

	for (int i = 0; i < 5; i++)
	{
		L1.push_back(i);
		L2.push_back(i*10);
	}

	// L2插入到L1的起始位置，L2中元素将删除
	L1.splice(L1.begin(), L2);
	show(L1);

	// L1取出第一个元素插入到L2的起始位置
	L2.splice(L2.begin(), L1, L1.begin());
	show(L1);
	show(L2);

	// L1中的所有元素插入到L2的起始位置
	L2.splice(L2.begin(), L1, L1.begin(), L1.end());
	show(L2);
}


void test4()
{
	list<int> L1;
	L1.push_back(22);
	L1.push_back(11);
	L1.push_back(33);
	L1.push_back(44);
	L1.push_back(33);
	show(L1);

	L1.sort();		// 排序元素
	show(L1);

	L1.unique();	// 去掉重复的元素
	show(L1);

	list<int> L2;
	L2.push_back(99);
	L2.push_back(99);
	L2.merge(L1);	// 合并L1到L2末尾处并删除L1中元素
	show(L2);
}


void test5()
{
	list<int> L1;
	L1.insert(L1.begin(), 100); // 插在最前面
	L1.insert(L1.begin(), 200);
	L1.insert(L1.begin(), 300);
	L1.insert(L1.begin(), 400);
	show(L1);

	list<int>::iterator it = L1.begin();
	L1.erase(it);
	show(L1);

	L1.erase(L1.begin(), L1.end());
	show(L1);
}

int main()
{
	test5();
	return 0;
}

