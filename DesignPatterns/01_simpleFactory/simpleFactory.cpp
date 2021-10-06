/**
 * @author Clark
 * @email haixuanwoTxh@gmail.com
 * @date 2021-10-06
 */
#include <iostream>
using namespace std;

class AProduct
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
    int A;
    int B;
};

class Plus:public AProduct
{
public:
    int get_result()
    {
        cout<<"A["<<A<<"] + B["<<B<<"] ="<<endl;
        return A + B;
    }
};

class Sub:public AProduct
{
public:
    int get_result()
    {
        cout<<"A["<<A<<"] - B["<<B<<"] ="<<endl;
        return A - B;
    }
};

class ProductFactory
{
public:
    ProductFactory()
    {
        ap = nullptr;
    }

    AProduct* get_product(char type)
    {
        switch(type)
        {
            case '+':
                ap = new Plus;
                break;
            case '-':
                ap = new Sub;
                break;
            default:
                cout<<"The type error"<<endl;
                break;
        }

        return ap;
    }

private:
    AProduct *ap;
};

int main(int argc, char *argv[])
{
    ProductFactory pf;

    AProduct *ap1 = pf.get_product('+');
    ap1->setA(200);
    ap1->setB(2);
    cout<<ap1->get_result()<<endl;

    AProduct *ap2 = pf.get_product('-');
    ap2->setA(200);
    ap2->setB(2);
    cout<<ap2->get_result()<<endl;

    return 0;
}
