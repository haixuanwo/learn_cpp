/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 16:51:52
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Observer
{
public:
    virtual void update() = 0;
};

class Subject
{
public:
    Subject()
    {
        observers = new list<Observer *>();
    }

    void attach(Observer *observer)
    {
        observers->push_back(observer);
    }

    void detach(Observer *observer)
    {
        list<Observer *>::iterator itList;

        for (itList = observers->begin(); itList != observers->end();)
        {
            if (observer ==  *itList)
            {
                itList = observers->erase( itList);
                break;
            }
            else
            {
                itList++;
            }
        }
    }

    void notify()
    {
        for (auto &&observer : *observers)
        {
            observer->update();
        }
    }

    string get_state()
    {
        return state;
    }

    void set_state(string state)
    {
        this->state = state;
    }

    string get_action()
    {
        return action;
    }

    void set_action(string action)
    {
        this->action = action;
    }

private:
    string state;
    string action;
    list<Observer *> *observers;
};

class ConcreteSubject : public Subject
{
public:
    void set_state(string state)
    {
        this->state = state;
    }

    string set_state()
    {
        return state;
    }

private:
    string state;
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject *subject, string name)
    {
        this->subject = subject;
        this->name = name;
    }

    void update()
    {
        state = subject->get_state();
        cout << "观察者" << name << "的新状态是"<< state << endl;
    }

private:
    string name;
    string state;
    Subject *subject;
};

int main()
{
    Subject *cs = new ConcreteSubject();
    cs->attach(new ConcreteObserver(cs, "X"));
    cs->attach(new ConcreteObserver(cs, "Y"));
    cs->attach(new ConcreteObserver(cs, "Z"));
    cs->set_state("ABC");
    cs->notify();

    return 0;
}
