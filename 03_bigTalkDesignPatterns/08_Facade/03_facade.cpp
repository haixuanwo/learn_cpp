/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 15:57:20
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

class SubSystemOne
{
public:
    void method_one()
    {
        cout << " 子系统方法一" << endl;
    }
};

class SubSystemTwo
{
public:
    void method_two()
    {
        cout << " 子系统方法二" << endl;
    }
};

class SubSystemThree
{
public:
    void method_three()
    {
        cout << " 子系统方法三" << endl;
    }
};

class SubSystemFour
{
public:
    void method_four()
    {
        cout << " 子系统方法四" << endl;
    }
};

class Facade
{
public:
    Facade()
    {
        one = new SubSystemOne();
        two = new SubSystemTwo();
        three = new SubSystemThree();
        four = new SubSystemFour();
    }

    void method_A()
    {
        cout << "method_A --- " << endl;
        one->method_one();
        two->method_two();
        four->method_four();
    }

    void method_B()
    {
        cout << "method_B --- " << endl;
        two->method_two();
        three->method_three();
    }

private:
    SubSystemOne *one;
    SubSystemTwo *two;
    SubSystemThree *three;
    SubSystemFour *four;
};

int main()
{
    Facade *facade = new Facade();
    facade->method_A();
    facade->method_B();

    return 0;
}
