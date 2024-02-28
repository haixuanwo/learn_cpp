/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 10:35:43
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

    void get_result(string managerLevel, Request *request)
    {
        if ("经理" == managerLevel)
        {
            if ("请假" == request->get_request_type() && request->get_number() <= 2)
            {
                cout << name << " " << request->get_request_content() << " 数量：" << request->get_number() << " 被批准"<< endl;
            }
            else
            {
                cout << name << " "  << request->get_request_content() << " 数量：" << request->get_number() << " 我无权处理"<< endl;
            }
        }
        else if ("总监" == managerLevel)
        {
            if ("请假" == request->get_request_type() && request->get_number() <= 5)
            {
                cout << name << " " << request->get_request_content() << " 数量：" << request->get_number() << " 被批准"<< endl;
            }
            else
            {
                cout << name << " "  << request->get_request_content() << " 数量：" << request->get_number() << " 我无权处理"<< endl;
            }
        }
        else if ("总经理" == managerLevel)
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
    }

private:
    string name;
};

int main()
{
    Manager *jinli = new Manager("金利");
    Manager *zongjian = new Manager("宗剑");
    Manager *zhongjingli = new Manager("钟精励");

    Request *request = new Request();
    request->set_request_type("加薪");
    request->set_request_content("小菜请求加薪");
    request->set_number(1000);

    jinli->get_result("经理", request);
    zongjian->get_result("总监", request);
    zhongjingli->get_result("总经理", request);


    Request *request2 = new Request();
    request2->set_request_type("请假");
    request2->set_request_content("小菜请假");
    request2->set_number(3);

    jinli->get_result("经理", request2);
    zongjian->get_result("总监", request2);
    zhongjingli->get_result("总经理", request2);

    return 0;
}
