#include <iostream>
using namespace std;


// 1、实现返回后置类型，但写法晦涩代码可读性差
template <typename T, typename U>
decltype((*(T*)0) + (*(U*)0)) add(T t, U u)
{
    return t + u;
}


// 2、使用auto和decltype结合实现
template <typename T, typename U>
auto add_(T t, U u)->decltype(t + u)
{
    return t + u;
}

int main(int argc, char * argv [ ])
{
    auto value = add<int, int>(100, 100);
    cout<<"value = "<<value<<endl;

    auto value_ = add_<int, int>(200, 200);
    cout<<"value_ = "<<value_<<endl;
    return 0;
}

