#include <iostream>
using namespace std;

// 和声明左值引用一样，右值引用也必须立即初始化，且只能使用右值初始化
int main(int argc, char * argv [ ])
{
    int && a = 10;
    int num = 10;
    // int &&b  = num; // 编译错误
    return 0;
}

