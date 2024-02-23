/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 15:16:23
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

class WorkExperience
{
public:
    void set_company(string company)
    {
        company_ = company;
    }

    void set_time_area(string timeArea)
    {
        timeArea_ = timeArea;
    }

    string get_company()
    {
        return company_;
    }

    string get_time_area()
    {
        return timeArea_;
    }

    WorkExperience *clone()
    {
        WorkExperience *we = new WorkExperience();
        we->set_company(company_);
        we->set_time_area(timeArea_);
        return we;
    }

private:
    string company_;
    string timeArea_;
};

class Resume
{
public:
    Resume(string name)
    {
        this->name = name;
        we = new WorkExperience();
    }
    // 设置个人信息
    void set_personal_info(string sex, string age)
    {
        this->sex = sex;
        this->age = age;
    }

    // 设置工作经历
    void set_work_experience(string timeArea, string company)
    {
        we->set_company(company);
        we->set_time_area(timeArea);
    }

    // 显示
    void display()
    {
        cout << "name: " << name << " sex: " << sex << " age: " << age << endl;
        cout << "工作经历： " << we->get_time_area() <<" "<< we->get_company() << endl;
    }

    Resume *clone()
    {
        Resume* resume = new Resume(name);
        resume->set_personal_info(sex, age);
        // resume->set_work_experience(we->get_time_area(), we->get_company());
        resume->we = we->clone(); // 内存泄漏
        return resume;
    }

    WorkExperience *we;

private:
    string name;
    string sex;
    string age;
};

int main()
{
    Resume *a = new Resume("大鸟");
    a->set_personal_info("男", "29");
    a->set_work_experience("1998-2000", "XX公司");

    Resume *b = a->clone();
    b->set_work_experience("1998-2006", "YY公司");

    Resume *c = a->clone();
    c->set_personal_info("男", "24");

    a->display();
    b->display();
    c->display();
    return 0;
}
