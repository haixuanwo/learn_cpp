/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 17:46:46
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class IUser
{
public:
    virtual void insert(IUser *user) = 0;
    virtual IUser* get_user(int id) = 0;
};

class SqlserverUser : public IUser
{
public:
    void insert(IUser *user)
    {
        cout << "在SQL Server中给User表增加一条记录" << endl;
    }

    IUser* get_user(int id)
    {
        cout << "在SQL Server中根据 ID:" << id << " 得到User表一条记录" << endl;
        return nullptr;
    }
};

class AccessUser : public IUser
{
public:
    void insert(IUser *user)
    {
        cout << "在Access Server中给User表增加一条记录" << endl;
    }

    IUser* get_user(int id)
    {
        cout << "在Access Server中根据 ID:" << id << " 得到User表一条记录" << endl;
        return nullptr;
    }
};

class IFactory
{
public:
    virtual IUser *create_user() = 0;
};

class SqlServerFactory : public IFactory
{
public:
    IUser *create_user()
    {
        return new SqlserverUser();
    }
};

class AccessFactory : public IFactory
{
public:
    IUser *create_user()
    {
        return new AccessUser();
    }
};

int main()
{
    IFactory *factory1 = new SqlServerFactory();
    IUser *user1 = factory1->create_user();
    user1->insert(user1);
    user1->get_user(1);

    IFactory *factory2 = new AccessFactory();
    IUser *user2 = factory2->create_user();
    user2->insert(user2);
    user2->get_user(2);
    return 0;
}
