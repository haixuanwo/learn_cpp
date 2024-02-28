/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 16:06:14
 * @Description: file content
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Subject;

class Observer
{
public:
    Observer(string name, Subject *sub)
    {
        this->name = name;
        this->sub = sub;
    }

    virtual void update() = 0;

    string name;
    Subject *sub;
};

class StockObserver : public Observer
{
public:
    StockObserver(string name, Subject *sub) : Observer(name, sub)
    {

    }

    void update();
};

class NBAObserver : public Observer
{
public:
    NBAObserver(string name, Subject *sub) : Observer(name, sub)
    {

    }

    void update();
};

//通知者接口
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

class Secretary : public Subject
{
public:
};

class Boss : public Subject
{
public:
};

#endif
