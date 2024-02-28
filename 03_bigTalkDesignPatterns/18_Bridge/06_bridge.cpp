/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 23:57:26
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Implementor
{
public:
    virtual void operation() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
    void operation()
    {
        cout << "具体实现A的方法执行" << endl;
    }
};

class ConcreteImplementorB : public Implementor
{
public:
    void operation()
    {
        cout << "具体实现B的方法执行" << endl;
    }
};

class Abstraction
{
public:
    void set_implementor(Implementor *implementor)
    {
        this->implementor = implementor;
    }

    virtual void operation()
    {
        implementor->operation();
    }

// private:
    Implementor *implementor;
};

class RefinedAbstraction : public Abstraction
{
public:
    void operation()
    {
        implementor->operation();
    }
};

int main()
{
    Abstraction *ab = new RefinedAbstraction();
    ab->set_implementor(new ConcreteImplementorA());
    ab->operation();

    ab->set_implementor(new ConcreteImplementorB());
    ab->operation();

    return 0;
}
