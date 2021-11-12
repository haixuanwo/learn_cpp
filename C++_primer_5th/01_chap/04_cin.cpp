/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-12 14:57:22
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-12 15:01:33
 * @Description: cin
 */

#include <iostream>

int main()
{
    int sum = 0;
    int value = 0;

    // 读取数据直到文件末尾，计算所有输入值的和
    // ctrl+d为文件结束符EOF
    while (std::cin>>value)
    {
        sum += value;
    }

    std::cout<<"Sum is: "<<sum<<std::endl;
    return 0;
}
