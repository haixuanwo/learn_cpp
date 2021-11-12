/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-12 11:23:27
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-12 12:28:01
 * @Description: 输入两个数并相加
 */

#include <iostream>

/**
 * @brief 读取两个数，并求和
 */
int main()
{
    // 提示用户输入两个数
    std::cout<<"Enter two numbers:"<<std::endl;
    int v1 = 0;
    int v2 = 0;

    std::cin>>v1>>v2;   // 读取输入数据

    // 计算并显示结果
    std::cout<<"The sun of "<<v1<<" and "<<v2<<" is "<<v1+v2<<std::endl;

    return 0;
}
