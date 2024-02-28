/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 23:57:26
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Barbecure
{
public:
    void bake_mutton()
    {
        cout << "烤羊肉串！" << endl;
    }

    void bake_chicken_wing()
    {
        cout << "烤鸡翅！" << endl;
    }
};

int main()
{
    Barbecure *boy = new Barbecure();
    boy->bake_mutton();
    boy->bake_mutton();
    boy->bake_mutton();
    boy->bake_chicken_wing();
    boy->bake_mutton();
    boy->bake_mutton();
    boy->bake_chicken_wing();

    return 0;
}
