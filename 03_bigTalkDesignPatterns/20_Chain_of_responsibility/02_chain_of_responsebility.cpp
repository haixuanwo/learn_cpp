/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 11:02:19
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Handler
{
public:
    void set_successor(Handler *successor)
    {
        this->successor = successor;
    }

    virtual void handle_request(int request) = 0;

// private:
    Handler *successor;
};

class ConcreteHandler1 : public Handler
{
public:
    void handle_request(int request)
    {
        if (request >= 0 && request < 10)
        {
            cout << "ConcreteHandler1 处理请求 " << request << endl;
        }
        else if (nullptr != successor)
        {
            successor->handle_request(request);
        }
    }
};

class ConcreteHandler2 : public Handler
{
public:
    void handle_request(int request)
    {
        if (request >= 10 && request < 20)
        {
            cout << "ConcreteHandler2 处理请求 " << request << endl;
        }
        else if (nullptr != successor)
        {
            successor->handle_request(request);
        }
    }
};

class ConcreteHandler3 : public Handler
{
public:
    void handle_request(int request)
    {
        if (request >= 20 && request < 30)
        {
            cout << "ConcreteHandler3 处理请求 " << request << endl;
        }
        else if (nullptr != successor)
        {
            successor->handle_request(request);
        }
    }
};

int main()
{
    Handler *h1 = new ConcreteHandler1();
    Handler *h2 = new ConcreteHandler2();
    Handler *h3 = new ConcreteHandler3();

    h1->set_successor(h2);
    h2->set_successor(h3);

    int requests[] = {2, 5, 14, 22, 18, 3, 27, 20};

    for (auto &&i : requests)
    {
        h1->handle_request(i);
    }

    return 0;
}
