/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 15:11:16
 * @Description: file content
 */

#include "02_observer_1.h"

Observer::Observer(string name, Secretary *sub)
{
    this->name = name;
    this->sub = sub;
}

StockObserver::StockObserver(string name, Secretary *sub) : Observer(name, sub)
{

}

void StockObserver::update()
{
    cout << sub->get_action() << " " << name << " 关闭股票行情，继续工作！" << endl;
}

NBAObserver::NBAObserver(string name, Secretary *sub) : Observer(name, sub)
{

}

void NBAObserver::update()
{
    cout << sub->get_action() << " " << name << " 关闭NBA直播，继续工作！" << endl;
}

Secretary::Secretary()
{
    observers = new list<Observer *>();
}

void Secretary::attach(Observer *observer)
{
    observers->push_back(observer);
}

void Secretary::detach(Observer *observer)
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
    Observer *tongshi1 = new StockObserver("魏关姹", tongzhizhe);
    Observer *tongshi2 = new NBAObserver("易管查", tongzhizhe);

    tongzhizhe->attach(tongshi1);
    tongzhizhe->attach(tongshi2);

    tongzhizhe->set_action("老板回来了！");
    tongzhizhe->notify();

    return 0;
}
