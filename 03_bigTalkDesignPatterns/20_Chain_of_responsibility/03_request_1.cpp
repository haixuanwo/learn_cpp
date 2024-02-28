/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 11:33:33
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Request
{
public:
    void set_request_type(string requestType)
    {
        this->requestType = requestType;
    }

    string get_request_type()
    {
        return requestType;
    }

    void set_request_content(string requestContent)
    {
        this->requestContent = requestContent;
    }

    string get_request_content()
    {
        return requestContent;
    }

    void set_number(int number)
    {
        this->number = number;
    }

    int get_number()
    {
        return number;
    }

private:
    int number;
    string requestType;
    string requestContent;
};

class Manager
{
public:
    Manager(string name)
    {
        this->name = name;
    }

    void set_superior(Manager *superior)
    {
        this->superior = superior;
    }

    virtual void request_applications(Request *request) = 0;

// private:
    string name;
    Manager *superior;
};

// 经理
class CommonManager : public Manager
{
public:
    CommonManager(string name) : Manager(name) { }

    void request_applications(Request *request)
    {
        if ("请假" == request->get_request_type() && request->get_number() <= 2)
        {
            cout << name << " " << request->get_request_content() << " 数量：" << request->get_number() << " 被批准"<< endl;
        }
        else if (nullptr != superior)
        {
            superior->request_applications(request);
        }
    }
};

// 总监
class MajorManager : public Manager
{
public:
    MajorManager(string name) : Manager(name) { }

    void request_applications(Request *request)
    {
        if ("请假" == request->get_request_type() && request->get_number() <= 5)
        {
            cout << name << " " << request->get_request_content() << " 数量：" << request->get_number() << " 被批准"<< endl;
        }
        else if (nullptr != superior)
        {
            superior->request_applications(request);
        }
    }
};

// 总经理
class GeneralManager : public Manager
{
public:
    GeneralManager(string name) : Manager(name) { }

    void request_applications(Request *request)
    {
        if ("请假" == request->get_request_type())
        {
            cout << name << " "  << request->get_request_content() << " 数量：" << request->get_number() << " 被批准"<< endl;
        }
        else if ("加薪" == request->get_request_type() && request->get_number() <= 500)
        {
            cout << name << " "  << request->get_request_content() << " 数量：" << request->get_number() << " 被批准"<< endl;
        }
        else if ("加薪" == request->get_request_type() && request->get_number() > 500)
        {
            cout << name << " "  << request->get_request_content() << " 数量：" << request->get_number() << " 再说吧" << endl;
        }
    }
};

int main()
{


    CommonManager *jinli = new CommonManager("金利");
    MajorManager *zongjian = new MajorManager("宗剑");
    GeneralManager *zhongjingli = new GeneralManager("钟精励");

    jinli->set_superior(zongjian);
    zongjian->set_superior(zhongjingli);

    Request *request = new Request();
    request->set_request_type("请假");
    request->set_request_content("小菜请假");
    request->set_number(1);
    jinli->request_applications(request);

    Request *request2 = new Request();
    request2->set_request_type("请假");
    request2->set_request_content("小菜请假");
    request2->set_number(4);
    jinli->request_applications(request2);

    Request *request3 = new Request();
    request3->set_request_type("加薪");
    request3->set_request_content("小菜请求加薪");
    request3->set_number(500);
    jinli->request_applications(request3);

    Request *request4 = new Request();
    request4->set_request_type("加薪");
    request4->set_request_content("小菜请求加薪");
    request4->set_number(1000);
    jinli->request_applications(request4);

    return 0;
}
