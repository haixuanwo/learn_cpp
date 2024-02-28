/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-26 16:10:25
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 16:37:36
 * @Description: file content
 */
/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 16:24:10
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Company
{
public:
    Company(string name)
    {
        this->name = name;
    }

    void set_name(string name)
    {
        this->name = name;
    }

    string get_name()
    {
        return name;
    }

    virtual void add(Company *c) = 0;
    virtual void remove(Company *c) = 0;
    virtual void display(int depth) = 0;
    virtual void line_of_duty() = 0;

// private:
    string name;
};

class ConcreteCompany : public Company
{
public:
    ConcreteCompany(string name) : Company(name)
    {
        children = new list<Company *>();
    }

    void add(Company *c)
    {
        children->push_back(c);
    }

    void remove(Company *c)
    {
        list<Company *>::iterator itList;
        for (itList = children->begin(); itList != children->end();)
        {
            if (c ==  *itList)
            {
                itList = children->erase( itList);
                break;
            }
            else
            {
                itList++;
            }
        }
    }

    // 实现树各层的递归
    void display(int depth)
    {
        cout << "name: " << name << " depth: " << depth << endl;

        for (auto &&company : *children)
        {
            company->display(depth + 2);
        }
    }

    void line_of_duty()
    {
        for (auto &&Company : *children)
        {
            Company->line_of_duty();
        }
    }

private:
    list<Company *> *children;
};

class HRDepartment : public Company
{
public:
    HRDepartment(string name) : Company(name)
    {
    }

    void add(Company *c)
    {
    }

    void remove(Company *c)
    {

    }

    // 实现树各层的递归
    void display(int depth)
    {
        cout << "name: " << name << " depth: " << depth << endl;
    }

    void line_of_duty()
    {
        cout << "name: " << name << " 员工招聘培训管理 " << endl;
    }
};

class FinanceDepartment : public Company
{
public:
    FinanceDepartment(string name) : Company(name)
    {
    }

    void add(Company *c)
    {
    }

    void remove(Company *c)
    {

    }

    // 实现树各层的递归
    void display(int depth)
    {
        cout << "name: " << name << " depth: " << depth << endl;
    }

    void line_of_duty()
    {
        cout << "name: " << name << " 公司财务收支管理 " << endl;
    }
};

int main()
{
    ConcreteCompany *root = new ConcreteCompany("北京总公司");
    root->add(new HRDepartment("总公司人力资源部"));
    root->add(new FinanceDepartment("总公司财务部"));

    ConcreteCompany *comp = new ConcreteCompany("上海华东公司");
    comp->add(new HRDepartment("华东分公司人力资源部"));
    comp->add(new FinanceDepartment("华东分公司财务部"));
    root->add(comp);

    ConcreteCompany *comp1 = new ConcreteCompany("南京办事处");
    comp1->add(new HRDepartment("南京办事处人力资源部"));
    comp1->add(new FinanceDepartment("南京办事处财务部"));
    comp->add(comp1);

    ConcreteCompany *comp2 = new ConcreteCompany("杭州办事处");
    comp2->add(new HRDepartment("杭州办事处人力资源部"));
    comp2->add(new FinanceDepartment("杭州办事处财务部"));
    comp->add(comp2);

    cout << "结构图：" << endl;
    root->display(1);

    cout << "职责：" << endl;
    root->line_of_duty();

    return 0;
}
