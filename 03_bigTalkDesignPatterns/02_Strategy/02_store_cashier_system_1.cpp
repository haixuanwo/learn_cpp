/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 11:47:21
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-20 14:24:02
 * @Description: file content
 */

/*
记录商品清单，统计商品总数与总价
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int totalNum = 0;
    double totalPrice = 0.0;

    string CalculationMethod[] = {"【1】：正常收费", "【2】：满300返100", "【3】：打8折"};

    while (1)
    {
        cout << "请输入商品单价:" << endl;
        double unitPrice = 0;
        cin>>unitPrice;

        cout << "请输入商品数量：" << endl;
        int num = 0;
        cin>>num;

        cout << "请选择计算方式："<<"\n"
            << CalculationMethod[0]<<"\n"
            << CalculationMethod[1]<<"\n"
            << CalculationMethod[2]<<endl;

        int calculationMethodIndex = 0;
        cin>>calculationMethodIndex;

        double currentTotalPrice = 0;
        switch(calculationMethodIndex)
        {
            case 1:
            {
                currentTotalPrice = unitPrice * num;
                cout <<"单价："<<unitPrice<<" 数量："<<num<<" 正常收费，合计："<< currentTotalPrice << endl;
                break;
            }
            case 2:
            {
                currentTotalPrice = unitPrice * num;
                currentTotalPrice -= currentTotalPrice/300*100;
                cout <<"单价："<<unitPrice<<" 数量："<<num<<" 满300减100，合计："<< currentTotalPrice << endl;
                break;
            }
            case 3:
            {
                currentTotalPrice = unitPrice * num;
                currentTotalPrice *= 0.8;
                cout <<"单价："<<unitPrice<<" 数量："<<num<<" 打8折，合计："<< currentTotalPrice << endl;
                break;
            }
        }

        totalNum += num;
        totalPrice += currentTotalPrice;
        cout << "totalPrice: "<<totalPrice<<" totalNum:"<<totalNum<<endl<<endl;
    }

    return 0;
}
