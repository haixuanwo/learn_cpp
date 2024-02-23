

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

    void wear_Tshirts()
    {
        cout << "大T恤 ";
    }

    void wear_big_trouser()
    {
        cout << "垮裤 ";
    }

    void wear_sneakers()
    {
        cout << "破球鞋 ";
    }

    void wear_suit()
    {
        cout << "西装 ";
    }

    void wear_tie()
    {
        cout << "领带 ";
    }

    void wear_leather_shoes()
    {
        cout << "皮鞋 ";
    }

    void show()
    {
        cout << "装扮的" << name_m << endl;
    }
private:
    string name_m;
};

int main()
{
    Person *xc = new Person("小菜");

    cout << "第一种装扮：" << endl;
    xc->wear_Tshirts();
    xc->wear_big_trouser();
    xc->wear_sneakers();
    xc->show();

    cout << "第二种装扮：" << endl;
    xc->wear_suit();
    xc->wear_tie();
    xc->wear_leather_shoes();
    xc->show();
}
