/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 14:16:51
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Player
{
public:
    Player(string name)
    {
        this->name = name;
    }

    virtual void attach() = 0;
    virtual void defense() = 0;

// private:
    string name;
};

class Forwards : public Player
{
public:
    Forwards(string name) : Player(name)
    {

    }

    void attach()
    {
        cout << "前锋：" << name << " 进攻" << endl;
    }

    void defense()
    {
        cout << "前锋：" << name << " 防守" << endl;
    }
};

class Center : public Player
{
public:
    Center(string name) : Player(name)
    {

    }

    void attach()
    {
        cout << "中锋：" << name << " 进攻" << endl;
    }

    void defense()
    {
        cout << "中锋：" << name << " 防守" << endl;
    }
};

class Guards : public Player
{
public:
    Guards(string name) : Player(name)
    {

    }

    void attach()
    {
        cout << "后卫：" << name << " 进攻" << endl;
    }

    void defense()
    {
        cout << "后卫：" << name << " 防守" << endl;
    }
};

int main()
{
    Player *b = new Forwards("巴蒂尔");
    b->attach();

    Player *m = new Guards("麦克格雷迪");
    m->attach();

    Player *ym = new Center("姚明");
    ym->attach();
    ym->defense();

    return 0;
}
