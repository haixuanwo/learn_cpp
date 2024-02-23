

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name)
    {
        name_m = name;
    }

    void show()
    {
        cout << "装扮的" << name_m << endl;
    }
private:
    string name_m;
};

class Finery
{
public:
    virtual void show() = 0;
};

class TShirts : public Finery
{
public:
    void show()
    {
        cout << "大T恤 ";
    }
};

class BigTrouser : public Finery
{
public:
    void show()
    {
        cout << "垮裤 ";
    }
};

class Sneakers : public Finery
{
public:
    void show()
    {
        cout << "破球鞋 ";
    }
};

class Suit : public Finery
{
public:
    void show()
    {
        cout << "西装 ";
    }
};

class Tie : public Finery
{
public:
    void show()
    {
        cout << "领带 ";
    }
};

class LeatherShoes : public Finery
{
public:
    void show()
    {
        cout << "皮鞋 ";
    }
};

int main()
{
    Person *xc = new Person("小菜");

    cout << "第一种装扮：" << endl;

    Finery *dtx = new TShirts();
    Finery *kk = new BigTrouser();
    Finery *pqx = new Sneakers();

    dtx->show();
    kk->show();
    pqx->show();
    xc->show();

    cout << "第二种装扮：" << endl;
    Finery *xz = new Suit();
    Finery *ld = new Tie();
    Finery *px = new LeatherShoes();

    xz->show();
    ld->show();
    px->show();
    xc->show();

    return 0;
}
