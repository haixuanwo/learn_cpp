/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 18:08:00
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;
 
public:
    static Singleton *get_instance()
    {
        if (nullptr == instance)
        {
            instance = new Singleton();
        }

        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton *instance1 = Singleton::get_instance();
    Singleton *instance2 = Singleton::get_instance();

    if (instance1 == instance2)
    {
        cout << "the same instance" << endl;
    }
    else
    {
        cout << "the difference instance" << endl;
    }

    return 0;
}
