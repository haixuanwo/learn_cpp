/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 09:33:53
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 11:17:00
 * @Description: file content
 */

#include <iostream>
using namespace std;

class LeiFeng
{
public:
    void sweep()
    {
        cout << "扫地" << endl;
    }

    void wash()
    {
        cout << "洗衣" << endl;
    }

    void buy_rice()
    {
        cout << "买米" << endl;
    }
};

class Undergraduate : public LeiFeng
{
public:

};

int main()
{
    LeiFeng *xueleifeng = new Undergraduate();
    xueleifeng->buy_rice();
    xueleifeng->sweep();
    xueleifeng->wash();

    LeiFeng *student1 = new Undergraduate();
    student1->buy_rice();

    LeiFeng *student2 = new Undergraduate();
    student2->sweep();

    LeiFeng *student3 = new Undergraduate();
    student3->wash();

    return 0;
}
