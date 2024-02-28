/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-28 16:43:15
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    virtual void visit_concrete_elementA(ConcreteElementA *concreteElementA) = 0;
    virtual void visit_concrete_elementB(ConcreteElementB *concreteElementB) = 0;
};

class ConcreteVisitor1 : public Visitor
{
public:
    void visit_concrete_elementA(ConcreteElementA *concreteElementA)
    {
        cout << "ConcreteVisitor1 --- ConcreteElementA" << endl;
    }

    void visit_concrete_elementB(ConcreteElementB *concreteElementB)
    {
        cout << "ConcreteVisitor1 --- ConcreteElementB" << endl;
    }
};

class ConcreteVisitor2 : public Visitor
{
public:
    void visit_concrete_elementA(ConcreteElementA *concreteElementA)
    {
        cout << "ConcreteVisitor2 --- ConcreteElementA" << endl;

    }

    void visit_concrete_elementB(ConcreteElementB *concreteElementB)
    {
        cout << "ConcreteVisitor2 --- ConcreteElementB" << endl;
    }
};

class Element
{
public:
    virtual void accept(Visitor *visitor) = 0;
};

class ConcreteElementA : public Element
{
public:
    void accept(Visitor *visitor)
    {
        visitor->visit_concrete_elementA(this);
    }

    void operationA()
    {

    }
};

class ConcreteElementB : public Element
{
public:
    void accept(Visitor *visitor)
    {
        visitor->visit_concrete_elementB(this);
    }

    void operationB()
    {

    }
};

class ObjectStructure
{
public:
    void attach(Element *element)
    {
        elements.push_back(element);
    }

    void detach(Element *element)
    {
        list<Element *>::iterator itList;
        for (itList = elements.begin(); itList != elements.end();)
        {
            if (element ==  *itList)
            {
                itList = elements.erase( itList);
                break;
            }
            else
            {
                itList++;
            }
        }
    }

    void accept(Visitor *visitor)
    {
        for (auto &&element : elements)
        {
            element->accept(visitor);
        }
    }

private:
    list<Element *> elements;
};


int main()
{
    ObjectStructure *o = new ObjectStructure();
    o->attach(new ConcreteElementA());
    o->attach(new ConcreteElementB());

    ConcreteVisitor1 *v1 = new ConcreteVisitor1();
    ConcreteVisitor2 *v2 = new ConcreteVisitor2();

    o->accept(v1);
    o->accept(v2);

    return 0;
}
