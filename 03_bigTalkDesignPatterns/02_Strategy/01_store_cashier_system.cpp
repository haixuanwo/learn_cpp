/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 11:47:21
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-20 11:59:21
 * @Description: file content
 */

/*
记录商品清单，统计商品总数与总价
*/

#include <iostream>
using namespace std;

int main()
{
    int totalNum = 0;
    double totalPrice = 0.0;

    while (1)
    {
        cout << "请输入商品单价:" << endl;
        double unitPrice = 0;
        cin>>unitPrice;

        cout << "请输入商品数量：" << endl;
        int num = 0;
        cin>>num;

        double currentTotalPrice = unitPrice * num;
        cout <<"单价："<<unitPrice<<" 数量："<<num<<" 合计："<< currentTotalPrice << endl;

        totalNum += num;
        totalPrice += currentTotalPrice;
        cout << "totalPrice: "<<totalPrice<<" totalNum:"<<totalNum<<endl<<endl;
    }

    return 0;
}
