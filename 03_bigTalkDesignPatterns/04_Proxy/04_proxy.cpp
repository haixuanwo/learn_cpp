/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 10:10:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 10:38:38
 * @Description: file content
 */

#include <string>
#include <iostream>
using namespace std;

class Subject
{
public:
    virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
    void request()
    {
        cout << "真实的请求" << endl;
    }
};

class Proxy : public Subject
{
public:
    void request()
    {
        if (nullptr == realSubject)
        {
            realSubject = new RealSubject();
        }
        realSubject->request();
    }

private:
    RealSubject *realSubject;
};

int main()
{
    Proxy *proxy = new Proxy();
    proxy->request();

    return 0;
}
