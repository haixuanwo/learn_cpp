
#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> &V)
{
	vector<int>::iterator it;
	for(it=V.begin(); it!=V.end(); it++)
		cout<<*it<<'\t';
	cout<<endl;
}

void showReverse(vector<int> &V)
{
	vector<int>::reverse_iterator it;
	for(it=V.rbegin(); it!=V.rend(); it++)
		cout<<*it<<'\t';
	cout<<endl;
}

void test1()
{
	vector<int> V1;
	V1.push_back(100); 			// 从头插入元素
	V1.push_back(200);
	V1.push_back(300);
	V1.push_back(400);
	show(V1);

	V1.pop_back();	   			// 从尾弹出元素
	show(V1);

	cout<<V1[0]<<endl;			// 下表获取元素

	vector<int> V2(V1.begin(), V1.end());
	show(V2);

	cout<<V2.front()<<endl;		// 返回第一个元素
	cout<<V2.back()<<endl;  	// 返回最后一个元素
}

void test2()
{
	vector<int> V1(5);			// 定义5个元素的容器
	cout<<V1.size()<<endl;

	V1.clear();					// 清空所有元素
	cout<<V1.size()<<endl;

	if(V1.empty())				// 是否为空
		cout<<"is empty"<<endl;
}

void test3()
{
	vector<int> V1;
	V1.insert(V1.begin(), 100); // 从头插入元素
	V1.insert(V1.begin(), 200);
	V1.insert(V1.begin(), 300);
	show(V1);

	//vector<int>::iterator it = find(V1.begin(), V1.end(), 200);
	//cout<<*it<<endl;

	vector<int> V2;
	V2.insert(V2.begin(), 400);
	V2.insert(V2.begin(), 500);
	V2.swap(V1);				// 交换V1与V2
	show(V1);
	show(V2);

	vector<int>::iterator it = V2.begin();
	V2.erase(it);
	show(V2);

	V1.erase(V1.begin(), V1.end());
	show(V1);
}

int main()
{
	test3();
	return 0;
}

