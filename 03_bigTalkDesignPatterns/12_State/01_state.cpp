/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 10:35:48
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

static int Hour = 0;
static bool workFinished = false;

void work_program()
{
    if (Hour < 12)
    {
        cout << "当前时间：" << Hour << "点 上午工作，精神百倍" << endl;
    }
    else  if (Hour < 13)
    {
        cout << "当前时间：" << Hour << "点 饿了，午饭，犯困，午休" << endl;
    }
    else  if (Hour < 17)
    {
        cout << "当前时间：" << Hour << "点 下午状态还不错，继续努力" << endl;
    }
    else
    {
        if (workFinished)
        {
            cout << "当前时间：" << Hour << "点 下班回家了" << endl;
        }
        else
        {
            if (Hour < 21)
            {
                cout << "当前时间：" << Hour << "点 加班哦，疲劳之极" << endl;
            }
            else
            {
                cout << "当前时间：" << Hour << "点 不行了，睡着了" << endl;
            }
        }
    }
}

int main()
{
    Hour = 9;
    work_program();

    Hour = 10;
    work_program();

    Hour = 12;
    work_program();

    Hour = 13;
    work_program();

    Hour = 14;
    work_program();

    Hour = 17;
    work_program();

    // workFinished = true;
    workFinished = false;

    Hour = 19;
    work_program();

    Hour = 22;
    work_program();

    return 0;
}
