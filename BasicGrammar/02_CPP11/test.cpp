#include <iostream>
using namespace std;

class base
{
public:
    virtual void print()
    {
        cout<<"base print"<<endl;
    }

    void show()
    {
        cout<<"base print"<<endl;
    }
};

class Derive:public base
{
public:
    void print()
    {
        cout<<"Derive print"<<endl;
    }

    void show()
    {
        cout<<"Derive show"<<endl;
    }
};


int main(int argc, char * argv [ ])
{
    base b;
    b.print();
    b.show();

    Derive d;
    d.print();
    d.show();

    base *q = new Derive;
    q->print();
    q->show();
    return 0;
}

