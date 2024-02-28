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
using namespace std;

class HandsetNGame
{
public:
    void run()
    {
        cout << "运行N品牌手机游戏" << endl;
    }
};

int main()
{
    HandsetNGame *game = new HandsetNGame();
    game->run();

    return 0;
}
