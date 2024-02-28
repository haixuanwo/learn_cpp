/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 16:09:16
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Component
{
public:
    Component(string name)
    {
        this->name = name;
    }

    virtual void add(Component *c) = 0;
    virtual void remove(Component *c) = 0;
    virtual void display(int depth) = 0;

// private:
    string name;
};

class Leaf : public Component
{
public:
    Leaf(string name) : Component(name)
    {
    }

    void add(Component *c)
    {
        cout << "Cannot add to a leaf" << endl;
    }

    void remove(Component *c)
    {
        cout << "Cannot remove from a leaf" << endl;
    }

    void display(int depth)
    {
        cout << name << " a leaf" << depth << endl;
    }
};

class Composite : public Component
{
public:
    Composite(string name) : Component(name)
    {
        children = new list<Component *>();
    }

    void add(Component *c)
    {
        children->push_back(c);
    }

    void remove(Component *c)
    {
        list<Component *>::iterator itList;
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
        for (auto &&component : *children)
        {
            component->display(depth + 2);
        }
    }

private:
    list<Component *> *children;
};

int main()
{
    Composite *root = new Composite("Root");
    root->add(new Leaf("Leaf A"));
    root->add(new Leaf("Leaf B"));

    Composite *comp = new Composite("Composite X");
    comp->add(new Leaf("Leaf XA"));
    comp->add(new Leaf("Leaf XB"));

    root->add(comp);

    Composite *comp2 = new Composite("Composite XY");
    comp2->add(new Leaf("Leaf XYA"));
    comp2->add(new Leaf("Leaf XYB"));

    comp->add(comp2);

    root->add(new Leaf("Leaf C"));

    Leaf *leaf = new Leaf("Leaf D");
    root->add(leaf);
    root->remove(leaf);

    root->display(1);

    return 0;
}
