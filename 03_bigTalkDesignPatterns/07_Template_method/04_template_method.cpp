/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 15:50:08
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

class AbstractClass
{
public:
    virtual void primitive_operation1() = 0;
    virtual void primitive_operation2() = 0;

    void template_method()
    {
        primitive_operation1();
        primitive_operation2();
    }
};

class ConcreteClassA : public AbstractClass
{
public:
    void primitive_operation1()
    {
        cout << "具体类A方法1实现" << endl;
    }

    void primitive_operation2()
    {
        cout << "具体类A方法2实现" << endl;
    }
};

class ConcreteClassB : public AbstractClass
{
public:
    void primitive_operation1()
    {
        cout << "具体类B方法1实现" << endl;
    }

    void primitive_operation2()
    {
        cout << "具体类B方法2实现" << endl;
    }
};

int main(int argc, char *argv[])
{
    AbstractClass *c = new ConcreteClassA();
    c->template_method();

    c = new ConcreteClassB();
    c->template_method();

    return 0;
}
