/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 12:58:34
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Country;
class UnitedNations
{
public:
    virtual void declare(string message, Country *colleague) = 0;
};

class Country
{
public:
    Country(UnitedNations *mediator)
    {
        this->mediator = mediator;
    }

// private:
    UnitedNations *mediator;
};

class USA : public Country
{
public:
    USA(UnitedNations *mediator) : Country(mediator)
    {

    }

    void declare(string message)
    {
        mediator->declare(message, this);
    }

    void get_message(string message)
    {
        cout << "美国获得对方信息：" << message << endl;
    }
};

class Iraq : public Country
{
public:
    Iraq(UnitedNations *mediator) : Country(mediator)
    {

    }

    void declare(string message)
    {
        mediator->declare(message, this);
    }

    void get_message(string message)
    {
        cout << "伊拉克获得对方信息：" << message << endl;
    }
};


class UnitedNationsSecurityCouncil : public UnitedNations
{
public:
    void set_colleague1(USA *colleague1)
    {
        this->colleague1 = colleague1;
    }

    USA *get_colleague1()
    {
        return colleague1;
    }

    void set_colleague2(Iraq *colleague2)
    {
        this->colleague2 = colleague2;
    }

    Iraq *get_colleague2()
    {
        return colleague2;
    }

    void declare(string message, Country *colleague)
    {
        if (colleague == colleague1)
        {
            colleague2->get_message(message);
        }
        else
        {
            colleague1->get_message(message);
        }
    }

private:
    USA *colleague1;
    Iraq *colleague2;
};


int main()
{
    UnitedNationsSecurityCouncil *UNSC = new UnitedNationsSecurityCouncil();

    USA *c1 = new USA(UNSC);
    Iraq *c2 = new Iraq(UNSC);

    UNSC->set_colleague1(c1);
    UNSC->set_colleague2(c2);

    c1->declare("不准研制核武器，否则发动战争！");
    c2->declare("我们没有核武器，也不怕侵略。");

    return 0;
}
