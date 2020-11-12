#include <iostream>
using namespace std;

// C++98 不允许联合体的成员是非 POD 类型，但是 C++1 1 取消了这种限制。

/*
POD 类型一般具有以下几种特征（包括 class、union 和 struct等）：

1) 没有用户自定义的构造函数、析构函数、拷贝构造函数和移动构造函数。

2) 不能包含虚函数和虚基类。

3) 非静态成员必须声明为 public。

4) 类中的第一个非静态成员的类型与其基类不同

5) 在类或者结构体继承时，满足以下两种情况之一：
派生类中有非静态成员，且只有一个仅包含静态成员的基类；
基类有非静态成员，而派生类没有非静态成员

6) 所有非静态数据成员均和其基类也符合上述规则（递归定义），也就是说 POD 类型不能包含非 POD 类型的数据。

7) 此外，所有兼容C语言的数据类型都是 POD 类型（struct、union 等不能违背上述规则）。
*/


// C++11 删除了联合体不允许拥有静态成员的限制
union U{
    static int func()
    {
        int n = 3;
        return n;
    }
};


union V
{
    // 因为 string 类拥有自定义的构造函数，所以 U 的构造函数被删除；定义 U 的类型变量 u 需要调用默认构造函数，所以 u 也就无法定义成功
    string s;
    int n;
public:
    V() { new(&s) string; }
    ~V() { s.~string(); }
};


union W
{
    union {int x;}; // 此联合体为匿名联合体
};

int main(int argc, char * argv [ ])
{
    V v;
    return 0;
}

