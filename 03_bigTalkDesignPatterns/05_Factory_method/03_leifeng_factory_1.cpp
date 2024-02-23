/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 09:33:53
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 11:37:47
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

class Voluntee : public LeiFeng
{
public:

};

enum{
    UNDERGRADUATE,
    VOLUNTEE,
};

class SimpleFactory
{
public:
    static LeiFeng *create_leifeng(char type)
    {
        switch (type)
        {
            case UNDERGRADUATE:
            {
                return new Undergraduate();
            }
            case VOLUNTEE:
            {
                return new Voluntee();
            }
        }

        return nullptr;
    }
};

int main()
{
    LeiFeng *studentA = SimpleFactory::create_leifeng(UNDERGRADUATE);
    studentA->buy_rice();

    LeiFeng *studentB = SimpleFactory::create_leifeng(UNDERGRADUATE);
    studentB->sweep();

    LeiFeng *studentC = SimpleFactory::create_leifeng(UNDERGRADUATE);
    studentC->wash();

    return 0;
}
