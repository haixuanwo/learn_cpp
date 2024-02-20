/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 09:33:53
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-20 11:07:11
 * @Description: file content
 */


/*
请用C++、Java、C#或VB.NET任意一种面向对象语言实现一个计算器控制台程序，
要求输入两个数和运算符，得到结果
*/

#include <iostream>
using namespace std;

class Operation
{
public:
    static double get_result(double A, double B, char operate)
    {
        double result = 0;
        switch (operate)
        {
            case '+':
            {
                result = A + B;
                break;
            }
            case '-':
            {
                result = A - B;
                break;
            }
            case '*':
            {
                result = A * B;
                break;
            }
            case '/':
            {
                result = A / B;
                break;
            }
            default:
            {
                throw -1;
                break;
            }
        }

        return result;
    }
};

int main()
{
    try
    {
        cout << "请输入数字A:" << endl;
        double A = 0;
        cin>>A;

        cout << "请选择运算符号(+、-、*、/):" << endl;
        char operate = '0';
        cin>>operate;

        cout << "请输入数字B:" << endl;
        double B = 0;
        cin>>B;

        double result = Operation::get_result(A, B, operate);

        cout << "A["<<A<<"] + B["<<B<<"] = "<<result<<endl;
    }
    catch(int err)
    {
        cout << "您的输入有错！！！ ["<<err<<"]"<<endl;
    }

    return 0;
}
