/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 11:45:57
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Work;
class State
{
public:
    virtual void write_program(Work *w) = 0;
};

class ForenoonState : public State
{
public:
    void write_program(Work *w);
};

class Work
{
public:
    Work()
    {
        state = new ForenoonState();
    }

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

    void set_state(State *state)
    {
        this->state = state;
    }

    void write_program()
    {
        state->write_program(this);
    }

private:
    int hour;
    bool workFinished;
    State *state;
};

// 睡眠状态
class SleepingState : public State
{
public:
    void write_program(Work *w)
    {
        cout << "当前时间：" << w->get_hour() << " 点 不行了，睡着了" << endl;
    }
};

// 下班休息状态
class RestState : public State
{
public:
    void write_program(Work *w)
    {
        cout << "当前时间：" << w->get_hour() << " 点 下班回家了" << endl;
    }
};

// 晚间工作状态
class EveningState : public State
{
public:
    void write_program(Work *w)
    {
        if (w->get_work_finished())
        {
            w->set_state(new RestState());
            w->write_program();
        }
        else
        {
            if (w->get_hour() < 21)
            {
                cout << "当前时间：" << w->get_hour() << " 点 加班哦，疲累之极" << endl;
            }
            else
            {
                w->set_state(new SleepingState());
                w->write_program();
            }
        }
    }
};

// 下午工作状态
class AfternoonState : public State
{
public:
    void write_program(Work *w)
    {
        if (w->get_hour() < 17)
        {
            cout << "当前时间：" << w->get_hour() << " 下午状态还不错，继续努力" << endl;
        }
        else
        {
            w->set_state(new EveningState());
            w->write_program();
        }
    }
};

// 中午工作状态
class NoonState : public State
{
public:
    void write_program(Work *w)
    {
        if (w->get_hour() < 13)
        {
            cout << "当前时间：" << w->get_hour() << " 点 饿了，午饭，犯困，午休" << endl;
        }
        else
        {
            w->set_state(new AfternoonState());
            w->write_program();
        }
    }
};

// 上午工作状态
void ForenoonState::write_program(Work *w)
{
    if (w->get_hour() < 12)
    {
        cout << "当前时间：" << w->get_hour() << " 上午工作，精神百倍" << endl;
    }
    else
    {
        w->set_state(new NoonState());
        w->write_program();
    }
}

int main()
{
    Work *work = new Work();
    work->set_hour(9);
    work->write_program();

    work->set_hour(10);
    work->write_program();

    work->set_hour(12);
    work->write_program();

    work->set_hour(13);
    work->write_program();

    work->set_hour(14);
    work->write_program();

    work->set_hour(17);
    work->write_program();

    work->set_hour(19);
    work->set_work_finished(true);
    work->write_program();

    work->set_hour(22);
    work->write_program();
    return 0;
}
