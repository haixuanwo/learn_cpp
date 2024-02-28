/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-23 17:28:08
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class User
{
public:
    void set_name(string name)
    {
        this->name = name;
    }

    string get_name()
    {
        return name;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    int get_id()
    {
        return id;
    }

private:
    string name;
    int id;
};

class SqlserverUser
{
public:
    void insert(User *user)
    {
        cout << "在SQL Server中给User表增加一条记录" << endl;
    }

    User* get_user(int id)
    {
        cout << "在SQL Server中根据ID得到User表一条记录" << endl;
        return nullptr;
    }
};

int main()
{
    User *user = new User();
    SqlserverUser *sqlserverUser = new SqlserverUser();

    sqlserverUser->insert(user);
    sqlserverUser->get_user(1);
    return 0;
}
