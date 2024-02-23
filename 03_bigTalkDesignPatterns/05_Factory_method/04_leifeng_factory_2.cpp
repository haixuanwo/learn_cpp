/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 09:33:53
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 11:51:04
 * @Description: file content
 */

#include <iostream>
using namespace std;

class LeiFeng
{
public:
    void sweep()
    {
        cout << "扫地" << endl;
    }

    void wash()
    {
        cout << "洗衣" << endl;
    }

    void buy_rice()
    {
        cout << "买米" << endl;
    }
};

class Undergraduate : public LeiFeng
{
public:

};

class Voluntee : public LeiFeng
{
public:

};

enum{
    UNDERGRADUATE,
    VOLUNTEE,
};

class IFactory
{
public:
    virtual LeiFeng *create_leifeng() = 0;
};

class UndergraduateFactory : public IFactory
{
public:
    LeiFeng *create_leifeng()
    {
        return new Undergraduate();
    }
};

class VolunteeFactory : public IFactory
{
public:
    LeiFeng *create_leifeng()
    {
        return new Voluntee();
    }
};

#if 0
class SimpleFactory
{
public:
    static LeiFeng *create_leifeng(char type)
    {
        switch (type)
        {
            case UNDERGRADUATE:
            {
                return new Undergraduate();
            }
            case VOLUNTEE:
            {
                return new Voluntee();
            }
        }

        return nullptr;
    }
};
#else
class FactoryMethod
{
public:
    static IFactory *create_factory(char type)
    {
        switch (type)
        {
            case UNDERGRADUATE:
            {
                return new UndergraduateFactory();
            }
            case VOLUNTEE:
            {
                return new VolunteeFactory();
            }
        }

        return nullptr;
    }
};
#endif

int main()
{
    IFactory *factory = FactoryMethod::create_factory(UNDERGRADUATE);
    LeiFeng *leiFeng = factory->create_leifeng();
    leiFeng->buy_rice();
    leiFeng->sweep();
    leiFeng->wash();

    return 0;
}
