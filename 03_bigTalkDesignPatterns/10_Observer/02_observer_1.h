/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 15:12:13
 * @Description: file content
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Secretary;

class Observer
{
public:
    Observer(string name, Secretary *sub);
    virtual void update() = 0;

    string name;
    Secretary *sub;
};

class StockObserver : public Observer
{
public:
    StockObserver(string name, Secretary *sub);
    void update();
};

class NBAObserver : public Observer
{
public:
    NBAObserver(string name, Secretary *sub);
    void update();
};

class Secretary
{
public:
    Secretary();

    void attach(Observer *observer);

    void detach(Observer *observer);

    void notify();

    string get_action();

    void set_action(string action);

private:
    string action;
    list<Observer *> *observers;
};

#endif
