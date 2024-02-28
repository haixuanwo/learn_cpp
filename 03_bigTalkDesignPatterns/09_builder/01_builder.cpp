/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 11:23:19
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

class Pen
{

};

class Graphics
{

};

class PersonBuilder
{
public:
    PersonBuilder() { }
    PersonBuilder(Pen *pen, Graphics *graphics)
    {
        pen_ = pen;
        graphics_ = graphics;
    }

    virtual ~PersonBuilder() { }
    virtual void build_head() { }
    virtual void build_body() { }

protected:
    Pen* pen_;
    Graphics* graphics_;
};

class PersonThinBuilder : public PersonBuilder
{
public:
    PersonThinBuilder(Pen* pen, Graphics* graphics) : PersonBuilder(pen, graphics)
    {

    }

    void build_head()
    {
        cout << "Build thin head" << endl;
    }

    void build_body()
    {
        cout << "Build thin body" << endl;
    }
};

class PersonFatBuilder : public PersonBuilder
{
public:
    PersonFatBuilder(Pen* pen, Graphics* graphics) : PersonBuilder(pen, graphics)
    {

    }

    void build_head()
    {
        cout << "Build fat head" << endl;
    }

    void build_body()
    {
        cout << "Build fat body" << endl;
    }
};

class PersonDirector
{
public:
    PersonDirector(PersonBuilder *personBuilder) : personBuilder_(personBuilder)
    {

    }

    void create_person()
    {
        personBuilder_->build_head();
        personBuilder_->build_body();
    }

private:
    PersonBuilder *personBuilder_;
};

int main()
{
    PersonBuilder *pb1 = new PersonThinBuilder(new Pen(), new Graphics());
    PersonDirector * pd1 = new PersonDirector(pb1);
    pd1->create_person();

    PersonBuilder *pb2 = new PersonFatBuilder(new Pen(), new Graphics());
    PersonDirector * pd2 = new PersonDirector(pb2);
    pd2->create_person();
    return 0;
}
