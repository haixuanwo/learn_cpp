/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-12 15:13:22
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-12 16:44:17
 * @Description:书店程序显示销售额、售出册数、平均售价
 */

#ifndef SALES_ITEM
#define SALES_ITEM

#include <string>
#include <iostream>
// #include <ostream>
// #include <istream>

class SalesItem
{
public:
    std::string get_isbn();
    friend std::ostream& operator <<(std::ostream& out, SalesItem &salesItem);
	friend std::istream& operator >>(std::istream& in, SalesItem &salesItem);
    SalesItem operator=(const SalesItem &salesItem)
    {
        if (this == &salesItem)
            return *this;

        this->isbn = salesItem.isbn;
        this->saledNum = salesItem.saledNum;
        this->unitPrice = salesItem.unitPrice;

        return *this;
    }

    SalesItem operator +(const SalesItem &salesItem)
    {
        SalesItem tmpSalesItem;

        tmpSalesItem.isbn = this->isbn;
        tmpSalesItem.saledNum = this->saledNum + salesItem.saledNum;

        tmpSalesItem.unitPrice = (this->unitPrice*this->saledNum
                                    + salesItem.unitPrice*salesItem.saledNum)
                                    / tmpSalesItem.saledNum;


        return tmpSalesItem;
    }

    SalesItem operator +=(const SalesItem &salesItem)
    {
        unsigned int preSaledNum = this->saledNum;
        this->saledNum = this->saledNum + salesItem.saledNum;
        this->unitPrice = (this->unitPrice*preSaledNum
                                    + salesItem.unitPrice*salesItem.saledNum)
                                    / this->saledNum;

        return *this;
    }

private:
    std::string isbn;       // 书唯一标识号
    unsigned int saledNum;  // 售出册数
    float unitPrice;        // 书本单价
};

#endif
