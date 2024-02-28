/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-28 15:37:04
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Person
{
public:
    void set_action(string action)
    {
        this->action = action;
    }

    string get_action()
    {
        return action;
    }

    virtual void get_conclusion() = 0;

private:
    string action;
};

class Man : public Person
{
public:
    void get_conclusion()
    {
        if ("成功" == get_action())
        {
            cout << std::string(typeid(Man).name()).substr(1)
                << " " << get_action()
                << "时，背后多半有一个伟大的女人。" << endl;
        }
        else if ("失败" == get_action())
        {
            cout << std::string(typeid(Man).name()).substr(1)
                << " " << get_action()
                << "时，闷头喝酒，谁也不用劝。" << endl;
        }
        else if ("恋爱" == get_action())
        {
            cout << std::string(typeid(Man).name()).substr(1)
                << " " << get_action()
                << "时，凡事不懂也要装懂。" << endl;
        }
    }
};

class Woman : public Person
{
public:
    void get_conclusion()
    {
        if ("成功" == get_action())
        {
            cout << std::string(typeid(Woman).name()).substr(1)
                << " " << get_action()
                << "时，背后多半有一个不成功的男人。" << endl;
        }
        else if ("失败" == get_action())
        {
            cout << std::string(typeid(Woman).name()).substr(1)
                << " " << get_action()
                << "时，眼泪汪汪，谁也劝不了。" << endl;
        }
        else if ("恋爱" == get_action())
        {
            cout << std::string(typeid(Woman).name()).substr(1)
                << " " << get_action()
                << "时，遇事懂也装作不懂。" << endl;
        }
    }
};

int main()
{
    list<Person*> persons;

    Person *man1 = new Man();
    man1->set_action("成功");
    persons.push_back(man1);

    Person *woman1 = new Woman();
    woman1->set_action("成功");
    persons.push_back(woman1);

    Person *man2 = new Man();
    man2->set_action("失败");
    persons.push_back(man2);

    Person *woman2 = new Woman();
    woman2->set_action("失败");
    persons.push_back(woman2);

    Person *man3 = new Man();
    man3->set_action("恋爱");
    persons.push_back(man3);

    Person *woman3 = new Woman();
    woman3->set_action("恋爱");
    persons.push_back(woman3);

    for (auto &&person : persons)
    {
        person->get_conclusion();
    }

    return 0;
}
