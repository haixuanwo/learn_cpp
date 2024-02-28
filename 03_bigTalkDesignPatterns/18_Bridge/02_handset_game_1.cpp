/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 23:23:47
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class HandsetGame
{
public:
    virtual void run() = 0;
};


class HandsetNGame : public HandsetGame
{
public:
    void run()
    {
        cout << "运行N品牌手机游戏" << endl;
    }
};

class HandsetMGame : public HandsetGame
{
public:
    void run()
    {
        cout << "运行M品牌手机游戏" << endl;
    }
};

class HandsetBrand
{
public:
    virtual void run() = 0;
};

class HandsetBrandM : public HandsetBrand
{
};

class HandsetBrandN : public HandsetBrand
{
};

class HandsetBrandMGame : public HandsetBrandM
{
public:
    void run()
    {
        cout << "运行M品牌手机游戏" << endl;
    }
};

class HandsetBrandNGame : public HandsetBrandN
{
public:
    void run()
    {
        cout << "运行N品牌手机游戏" << endl;
    }
};

class HandsetBrandMAddressList : public HandsetBrandM
{
public:
    void run()
    {
        cout << "运行M品牌手机通讯录" << endl;
    }
};

class HandsetBrandNAddressList : public HandsetBrandN
{
public:
    void run()
    {
        cout << "运行N品牌手机通讯录" << endl;
    }
};

int main()
{
    HandsetBrand *ab = new HandsetBrandMAddressList();
    ab->run();

    ab = new HandsetBrandMGame();
    ab->run();

    ab = new HandsetBrandNAddressList();
    ab->run();

    ab = new HandsetBrandNGame();
    ab->run();

    return 0;
}
