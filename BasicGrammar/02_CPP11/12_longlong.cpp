#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

// 有符号 long long "LL"或"ll" 如"10LL"
// 无符号 unsigned long long "ULL"或"ull"、"Ull"、"uLL" 如"10ULL"

// 如果不添加任何标识，则所有的整数都会默认为 int 类型。
int main(int argc, char * argv [ ])
{
    cout<<"long long最小值："<<LLONG_MIN<<" "<<hex<<LLONG_MIN<<"\n";
    cout<<dec<<"long long最大值："<<LLONG_MAX<<" "<<hex<<LLONG_MAX<<"\n";
    cout<<dec<<"unsigned long long最大值："<<ULLONG_MAX<<" "<<hex<<ULLONG_MAX;

    return 0;
}

