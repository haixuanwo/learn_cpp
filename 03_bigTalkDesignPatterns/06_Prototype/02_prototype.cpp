/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 14:00:06
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

class Prototype
{
public:
    Prototype(string id)
    {
        this->id = id;
    }

    string get_id()
    {
        return id;
    }

    virtual Prototype *clone() = 0;
private:
    string id;
};

class ConcretePrototype1 : public Prototype
{
public:
    ConcretePrototype1(string id) : Prototype(id)
    {

    }

    Prototype *clone()
    {
        return this;
    }
};

int main()
{
    ConcretePrototype1 *p1 = new ConcretePrototype1("I");
    ConcretePrototype1 *c1 = (ConcretePrototype1 *)p1->clone();
    cout << "cloned: " << c1->get_id() << endl;

    return 0;
}
