/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 10:28:11
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

/*
用简单工厂来改进抽象工厂
*/

class User
{
};

class IUser
{
public:
    virtual void insert(User *user) = 0;
    virtual User* get_user(int id) = 0;
};

class SqlserverUser : public IUser
{
public:
    void insert(User *user)
    {
        cout << "在SQL Server中给User表增加一条记录" << endl;
    }

    User* get_user(int id)
    {
        cout << "在SQL Server中根据 ID:" << id << " 得到User表一条记录" << endl;
        return nullptr;
    }
};

class AccessUser : public IUser
{
public:
    void insert(User *user)
    {
        cout << "在Access Server中给User表增加一条记录" << endl;
    }

    User* get_user(int id)
    {
        cout << "在Access Server中根据 ID:" << id << " 得到User表一条记录" << endl;
        return nullptr;
    }
};

class Department
{
};

class IDepartment
{
public:
    virtual void insert(Department *department) = 0;
    virtual Department* get_department(int id) = 0;
};

class SqlserverDepartment : public IDepartment
{
public:
    void insert(Department *department)
    {
         cout << "在SqlserverDepartment中给department表增加一条记录" << endl;
    }

    Department* get_department(int id)
    {
        cout << "在SqlserverDepartment中根据 ID:" << id << " 得到department表一条记录" << endl;
        return nullptr;
    }
};

class AccessDepartment : public IDepartment
{
public:
    void insert(Department *department)
    {
        cout << "在AccessDepartment中给department表增加一条记录" << endl;
    }

    Department* get_department(int id)
    {
        cout << "在AccessDepartment中根据 ID:" << id << " 得到department表一条记录" << endl;
        return nullptr;
    }
};

class DataAccess
{
public:
    typedef enum {
        SQLSERVER,
        ACCESS,
    }DB;

    static IUser* create_user()
    {
        IUser *result = nullptr;
        switch (db)
        {
            case SQLSERVER:
            {
                result = new SqlserverUser();
                break;
            }
            case ACCESS:
            {
                result = new AccessUser();
                break;
            }
        }
        return result;
    }

    static IDepartment* create_department()
    {
        IDepartment *result = nullptr;
        switch (db)
        {
            case SQLSERVER:
            {
                result = new SqlserverDepartment();
                break;
            }
            case ACCESS:
            {
                result = new AccessDepartment();
                break;
            }
        }
        return result;
    }
private:
    static const DB db;
};

// const DataAccess::DB DataAccess::db = DataAccess::ACCESS;
const DataAccess::DB DataAccess::db = DataAccess::SQLSERVER;

#if 0
class IFactory
{
public:
    virtual IUser *create_user() = 0;
    virtual IDepartment *create_department() = 0;
};

class SqlServerFactory : public IFactory
{
public:
    IUser *create_user()
    {
        return new SqlserverUser();
    }

    IDepartment *create_department()
    {
        return new SqlserverDepartment();
    }
};

class AccessFactory : public IFactory
{
public:
    IUser *create_user()
    {
        return new AccessUser();
    }

    IDepartment *create_department()
    {
        return new AccessDepartment();
    }
};
#endif

int main()
{
    IUser *user1 = DataAccess::create_user();
    user1->insert(new User());
    user1->get_user(1);

    IDepartment *department1 = DataAccess::create_department();
    department1->insert(new Department());
    department1->get_department(1);

    return 0;
}
