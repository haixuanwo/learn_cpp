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

class Work
{
public:
    void set_hour(int hour)
    {
        this->hour = hour;
    }

    int get_hour()
    {
        return hour;
    }

    void set_work_finished(bool workFinished)
    {
        this->workFinished = workFinished;
    }

    bool get_work_finished()
    {
        return workFinished;
    }

    void work_program()
    {
        if (hour < 12)
        {
            cout << "当前时间：" << hour << "点 上午工作，精神百倍" << endl;
        }
        else  if (hour < 13)
        {
            cout << "当前时间：" << hour << "点 饿了，午饭，犯困，午休" << endl;
        }
        else  if (hour < 17)
        {
            cout << "当前时间：" << hour << "点 下午状态还不错，继续努力" << endl;
        }
        else
        {
            if (workFinished)
            {
                cout << "当前时间：" << hour << "点 下班回家了" << endl;
            }
            else
            {
                if (hour < 21)
                {
                    cout << "当前时间：" << hour << "点 加班哦，疲劳之极" << endl;
                }
                else
                {
                    cout << "当前时间：" << hour << "点 不行了，睡着了" << endl;
                }
            }
        }
    }

private:
    int hour;
    bool workFinished;
};

int main()
{
    Work *work = new Work();
    work->set_hour(9);
    work->work_program();

    work->set_hour(10);
    work->work_program();

    work->set_hour(12);
    work->work_program();

    work->set_hour(13);
    work->work_program();

    work->set_hour(14);
    work->work_program();

    work->set_hour(17);
    work->work_program();

    work->set_hour(19);
    work->set_work_finished(true);
    work->work_program();

    work->set_hour(22);
    work->work_program();

    return 0;
}
