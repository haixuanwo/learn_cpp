#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char * argv [ ])
{
    // 1、遍历容器
    vector<int> V {1, 2, 3, 4, 5};
    for (auto v : V)
        cout<<v<<" ";
    cout<<endl;


    // 2、遍历列表
    for (int n : {1, 2, 3, 4, 5})
        cout<<n<<" ";
    cout<<endl;

    // 3、修改值
    for (auto &v : V)
        v++;

    for (auto v : V)
        cout<<v<<" ";
    cout<<endl;

    // 4、for 循环只能遍历有明确范围的一组数据，直接给指针会报错

    /*
       5、系统学过 STL 标准库的读者应该知道，基于关联式容器（包括哈希容器）底层存储机制的限制：
        不允许修改 map、unordered_map、multimap 以及 unordered_multimap 容器存储的键的值；
        不允许修改 set、unordered_set、multiset 以及 unordered_multiset 容器中存储的元素的值。
        切勿修改容器中不允许被修改的数据部分，否则会导致程序的执行出现各种 Bug
    */
    return 0;
}

