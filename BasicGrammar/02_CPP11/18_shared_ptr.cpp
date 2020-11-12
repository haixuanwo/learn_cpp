#include <iostream>
#include <memory>
using namespace std;

/*
内存问题
1、使用已释放内存
2、重复释放
3、内存泄漏
*/

/*
引用计数:
智能指针在申请堆内存空间的同时，会为其配备一个整形值（初始值为 1），每当有新对象使用此堆内存时，
该整形值 +1；反之，每当使用此堆内存的对象被释放时，该整形值减 1。当堆空间对应的整形值为 0 时，
即表明不再有对象使用它，该堆空间就会被释放掉

*/

/*
operator=()	    重载赋值号，使得同一类型的 shared_ptr 智能指针可以相互赋值。
operator*()	    重载 * 号，获取当前 shared_ptr 智能指针对象指向的数据。
operator->()	重载 -> 号，当智能指针指向的数据类型为自定义的结构体时，通过 -> 运算符可以获取其内部的指定成员。
swap()	        交换 2 个相同类型 shared_ptr 智能指针的内容。
reset()	        当函数没有实参时，该函数会使当前 shared_ptr 所指堆内存的引用计数减 1，同时将当前对象重置为一个空指针；当为函数传递一个新申请的堆内存时，则调用该函数的 shared_ptr 对象会获得该存储空间的所有权，并且引用计数的初始值为 1。
get()	        获得 shared_ptr 对象内部包含的普通指针。
use_count()	    返回同当前 shared_ptr 对象（包括它）指向相同的所有 shared_ptr 对象的数量。
unique()	    判断当前 shared_ptr 对象指向的堆内存，是否不再有其它 shared_ptr 对象再指向它。
operator bool()	判断当前 shared_ptr 对象是否为空智能指针，如果是空指针，返回 false；反之，返回 true。
*/
int main(int argc, char * argv [ ])
{
    shared_ptr<int> p1(new int(10));
    shared_ptr<int> p2(p1);
    cout<<*p2<<endl;

    p1.reset(); // 引用计数减一，p1为空指针
    if (p1)
    {
        cout<<"p1不为空"<<endl;
    }
    else
    {
        cout<<"p1为空"<<endl;
    }

    // 以上操作不影响p2
    cout<<*p2<<endl;
    cout<<p2.use_count()<<endl;

    // 自定义释放规则
    std::shared_ptr<int> p6(new int[10], std::default_delete<int[]>());

    return 0;
}

