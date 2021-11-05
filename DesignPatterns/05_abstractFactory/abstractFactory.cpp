/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-05 16:29:10
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-05 18:30:02
 * @Description: file content
 */

#include <iostream>
using namespace std;

/**
 * @brief 具体工厂里不同的函数生产不同的产品
 */

class Fruit
{
public:
    virtual void show() = 0;
};


class RedFruit:public Fruit
{
public:
    void show()
    {
        cout<<"red fruit"<<endl;
    }
};

class GreenFruit:public Fruit
{
public:
    void show()
    {
        cout<<"Green fruit"<<endl;
    }
};

class Vagetable
{
public:
    virtual void show() = 0;
};

class RedVagetable:public Vagetable
{
public:
    void show()
    {
        cout<<"red Vagetable"<<endl;
    }
};

class GreenVagetable:public Vagetable
{
public:
    void show()
    {
        cout<<"Green Vagetable"<<endl;
    }
};

class AbFactory
{
public:
    virtual Fruit *get_fruit() = 0;
    virtual Vagetable *get_vagetable() = 0;
};

class RedFactory:public AbFactory
{
public:
    Fruit *get_fruit()
    {
        return new RedFruit;
    }

    Vagetable *get_vagetable()
    {
        return new RedVagetable;
    }
};

class GreenFactory:public AbFactory
{
public:
    Fruit *get_fruit()
    {
        return new GreenFruit;
    }

    Vagetable *get_vagetable()
    {
        return new GreenVagetable;
    }
};

int main()
{

    // 红色工厂
    AbFactory *redAf = new RedFactory;

    Fruit *redFruit = redAf->get_fruit();
    redFruit->show();

    Vagetable *redVagetable = redAf->get_vagetable();
    redVagetable->show();

    // 绿色工厂
    AbFactory *greenAf = new GreenFactory;

    Fruit *greenFruit = greenAf->get_fruit();
    greenFruit->show();

    Vagetable *greenVagetable = greenAf->get_vagetable();
    greenVagetable->show();

    return 0;
}
