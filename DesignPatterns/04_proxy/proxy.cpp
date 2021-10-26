/*
 * @Author: Clark (haixuanwoTxh@gmail.com)
 * @Date: 2021-10-26 12:05:59
 * @LastEditTime: 2021-10-26 12:16:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cplus-plus/DesignPatterns/04_proxy/proxy.cpp
 */

#include <iostream>
#include <string>
using namespace std;

class Girl
{
public:
    Girl(string _name)
    {
        name = _name;
    }

    string get_name()
    {
        return name;
    }

private:
    string name;
};

class Pursuit
{
public:
    Pursuit(Girl _girl):girl(_girl)
    {

    }

    void give_flower()
    {
        cout<<"give flower to "<<girl.get_name()<<endl;
    }

    void give_money()
    {
        cout<<"give money to "<<girl.get_name()<<endl;
    }

    void give_house()
    {
        cout<<"give ouse to "<<girl.get_name()<<endl;
    }
private:
    Girl girl;
};

class Proxy
{
public:
    Proxy(Girl girl):pursuit(girl)
    {

    }

    void give_flower()
    {
        pursuit.give_flower();
    }

    void give_money()
    {
        pursuit.give_money();
    }

    void give_house()
    {
        pursuit.give_house();
    }
private:
    Pursuit pursuit;
};

int main(int argc, char *argv[])
{
    Girl girl("lucy");
    Proxy proxy(girl);

    proxy.give_flower();
    proxy.give_house();
    proxy.give_money();

    return 0;
}
