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
#include <mutex>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    static mutex mutex_;

public:
    static Singleton *get_instance()
    {
        // 双重锁定，懒汉模式，运行时初始化实例
        if (nullptr == instance)
        {
            mutex_.lock();
            if (nullptr == instance)
            {
                instance = new Singleton();
            }
            mutex_.unlock();
        }

        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mutex_;

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
