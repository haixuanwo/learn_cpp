/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-12 12:32:22
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-12 12:36:44
 * @Description: while语句示例
 */

#include <iostream>

int main()
{
    int sum = 0;
    int val = 0;

    // while会循环到val值不小于10为止
    while (val <= 10)
    {
        sum += val; // 将sum+val的值赋予sum
        ++val;      // val值加1
    }

    std::cout<<"Sum of 1 to 10 inclusive is "<<sum<<std::endl;

    return 0;
}
