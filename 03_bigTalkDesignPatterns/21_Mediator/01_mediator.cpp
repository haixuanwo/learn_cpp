/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 11:53:32
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Colleague;
class Mediator
{
public:
    virtual void send(string message, Colleague *colleague) = 0;
};

class Colleague
{
public:
    Colleague(Mediator *mediator)
    {
        this->mediator = mediator;
    }

// private:
    Mediator *mediator;
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator *mediator) : Colleague(mediator)
    {

    }

    void send(string message)
    {
        mediator->send(message, this);
    }

    void notify(string message)
    {
        cout << "同事1得到消息：" << message << endl;
    }
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator *mediator) : Colleague(mediator)
    {

    }

    void send(string message)
    {
        mediator->send(message, this);
    }

    void notify(string message)
    {
        cout << "同事2得到消息：" << message << endl;
    }
};

class ConcreteMediator : public Mediator
{
public:

    void set_concrete_colleague1(ConcreteColleague1 *colleague1)
    {
        this->colleague1 = colleague1;
    }

    ConcreteColleague1 *get_concrete_colleague1()
    {
        return colleague1;
    }

    void set_concrete_colleague2(ConcreteColleague2 *colleague2)
    {
        this->colleague2 = colleague2;
    }

    ConcreteColleague2 *get_concrete_colleague2()
    {
        return colleague2;
    }

    void send(string message, Colleague *colleague)
    {
        if (colleague == colleague1)
        {
            colleague2->notify(message);
        }
        else
        {
            colleague1->notify(message);
        }
    }

private:
    ConcreteColleague1 *colleague1;
    ConcreteColleague2 *colleague2;
};

int main()
{
    ConcreteMediator *m = new ConcreteMediator();
    ConcreteColleague1 *c1 = new ConcreteColleague1(m);
    ConcreteColleague2 *c2 = new ConcreteColleague2(m);

    m->set_concrete_colleague1(c1);
    m->set_concrete_colleague2(c2);

    c1->send("吃过饭了吗？");
    c2->send("没有呢，你打算请客？");

    return 0;
}
