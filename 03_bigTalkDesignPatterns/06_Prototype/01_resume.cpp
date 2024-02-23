/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 13:48:56
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

class Resume
{
public:
    Resume(string name)
    {
        this->name = name;
    }

    //设置个人信息
    void set_personal_info(string sex, string age)
    {
        this->sex = sex;
        this->age = age;
    }

    //设置工作经历
    void set_work_experience(string timeArea, string company)
    {
        this->timeArea = timeArea;
        this->company = company;
    }

    //显示
    void display()
    {
        cout << "name: " << name << " sex: " << sex << " age: " << endl;
        cout << "工作经历： " << timeArea <<" "<< company << endl;
    }

private:
    string name;
    string sex;
    string age;
    string timeArea;
    string company;
};

int main()
{
    Resume *a = new Resume("大鸟");
    a->set_personal_info("男", "29");
    a->set_work_experience("1998-2000", "XX公司");

    #if 0
    Resume *b = new Resume("大鸟");
    b->set_personal_info("男", "29");
    b->set_work_experience("1998-2000", "XX公司");

    Resume *c = new Resume("大鸟");
    c->set_personal_info("男", "29");
    c->set_work_experience("1998-2000", "XX公司");
    #else
    Resume *b = a;
    Resume *c = a;
    #endif

    a->display();
    b->display();
    c->display();
    return 0;
}
