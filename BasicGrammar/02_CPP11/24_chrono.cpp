/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-07-07 12:41:44
 * @LastEditors: Clark
 * @LastEditTime: 2022-07-07 13:03:14
 * @Description: file content
 */

#include <chrono>
#include <thread>
#include <iostream>
using std::cout;
using std::endl;
using namespace std::chrono;
using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;

class Timer
{
public:
    TimePoint get_now_time()
    {
        return steady_clock::now();
    }

    TimePoint start()
    {
        last = get_now_time();
        return last;
    }

    unsigned long stop()
    {
        auto now = get_now_time();
        return duration_cast<microseconds>(now - last).count()/1000;  // 返回毫秒数
    }

 private:
    TimePoint last;
};

int main()
{
    Timer T;
    // cout<<"Start: "<<T.Start()<<endl;
    T.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    cout<<"Stop: "<<T.stop()<<endl;

    return 0;
}
