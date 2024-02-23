/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 10:10:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 10:30:51
 * @Description: file content
 */

#include <string>
#include <iostream>
using namespace std;

class IGiveGift
{
public:
    virtual void give_dolls() = 0;
    virtual void give_flowers() = 0;
    virtual void give_chocolate() = 0;
};

class SchoolGirl
{
public:
    string get_name()
    {
        return name_m;
    }

    void set_name(string name)
    {
        name_m = name;
    }
private:
    string name_m;
};

class Pursuit : public IGiveGift
{
public:
    Pursuit(SchoolGirl *mm)
    {
        mm_m = mm;
    }

    void give_dolls()
    {
        cout << mm_m->get_name() << " 送你洋娃娃" << endl;
    }

    void give_flowers()
    {
        cout << mm_m->get_name() << " 送你鲜花" << endl;
    }

    void give_chocolate()
    {
        cout << mm_m->get_name() << " 送你巧克力" << endl;
    }

private:
    SchoolGirl *mm_m;
};

class Proxy : public IGiveGift
{
public:
    Proxy(SchoolGirl *mm)
    {
        gg = new Pursuit(mm);
    }

    void give_dolls()
    {
        gg->give_dolls();
    }

    void give_flowers()
    {
         gg->give_flowers();
    }

    void give_chocolate()
    {
        gg->give_chocolate();
    }

private:
    Pursuit *gg;
};

int main()
{
    SchoolGirl *jiaojiao = new SchoolGirl();
    jiaojiao->set_name("李娇娇");

    Proxy *daili = new Proxy(jiaojiao);
    daili->give_dolls();
    daili->give_flowers();
    daili->give_chocolate();

    return 0;
}
