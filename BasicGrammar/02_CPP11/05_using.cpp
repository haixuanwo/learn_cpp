#include <iostream>
#include <map>
using namespace std;

/**
 * typedef无法重定义一个模板
 * using 的别名语法覆盖了其全部功能
 */

template <typename Val>
using str_map_t = map<string, Val>;

//typedef void (*func_t)(int, int);
using func_t = void (*)(int, int);


int main(int argc, char * argv [ ])
{
    str_map_t<int> map1;
    return 0;
}

