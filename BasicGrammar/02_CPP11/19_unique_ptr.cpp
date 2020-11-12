#include <iostream>
#include <memory>
using namespace std;

// unique_ptr 指针指向的堆内存无法同其它 unique_ptr 共享

/*
operator*()	获取当前 unique_ptr 指针指向的数据。
operator->()	重载 -> 号，当智能指针指向的数据类型为自定义的结构体时，通过 -> 运算符可以获取其内部的指定成员。
operator =()	重载了 = 赋值号，从而可以将 nullptr 或者一个右值 unique_ptr 指针直接赋值给当前同类型的 unique_ptr 指针。
operator []()	重载了 [] 运算符，当 unique_ptr 指针指向一个数组时，可以直接通过 [] 获取指定下标位置处的数据。
get()	获取当前 unique_ptr 指针内部包含的普通指针。
get_deleter()	获取当前 unique_ptr 指针释放堆内存空间所用的规则。
operator bool()	unique_ptr 指针可直接作为 if 语句的判断条件，以判断该指针是否为空，如果为空，则为 false；反之为 true。
release()	释放当前 unique_ptr 指针对所指堆内存的所有权，但该存储空间并不会被销毁。
reset(p)	其中 p 表示一个普通指针，如果 p 为 nullptr，则当前 unique_ptr 也变成空指针；反之，则该函数会释放当前 unique_ptr 指针指向的堆内存（如果有），然后获取 p 所指堆内存的所有权（p 为 nullptr）。
swap(x)	交换当前 unique_ptr 指针和同类型的 x 指针。
除此之外，C++11标准还支持同类型的 unique_ptr 指针之间，以及 unique_ptr 和 nullptr 之间，做 ==，!=，<，<=，>，>= 运算。
*/

int main(int argc, char * argv [ ])
{
    unique_ptr<int> p4(new int);
    //unique_ptr<int> p5(p4);//错误，堆内存不共享
    unique_ptr<int> p5(move(p4));//正确，调用移动构造函数

    int *p = p5.release();
    if (p5)
        cout<<"p5 is not nullptr"<<endl;
    else
        cout<<"p5 is nullptr"<<endl;

    unique_ptr<int> p6;
    p6.reset(p);
    cout<<*p6<<endl;

    return 0;
}

