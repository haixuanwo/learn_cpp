/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 14:06:55
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Target
{
public:
    virtual void request()
    {
        cout << "普通请求" << endl;
    }
};

class Adaptee
{
public:
    void specific_request()
    {
        cout << "特殊请求" << endl;
    }
};

class Adapter : public Target
{
public:
    Adapter()
    {
        adaptee = new Adaptee();
    }

    void request()
    {
        adaptee->specific_request();
    }

private:
    Adaptee *adaptee;
};

int main()
{
    Target *target = new Adapter();
    target->request();

    return 0;
}

