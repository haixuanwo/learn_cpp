#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 返回值类型推导
 */

auto func()
{
    vector<int> *V = new vector<int>;
    V->push_back(100);
    return V;
}

int main(int argc, char * argv [ ])
{
    auto v = func();
    cout<<v->front()<<endl;
    return 0;
}

