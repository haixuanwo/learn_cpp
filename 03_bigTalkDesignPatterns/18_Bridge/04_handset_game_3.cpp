/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 23:38:15
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class HandsetSoft
{
public:
    virtual void run() = 0;
};

class HandsetGame : public HandsetSoft
{
public:
    void run()
    {
        cout << "运行手机游戏" << endl;
    }
};

class HandsetAddressList : public HandsetSoft
{
public:
    void run()
    {
        cout << "运行手机通讯录" << endl;
    }
};

class HandsetMP3 : public HandsetSoft
{
public:
    void run()
    {
        cout << "运行手机MP3播放" << endl;
    }
};


class HandsetBrand
{
public:
    void set_handset_soft(HandsetSoft *soft)
    {
        this->soft = soft;
    }

    virtual void run() = 0;

// private:
    HandsetSoft *soft;
};

class HandsetBrandN : public HandsetBrand
{
public:
    void run()
    {
        cout << "N品牌 ";
        soft->run();
    }
};

class HandsetBrandM : public HandsetBrand
{
public:
    void run()
    {
        cout << "M品牌 ";
        soft->run();
    }
};

int main()
{
    HandsetBrand *ab = new HandsetBrandN();
    ab->set_handset_soft(new HandsetGame());
    ab->run();

    ab->set_handset_soft(new HandsetAddressList());
    ab->run();

    ab->set_handset_soft(new HandsetMP3());
    ab->run();

    ab = new HandsetBrandM();
    ab->set_handset_soft(new HandsetGame());
    ab->run();

    ab->set_handset_soft(new HandsetAddressList());
    ab->run();

    ab->set_handset_soft(new HandsetMP3());
    ab->run();
    
    return 0;
}
