/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 14:36:53
 * @Description: file content
 */

#include "01_observer.h"

StockObserver::StockObserver(string name, Secretary *sub)
{
    this->name = name;
    this->sub = sub;
}

void StockObserver::update()
{
    cout << sub->get_action() << " " << name << " 关闭股票行情，继续工作！" << endl;
}

Secretary::Secretary()
{
    observers = new list<StockObserver *>();
}

void Secretary::attach(StockObserver *observer)
{
    observers->push_back(observer);
}

void Secretary::notify()
{
    for (auto &&observer : *observers)
    {
        observer->update();
    }
}

string Secretary::get_action()
{
    return action;
}

void Secretary::set_action(string action)
{
    this->action = action;
}

int main()
{
    Secretary *tongzhizhe = new Secretary();
    StockObserver *tongshi1 = new StockObserver("魏关姹", tongzhizhe);
    StockObserver *tongshi2 = new StockObserver("易管查", tongzhizhe);

    tongzhizhe->attach(tongshi1);
    tongzhizhe->attach(tongshi2);

    tongzhizhe->set_action("老板回来了！");
    tongzhizhe->notify();

    return 0;
}
