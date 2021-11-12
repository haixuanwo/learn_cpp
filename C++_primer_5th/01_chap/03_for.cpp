/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-12 14:53:00
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-12 14:55:05
 * @Description: for语句
 */

#include <iostream>

int main()
{
    int sum = 0;

    for (int val = 0; val <= 10; val++)
    {
        sum += val;/* code */
    }

    std::cout<<"Sum of 1 to 10 inclusive is "<<sum<<std::endl;

    return 0;
}
