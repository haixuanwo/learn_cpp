/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 16:05:30
 * @Description: file content
 */

#include "03_observer_2.h"

void StockObserver::update()
{
    cout << sub->get_action() << " " << name << " 关闭股票行情，继续工作！" << endl;
}

void NBAObserver::update()
{
    cout << sub->get_action() << " " << name << " 关闭NBA直播，继续工作！" << endl;
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

    Boss *huhansan = new Boss();
    Observer *tongshi3 = new StockObserver("魏关姹", huhansan);
    Observer *tongshi4 = new NBAObserver("易管查", huhansan);

    huhansan->attach(tongshi3);
    huhansan->attach(tongshi4);
    huhansan->detach(tongshi3);

    huhansan->set_action("我胡汉三回来了！");
    huhansan->notify();

    return 0;
}
