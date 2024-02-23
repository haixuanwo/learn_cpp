/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 16:05:22
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

//股票1
class Stock1
{
public:
    //卖股票
    void sell()
    {
        cout << " 股票1卖出" << endl;
    }

    //买股票
    void buy()
    {
        cout << " 股票1买入" << endl;
    }
};

class Stock2
{
public:
    //卖股票
    void sell()
    {
        cout << " 股票2卖出" << endl;
    }

    //买股票
    void buy()
    {
        cout << " 股票2买入" << endl;
    }
};

class Stock3
{
public:
    //卖股票
    void sell()
    {
        cout << " 股票3卖出" << endl;
    }

    //买股票
    void buy()
    {
        cout << " 股票3买入" << endl;
    }
};

class NationalDebt1
{
public:
    void sell()
    {
        cout << " 国债1卖出" << endl;
    }

    void buy()
    {
        cout << " 国债1买入" << endl;
    }
};

class Realty1
{
public:
    void sell()
    {
        cout << " 房地产1卖出" << endl;
    }

    void buy()
    {
        cout << " 房地产1买入" << endl;
    }
};

class Fund
{
public:
    Fund()
    {
        gu1 = new Stock1();
        gu2 = new Stock2();
        gu3 = new Stock3();
        nd1 = new NationalDebt1();
        rt1 = new Realty1();
    }

    void buy_fund()
    {
        gu1->buy();
        gu2->buy();
        gu3->buy();
        nd1->buy();
        rt1->buy();
    }

    void sell_fund()
    {
        gu1->sell();
        gu2->sell();
        gu3->sell();
        nd1->sell();
        rt1->sell();
    }

private:
    Stock1 *gu1;
    Stock2 *gu2;
    Stock3 *gu3;
    NationalDebt1 *nd1;
    Realty1 *rt1;
};

int main()
{
    Fund *jijin = new Fund();
    jijin->buy_fund();
    jijin->sell_fund();

    return 0;
}
