/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-06-19 11:00:47
 * @LastEditors: Clark
 * @LastEditTime: 2022-06-19 16:03:06
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "time.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

template <typename T>
static void show(vector<T> &v)
{
    for (auto &&i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

static void test1_init()
{
    vector<int> v;
    vector<int> v1 = v;
    vector<int> v2(v1);
    vector<int> v0(10);

    cout<<"v empty["<<v.empty()<<"]"<<" size("<<v.size()<<")"<<endl;
    cout<<"v0 empty["<<v0.empty()<<"]"<<" size("<<v0.size()<<")"<<endl;
    cout<<"v1 empty["<<v1.empty()<<"]"<<" size("<<v1.size()<<")"<<endl;
    cout<<"v2 empty["<<v2.empty()<<"]"<<" size("<<v2.size()<<")"<<endl;

    vector<int> v3 = {1, 2, 3, 4, 5};
    for (auto &value : v3)
    {
         cout<<"v3 :"<<value<<endl;
    }

    vector<int> v4(5, 10);
    for (auto &value : v4)
    {
         cout<<"v4 :"<<value<<endl;
    }

    vector<int> v5 = v4;
    // for (vector<int>::size_type i = 0; i < v5.size(); i++)
    for (decltype(v5.size()) i = 0; i < v5.size(); i++)
    {
         cout<<"v5[i] :"<<v5[i]<<endl;
    }

    if (v4 == v5)
    {
        cout<<"v4 == v5"<<endl;
    }
    else
    {
        cout<<"v4 != v5"<<endl;
    }
    show(v4);
    show(v5);
}

static void test2_string()
{
    // vector<string> vs = {"tan"};
    vector<string> vs{"tan"};
    cout<<"vs :"<<vs[0]<<endl;

    vector<string> vs1{10};
    cout<<"vs1 empty["<<vs1.empty()<<"]"<<" size("<<vs1.size()<<")"<<endl;

    vector<string> vs2{10, "tan"};
    cout<<"vs2 empty["<<vs2.empty()<<"]"<<" size("<<vs2.size()<<")"<<endl;

    show(vs2);
}

static void test3_add_element()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    show(v);

    // for (size_t i = 0; i < 10; i++)
    // {
    //     v.push_front(i);
    // }
    // show(v);
}

static void test4_iterator()
{
    vector<int> v{1, 2, 3, 4, 5};

    // 迭代器
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // const迭代器
    for(auto it = v.cbegin(); it != v.cend(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // 逆序
    for(auto it = v.crbegin(); it != v.crend(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"end - begin = ["<<v.end() - v.begin()<<"]"<<endl;
}

static void test5_copy_swap()
{
    vector<int> v{1,2,3,4,5};
    vector<int> v1(5, 0);

    Time T;

    T.start_test_time();
    for (size_t i = 0; i < 2000*10000; i++)
    {
        std::swap(v, v1);
    }
    cout<<"swap cost :"<<T.get_diff_time()<<" ms"<<endl;

    show(v);
    show(v1);

    T.start_test_time();
    for (size_t i = 0; i < 2000*10000; i++)
    {
        std::copy(v.begin(), v.end(), v1.begin());  // 存放末尾不能超过最大元素
    }
    cout<<"copy cost :"<<T.get_diff_time()<<" ms"<<endl;
    show(v1);

    vector<int> v2;
    v2.swap(v1);
    show(v1);
    show(v2);
}

bool is_short(string &lhs, string &rhs)
{
    return lhs.size() > rhs.size();
}

static void test6_sort_unique()
{
    vector<string> vs{"tan", "hui", "fang", "tan", "xiao", "hai", "tan", "heng"};
    std::sort(vs.begin(), vs.end(), is_short);
    show(vs);

    std::sort(vs.begin(), vs.end());
    show(vs);

    vector<int> v{1, 10, 3, 4, 5, 6, 8, 5, 6, 7, 4,9, 2};
    std::sort(v.begin(), v.end());
    show(v);

    auto uniqueEnd = unique(v.begin(), v.end());
    show(v);
    v.erase(uniqueEnd, v.end());
    show(v);
}

static void test7_insert()
{
    /*
    1、插入单个元素
    iterator insert (iterator position, const value_type& val);

    2、插入n个同样元素
    void insert (iterator position, size_type n, const value_type& val);

    3、插入一个范围
    void insert (iterator position, InputIterator first, InputIterator last);
    */

    vector<int> v{1, 2, 3};
    v.insert(v.begin(), 4);
    v.insert(v.end(), 5);
    show(v);

    v.insert(v.end(), 6, 6);
    show(v);

    vector<int> v1{9, 8, 7};
    v.insert(v.end(), v1.begin(), v1.end());
    show(v);
}

static void test8_erase()
{
    // iterator erase (iterator position);
    // iterator erase (iterator first, iterator last);

    vector<int> v{1,2,3,4,5};
    v.erase(v.begin()+2);
    show(v);

    v.erase(v.begin()+1, v.end());
    show(v);
}

static void test9_resize()
{
    vector<int> v{1,2,3,4,5};
    v.resize(3);
    show(v);

    v.resize(10);
    show(v);
}

int main(int argc, char *argv[])
{
    // test1_init();
    // test2_string();
    // test3_add_element();
    // test4_iterator();
    // test5_copy_swap();
    // test6_sort();
    // test7_insert();
    // test8_erase();
    test9_resize();
    return 0;
}
