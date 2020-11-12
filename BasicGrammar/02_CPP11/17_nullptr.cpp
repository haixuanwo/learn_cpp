#include <iostream>
using namespace std;

// #define NULL 0
// 在整型和指针的重载函数时，NULL还是会按整型处理

// nullptr 是 nullptr_t 类型的右值常量，专用于初始化空类型指针
#include <iostream>
using namespace std;

void isnull(void *c)
{
    cout << "void*c" << endl;
}

void isnull(int n)
{
    cout << "int n" << endl;
}

int main()
{
    // isnull(NULL); 编译不过
    isnull(nullptr);
    return 0;
}


