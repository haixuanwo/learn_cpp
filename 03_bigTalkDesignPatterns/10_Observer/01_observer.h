/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 14:33:24
 * @Description: file content
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Secretary;

class StockObserver
{
public:
    StockObserver(string name, Secretary *sub);
    void update();

private:
    string name;
    Secretary *sub;
};

class Secretary
{
public:
    Secretary();

    void attach(StockObserver *observer);

    void notify();

    string get_action();

    void set_action(string action);

private:
    string action;
    list<StockObserver *> *observers;
};

#endif
