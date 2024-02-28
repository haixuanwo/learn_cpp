/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 23:08:28
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;

public:
    static Singleton *get_instance()
    {
        return instance;
    }
};

// 饿汉模式，加载时就将自己实例化
Singleton* Singleton::instance = new Singleton();

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
