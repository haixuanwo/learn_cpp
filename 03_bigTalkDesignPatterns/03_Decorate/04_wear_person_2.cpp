/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-21 17:40:00
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 10:04:29
 * @Description: file content
 */

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person()
    {

    }

    Person(string name)
    {
        name_m = name;
    }

    virtual void show()
    {
        cout << "装扮的" << name_m << endl;
    }
private:
    string name_m;
};

class Finery : public Person
{
public:
    void decorate(Person *component)
    {
        component_m = component;
    }

    void show()
    {
        if (nullptr != component_m)
        {
            component_m->show();
        }
    }

private:
    Person *component_m;
};

class TShirts : public Finery
{
public:
    void show()
    {
        cout << "大T恤 ";
        Finery::show();
    }
};

class BigTrouser : public Finery
{
public:
    void show()
    {
        cout << "垮裤 ";
        Finery::show();
    }
};

class Sneakers : public Finery
{
public:
    void show()
    {
        cout << "破球鞋 ";
        Finery::show();
    }
};

class Suit : public Finery
{
public:
    void show()
    {
        cout << "西装 ";
        Finery::show();
    }
};

class Tie : public Finery
{
public:
    void show()
    {
        cout << "领带 ";
        Finery::show();
    }
};

class LeatherShoes : public Finery
{
public:
    void show()
    {
        cout << "皮鞋 ";
        Finery::show();
    }
};

int main()
{
    Person *xc = new Person("小菜");

    cout << "第一种装扮：" << endl;
    Sneakers *pqx = new Sneakers();
    BigTrouser *kk = new BigTrouser();
    TShirts* dtx = new TShirts();

    pqx->decorate(xc);
    kk->decorate(pqx);
    dtx->decorate(kk);
    dtx->show();

    cout << "第二种装扮：" << endl;
    LeatherShoes *px = new LeatherShoes();
    Tie *ld = new Tie();
    Suit* xz = new Suit();

    px->decorate(xc);
    ld->decorate(px);
    xz->decorate(ld);
    xz->show();

    cout << "第三种装扮：" << endl;
    Sneakers *pqx2 = new Sneakers();
    LeatherShoes *px2 = new LeatherShoes();
    BigTrouser* kk2 = new BigTrouser();
    Tie* ld2 = new Tie();

    pqx2->decorate(xc);
    px2->decorate(pqx2);
    kk2->decorate(px2);
    ld2->decorate(kk2);
    ld2->show();

    return 0;
}
