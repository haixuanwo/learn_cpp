/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-12 15:03:18
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-12 15:10:36
 * @Description:if 统计输入数据次数
 */

#include <iostream>

int main()
{
    int currVal = 0;    // 当前正在统计的值
    int val = 0;        // 读取的值

    // 读取一个数，确保数据可以处理
    if (std::cin>>currVal)
    {
        int cnt = 1;    // 正在处理数的个数
        while (std::cin>>val)   // 读取剩余的数
        {
            if (val == currVal) // 判断与当前的数是否相同
            {
                ++cnt;
            }
            else
            {
                // 打印前一个数的值和次数，开始统计新的数
                std::cout<<currVal<<" occurs "<<cnt<<" times"<<std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout<<currVal<<" occurs"<<cnt<<" times"<<std::endl;
    }
    return 0;
}
