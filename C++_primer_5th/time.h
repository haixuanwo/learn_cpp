/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-06-19 15:10:06
 * @LastEditors: Clark
 * @LastEditTime: 2022-06-19 15:09:00
 * @Description: file content
 */
#ifndef TIME_H
#define TIME_H

#include <sys/time.h>

// struct timeval{
//     long int tv_sec; // 秒数
//     long int tv_usec; // 微秒数
// }

// struct timezone{
// 	int tz_minuteswest;/*格林威治时间往西方的时差*/
// 	int tz_dsttime;/*DST 时间的修正方式*/
// }

/**
 * @brief 时间类
 *  1、计算一块代码运行时间
 *  2、计算代码行执行周期时间
 * 注：在多线程和多进程时，会包含切换后其他任务的执行时间
 */
class Time
{
public:
    Time()
    {
        lastTime = get_now_time();
    }

    time_t get_now_time()  // 单位ms
    {
        struct timeval tv;
        int ret = gettimeofday(&tv, nullptr);
        if (-1 == ret)
        {
            return 0;
        }

        return (tv.tv_sec*1000 + tv.tv_usec/1000);
    }

    time_t get_diff_time()
    {
        time_t nowTime = get_now_time();
        time_t diffTime = nowTime - lastTime;
        lastTime = nowTime;

        return diffTime;
    }

    void start_test_time()
    {
        lastTime = get_now_time();
    }

    ~Time()
    {

    }
private:
    time_t lastTime;
};

#endif
