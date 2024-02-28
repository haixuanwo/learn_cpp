/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 15:26:30
 * @Description: file content
 */

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Flyweight
{
public:
    virtual void operation(int extrinsicstate) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
    void operation(int extrinsicstate)
    {
        cout << "具体Flyweight: " << extrinsicstate << endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    void operation(int extrinsicstate)
    {
        cout << "不共享的具体Flyweight: " << extrinsicstate << endl;
    }
};

class FlyweightFactory
{
public:
    FlyweightFactory()
    {
        flyweights["X"] = new ConcreteFlyweight();
        flyweights["Y"] = new ConcreteFlyweight();
        flyweights["Z"] = new ConcreteFlyweight();
    }

    Flyweight *get_flyweight(string key)
    {
        return flyweights[key];
    }

private:
    map <string, Flyweight*> flyweights;
};

int main()
{
    int extrinsicstate =22;

    FlyweightFactory *f = new FlyweightFactory();

    Flyweight *fx = f->get_flyweight("X");
    fx->operation(--extrinsicstate);

    Flyweight *fy = f->get_flyweight("Y");
    fy->operation(--extrinsicstate);

    Flyweight *fz = f->get_flyweight("Z");
    fz->operation(--extrinsicstate);

    Flyweight *uf = new UnsharedConcreteFlyweight();
    uf->operation(--extrinsicstate);

    return 0;
}
