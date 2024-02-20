/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 09:33:53
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-20 10:28:26
 * @Description: file content
 */


/*
请用C++、Java、C#或VB.NET任意一种面向对象语言实现一个计算器控制台程序，
要求输入两个数和运算符，得到结果
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "请输入数字A:" << endl;
    int A = 0;
    cin>>A;

    cout << "请选择运算符号(+、-、*、/):" << endl;
    char B = '0';
    cin>>B;

    cout << "请输入数字B:" << endl;
    int C = 0;
    cin>>C;

    int D = 0;

    if (B == '+')
    {
        D = A + C;
    }

    if (B == '-')
    {
        D = A - C;
    }

    if (B == '*')
    {
        D = A * C;
    }

    if (B == '/')
    {
        D = A / C;
    }

    cout << "A["<<A<<"] + B["<<B<<"] = "<<D<<endl;
    return 0;
}
