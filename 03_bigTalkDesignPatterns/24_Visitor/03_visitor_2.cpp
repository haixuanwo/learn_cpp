/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-28 16:14:56
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Man;
class Woman;

class Action
{
public:
    virtual void get_man_conclusion(Man *concreteElementA) = 0;
    virtual void get_woman_conclusion(Woman *concreteElementB) = 0;
};

class Person
{
public:
    virtual void accept(Action *visitor) = 0;
};

class Man : public Person
{
public:
    void accept(Action *visitor)
    {
        /*
        双分派的技术，首先在客户程序中将具体状态作为参
        数传递给“男人”类完成了一次分派，然后“男人”类调用作为参数的“具体状态”中的方
        法“男人反应”，同时将自己（this）作为参数传递进去。这便完成了第二次分派
        */
        visitor->get_man_conclusion(this);
    }
};

class Woman : public Person
{
public:
    void accept(Action *visitor)
    {
        visitor->get_woman_conclusion(this);
    }
};



class Success : public Action
{
public:
    void get_man_conclusion(Man *concreteElementA)
    {
        cout << "男人成功时，背后多半有一个伟大的女人。" << endl;
    }

    void get_woman_conclusion(Woman *concreteElementB)
    {
        cout << "女人成功时，背后大多有一个不成功的男人。" << endl;
    }
};

class Fail : public Action
{
public:
    void get_man_conclusion(Man *concreteElementA)
    {
        cout << "男人失败时，闷头喝酒，谁也不用劝。" << endl;
    }

    void get_woman_conclusion(Woman *concreteElementB)
    {
        cout << "女人失败时，眼泪汪汪，谁也劝不了。" << endl;
    }
};

class Amativeness : public Action
{
public:
    void get_man_conclusion(Man *concreteElementA)
    {
        cout << "男人恋爱时，凡事不懂也要装懂。" << endl;
    }

    void get_woman_conclusion(Woman *concreteElementB)
    {
        cout << "女人恋爱时，遇事懂也装作不懂。" << endl;
    }
};

class ObjectStructure
{
public:
    void attach(Person *element)
    {
        elements.push_back(element);
    }

    void detach(Person *element)
    {
        list<Person *>::iterator itList;
        for (itList = elements.begin(); itList != elements.end();)
        {
            if (element ==  *itList)
            {
                itList = elements.erase( itList);
                break;
            }
            else
            {
                itList++;
            }
        }
    }

    void display(Action *visitor)
    {
        for (auto &&element : elements)
        {
            element->accept(visitor);
        }
    }

private:
    list<Person *> elements;
};


int main()
{
    ObjectStructure *o = new ObjectStructure();
    o->attach(new Man());
    o->attach(new Woman());

    // 成功时的反应
    Success *v1 = new Success();
    o->display(v1);

    // 失败时的反应
    Fail *v2 = new Fail();
    o->display(v2);

    // 恋爱时的反应
    Amativeness *v3 = new Amativeness();
    o->display(v3);

    return 0;
}
