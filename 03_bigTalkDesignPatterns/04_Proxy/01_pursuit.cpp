/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 10:10:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 10:20:49
 * @Description: file content
 */

#include <string>
#include <iostream>
using namespace std;

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

class Pursuit
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

int main()
{
    SchoolGirl *jiaojiao = new SchoolGirl();
    jiaojiao->set_name("李娇娇");

    Pursuit *zhuojiayi = new Pursuit(jiaojiao);
    zhuojiayi->give_dolls();
    zhuojiayi->give_flowers();
    zhuojiayi->give_chocolate();

    return 0;
}
