/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-06-19 16:41:05
 * @LastEditors: Clark
 * @LastEditTime: 2022-06-19 17:55:57
 * @Description: file content
 */

#include <vector>
#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

template <typename T>
static void show(vector<T> &v)
{
    for (auto &&i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

static void test1_shared_ptr()
{
    auto p = make_shared<vector<int>>(6, 6);
    show(*p);

    // p.get(); //返回智能指针保存的对象地址
    // p.unique()
    // p.reset() // 解引用，引用减一
    auto q = make_shared<vector<int>>();
    p.swap(q);  // 交换引用对象
    show(*q);

    cout<<"use count :"<<p.use_count()<<endl;

    auto x(q);
    show(*x);
}

static void test2_unique_ptr()
{
    std::unique_ptr<int> up(new int(100));

    cout<<*up<<endl;
}

static void test3_weak_ptr()
{
    auto p = make_shared<int>(100);
    std::weak_ptr<int> wp(p);
    cout<<wp.use_count()<<endl;
}

int main(int argc, char *argv[])
{
    // test1_shared_ptr();
    // test2_unique_ptr();
    test3_weak_ptr();

    return 0;
}
