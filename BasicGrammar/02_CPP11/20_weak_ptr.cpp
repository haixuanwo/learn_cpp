#include <iostream>
#include <memory>
using namespace std;

// weak_ptr 类型指针并不会影响所指堆内存空间的引用计数，不能访问不能修改

/*
operator=()	重载 = 赋值运算符，是的 weak_ptr 指针可以直接被 weak_ptr 或者 shared_ptr 类型指针赋值。
swap(x)	其中 x 表示一个同类型的 weak_ptr 类型指针，该函数可以互换 2 个同类型 weak_ptr 指针的内容。
reset()	将当前 weak_ptr 指针置为空指针。
use_count()	查看指向和当前 weak_ptr 指针相同的 shared_ptr 指针的数量。
expired()	判断当前 weak_ptr 指针为否过期（指针为空，或者指向的堆内存已经被释放）。
lock()	如果当前 weak_ptr 已经过期，则该函数会返回一个空的 shared_ptr 指针；反之，该函数返回一个和当前 weak_ptr 指向相同的 shared_ptr 指针。
*/

int main(int argc, char * argv [ ])
{
    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2(sp1);
    shared_ptr<int> wp(sp2);

    cout<<wp.use_count()<<endl;

    sp2.reset();    // 释放
    cout<<wp.use_count()<<endl;


    return 0;
}

