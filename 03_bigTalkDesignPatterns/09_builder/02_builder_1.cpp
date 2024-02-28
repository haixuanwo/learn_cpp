/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 13:45:52
 * @Description: file content
 */
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Product
{
public:
    Product()
    {
        parts = new list<string>();
    }

    void add(string part)
    {
        parts->push_back(part);
    }

    void show()
    {
        for (auto &&part : *parts)
        {
            cout << part << endl;
        }
    }

private:
    list<string> *parts;
};

class Builder
{
public:
    virtual void build_partA() = 0;
    virtual void build_partB() = 0;
    virtual Product* get_result() = 0;
};

class ConcreteBuilder1 : public Builder
{
public:
    ConcreteBuilder1()
    {
        product = new Product();
    }

    void build_partA()
    {
        product->add("部件A");
    }

    void build_partB()
    {
        product->add("部件B");
    }

    Product* get_result()
    {
        return product;
    }

private:
    Product *product;
};

class ConcreteBuilder2 : public Builder
{
public:
    ConcreteBuilder2()
    {
        product = new Product();
    }

    void build_partA()
    {
        product->add("部件X");
    }

    void build_partB()
    {
        product->add("部件Y");
    }

    Product* get_result()
    {
        return product;
    }

private:
    Product *product;
};

class Director
{
public:
    void construct(Builder *builder)
    {
        builder->build_partA();
        builder->build_partB();
    }
};

int main()
{
    Director *director = new Director();
    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();

    director->construct(b1);
    Product *p1 = b1->get_result();
    p1->show();

    director->construct(b2);
    Product *p2 = b2->get_result();
    p2->show();
    return 0;
}
