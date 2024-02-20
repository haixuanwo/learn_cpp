/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 11:47:21
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-20 14:48:16
 * @Description: file content
 */

/*
记录商品清单，统计商品总数与总价
*/

#include <iostream>
#include <string>
using namespace std;

class CashSuper
{
public:
    virtual double accept_cash(double money) = 0;
};

class CashNormal: public CashSuper
{
public:
    double accept_cash(double money)
    {
        return money;
    }
};

class CashRebate: public CashSuper
{
public:
    CashRebate(double moneyRebate)
    {
        _moneyRebate = moneyRebate;
    }

    double accept_cash(double money)
    {
        return money*_moneyRebate;
    }

private:
    double _moneyRebate;
};

class CashReturn: public CashSuper
{
public:
    CashReturn(double moneyCondition, double moneyReturn)
    {
        _moneyReturn = moneyReturn;
        _moneyCondition = moneyCondition;
    }

    double accept_cash(double money)
    {
        if (money >= _moneyCondition)
        {
            money -= money/_moneyCondition*_moneyReturn;
        }

        return money;
    }

private:
    double _moneyReturn;
    double _moneyCondition;
};

// "【1】：正常收费", "【2】：满300返100", "【3】：打8折"
enum{
    CASH_NORMAL = 1,
    CASH_RETURN,
    CASH_REBATE,
};

class CashFactory
{
public:
    CashSuper* create_cash_super(int calculateMethod)
    {
        switch (calculateMethod)
        {
            case CASH_NORMAL:
            {
                return new CashNormal();
            }
            case CASH_REBATE:
            {
                cout << "请输入打折率:";
                double moneyRebate = 1;
                cin>>moneyRebate;
                return new CashRebate(moneyRebate);
            }
            case CASH_RETURN:
            {
                cout << "请输入返减条件:";
                double moneyCondition = 0;
                cin>>moneyCondition;

                cout << "请输入返减额度:";
                double moneyReturn = 0;
                cin>>moneyReturn;
                return new CashReturn(moneyCondition, moneyReturn);
            }
            default:
            {
                return nullptr;
            }
        }
    }
};

int main()
{
    int totalNum = 0;
    double totalPrice = 0.0;

    string calculationMethod[] = {"【1】：正常收费", "【2】：满金额返减", "【3】：打折"};

    while (1)
    {
        cout << "请输入商品单价:" << endl;
        double unitPrice = 0;
        cin>>unitPrice;

        cout << "请输入商品数量：" << endl;
        int num = 0;
        cin>>num;

        cout << "请选择计算方式："<<"\n"
            << calculationMethod[0]<<"\n"
            << calculationMethod[1]<<"\n"
            << calculationMethod[2]<<endl;

        int calculationMethodIndex = 0;
        cin>>calculationMethodIndex;

        double currentTotalPrice = 0;

        CashFactory cashFactory;
        CashSuper *cashSuper = cashFactory.create_cash_super(calculationMethodIndex);

        currentTotalPrice = unitPrice * num;
        currentTotalPrice = cashSuper->accept_cash(currentTotalPrice);
        delete cashSuper;

        cout <<"单价："<<unitPrice<<" 数量："<<num<<calculationMethod[calculationMethodIndex-1]<<"，合计："<< currentTotalPrice << endl;

        totalNum += num;
        totalPrice += currentTotalPrice;
        cout << "totalPrice: "<<totalPrice<<" totalNum:"<<totalNum<<endl<<endl;
    }

    return 0;
}
