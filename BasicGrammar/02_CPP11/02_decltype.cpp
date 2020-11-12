#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief decltype 根据表达式推导类型，          必须保证表达式的结果有类型，而不是void
 */

int func()
{
    return 120;
}

template <typename T>
class base{
public:
    void func(T &container){
        m_it = container.begin();
    }
private:
    decltype(T().begin()) m_it;
};

int main()
{
    // (1) 若exp被括号包围且为左值时，定义的为该类型的引用
    int a = 10;
    decltype((a)) b = a;

    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;

    b = 119;
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;

    // (2) 表达式为函数时，类型为其返回值类型
    decltype(func()) x = 120;
    cout<<"x = "<<x<<endl;

    // (3) 实际应用
    base<vector<int>> B;
    vector<int> V;
    B.func(V);

    return 0;
}

