/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-21 17:40:00
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-21 17:56:55
 * @Description: file content
 */

#include <iostream>
#include <string>
using namespace std;

class Component
{
public:
    virtual void operation() = 0;
};

class ConcreteComponet : public Component
{
public:
     void operation()
     {
        cout << "具体对象的操作" << endl;
     }
};

class Decorator : public Component
{
public:
    void set_component(Component *component)
    {
        component_m = component;
    }

    void operation()
    {
        if (component_m)
        {
            component_m->operation();
        }
    }

private:
    Component *component_m;
};

class ConcreteDecoratorA : public Decorator
{
public:
    void operation()
    {
        Decorator::operation();
        addedState = "New State";
        cout << "具体装饰对象A的操作" << endl;
    }

private:
    string addedState;
};

class ConcreteDecoratorB : public Decorator
{
public:
    void operation()
    {
        Decorator::operation();
        added_behavior();
        cout << "具体装饰对象B的操作" << endl;
    }

    void added_behavior()
    {

    }
};

int main()
{
    ConcreteComponet *c = new ConcreteComponet();
    ConcreteDecoratorA *d1 = new ConcreteDecoratorA();
    ConcreteDecoratorB *d2 = new ConcreteDecoratorB();

    d1->set_component(c);
    d2->set_component(d1);
    d2->operation();

    return 0;
}
