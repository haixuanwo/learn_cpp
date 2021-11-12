/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2021-11-12 15:30:02
 * @LastEditors: Clark
 * @LastEditTime: 2021-11-12 16:47:42
 * @Description: 书籍销售类
 */

#include "06_sales_item.h"


std::string SalesItem::get_isbn()
{
    return isbn;
}

std::ostream& operator <<(std::ostream& out, SalesItem &salesItem)
{
    std::cout<<salesItem.isbn<<" "<<salesItem.saledNum<<" "<<salesItem.unitPrice;
    return out;
}

std::istream& operator >>(std::istream& in, SalesItem &salesItem)
{
    std::cin>>salesItem.isbn>>salesItem.saledNum>>salesItem.unitPrice;
    return in;
}


int test()
{
    // 测试输入
    SalesItem book;
    std::cin>>book;
    std::cout<<"book: "<<book<<std::endl;

    // 测试赋值
    SalesItem book1;
    book1 = book;
    std::cout<<"book1: "<<book1<<std::endl;

    // 测试加号
    SalesItem book2;
    SalesItem book3;

    std::cin>>book2;
    book3 = (book2 + book1);
    std::cout<<"book3: "<<book3<<std::endl;

    // 测试加等于
    SalesItem book4;
    std::cin>>book4;
    book4 += book3;
    std::cout<<"book4: "<<book4<<std::endl;

    return 0;
}

int main()
{
    // test();
    // return 0;

    SalesItem total; // 保存下一条交易记录的变量

    // 读入第一条记录，并确保有数据可以处理
    if (std::cin>>total)
    {
        SalesItem trans;    // 保存和的变量
        // 读入并处理剩余交易记录
        while (std::cin>>trans)
        {
            // 判断是否处理相同的书
            if (total.get_isbn() == trans.get_isbn())
            {
                total += trans; // 更新总销售额
            }
            else
            {
                // 打印前一本书的结果，开始记录下一本书
                std::cout<<total<<std::endl;
                total = trans;
            }
        }

        std::cout<<total<<std::endl; // 打印最后一本的结果
    }
    else
    {
        // 没有输入警告读者
        std::cerr<<"No data?!"<<std::endl;
        return -1;
    }
    return 0;
}
