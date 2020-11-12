#include <iostream>
#include <memory>
using namespace std;

/**
 * @brief 使用auto类型声明定义lambda参数，会基于参数推导类型进行实例化
 */

int main(int argc, char * argv [ ])
{

    auto adder = [](auto op1, auto op2) { return op1 + op2; };
    int a = 100;
    int b = 100;

    int c = adder(a, b);
    cout<<c<<endl;

    // 解引用
    unique_ptr<int> p(new int);
    *p = 119;

    auto func = [p = move(p)]() { cout<<"inside："<<*p<<endl; };
    func();
    //cout<<"outside："<<*p<<endl;

    return 0;
}

