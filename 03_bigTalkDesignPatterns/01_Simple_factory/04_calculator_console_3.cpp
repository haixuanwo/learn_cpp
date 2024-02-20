/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 09:33:53
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-20 11:28:46
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

    void set_A(double A)
    {
        _A = A;
    }

    double get_A()
    {
        return _A;
    }

    void set_B(double B)
    {
        _B = B;
    }

    double get_B()
    {
        return _B;
    }

    virtual double get_result()
    {
        return 0;
    }

    double _A;
    double _B;
};

class OperationAdd : public Operation
{
public:
    double get_result()
    {
        return _A + _B;
    }
};

class OperationSub : public Operation
{
public:
    double get_result()
    {
        return _A - _B;
    }
};

class OperationMul : public Operation
{
public:
    double get_result()
    {
        return _A * _B;
    }
};

class OperationDiv : public Operation
{
public:
    double get_result()
    {
        if (0 == _B)
        {
            throw -2;
        }

        return _A / _B;
    }
};

class OperationFactory
{
public:
    Operation* create_operation(char operate)
    {
        switch (operate)
        {
            case '+':
            {
                return new OperationAdd();
            }
            case '-':
            {
                return new OperationSub();
            }
            case '*':
            {
                return new OperationMul();

            }
            case '/':
            {
                return new OperationDiv();
            }
            default:
            {
                throw -1;
                break;
            }
        }
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

        OperationFactory factory;
        Operation *operation = factory.create_operation(operate);
        operation->set_A(A);
        operation->set_B(B);

        double result = operation->get_result();
        cout << "A["<<A<<"] + B["<<B<<"] = "<<result<<endl;
    }
    catch(int err)
    {
        cout << "您的输入有错！！！ ["<<err<<"]"<<endl;
    }

    return 0;
}
