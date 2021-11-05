/**
 * @author Clark
 * @email haixuanwoTxh@gmail.com
 * @date 2021-10-06
 */
#include <iostream>
using namespace std;

/**
 * brief 不同的工厂生产不同的产品
 */

class AbProduct
{
public:
    virtual int get_result() = 0;
    void setA(int a)
    {
        A = a;
    }

    void setB(int b)
    {
        B = b;
    }

protected:

    int getA()
    {
        return A;
    }

    int getB()
    {
        return B;
    }

    int A;
    int B;
};

class Plus:public AbProduct
{
public:
    int get_result()
    {
        cout<<"A["<<A<<"] + B["<<B<<"] ="<<endl;
        return getA() + getB();
    }
};

class Sub:public AbProduct
{
public:
    int get_result()
    {
        cout<<"A["<<A<<"] - B["<<B<<"] ="<<endl;
        return getA() - getB();
    }
};

class AbFactory
{
public:
    virtual AbProduct* get_product() = 0;
};

class PlusFactory:public AbFactory
{
public:
    AbProduct* get_product()
    {
        return new Plus;
    }
};

class SubFactory:public AbFactory
{
public:
    AbProduct* get_product()
    {
        return new Sub;
    }
};

int main(int argc, char *argv[])
{
    AbFactory *af1 = new PlusFactory;
    AbProduct *ap1 = af1->get_product();
    ap1->setA(200);
    ap1->setB(2);
    cout<<ap1->get_result()<<endl;


    AbFactory *af2 = new SubFactory;
    AbProduct *ap2 = af2->get_product();
    ap2->setA(200);
    ap2->setB(2);
    cout<<ap2->get_result()<<endl;
    return 0;
}


