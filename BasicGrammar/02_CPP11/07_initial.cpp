#include <iostream>
#include <vector>
using namespace std;

// 1、C++98/03
int i_arr[3] = {1, 2, 3};

struct A
{
    int x;
    struct B
    {
        int i;
        int j;
    }b;
}a = {1, {2, 3}};

class Foo
{
public:
    Foo(int) {}
}foo = 123;


// 2、C++11中初始化列表可用于任何类型对象的初始化

int main(int argc, char * argv [ ])
{
    int j(0);
    Foo bar(123);
    return 0;

    Foo c = {111};
    int array[3] {1, 2, 3}; // 可不适用等号

    int *a = new int{111};
    double b = double{12.12};
    int *arr = new int[3] {1, 2, 3};

    vector<int> V = {1, 2, 3, 4, 5};


}

