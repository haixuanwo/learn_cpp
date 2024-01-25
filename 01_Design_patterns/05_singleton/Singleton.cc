/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-25 13:43:48
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-25 13:44:03
 * @Description: file content
 */

#include <iostream>

class Singleton
{
public:
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const&) = delete;

    static Singleton* get()
    {
        if (!instance)  // 锁呢？
        {
            instance = new Singleton();
        }

        return instance;
    }

    static void restart()
    {
        if (instance)
        {
            delete instance;
        }
    }

    void tell()
    {
        std::cout << "This is Singleton." << std::endl;
    }

private:
    Singleton() { }
    static Singleton *instance;
};

Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton::get()->tell();
    Singleton::restart();

    return 0;
}
