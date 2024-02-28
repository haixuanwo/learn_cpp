/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 13:45:26
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class WebSite
{
public:
    WebSite(string name)
    {
        this->name = name;
    }

    void use()
    {
        cout << "网站分类：" << name << endl;
    }

private:
    string name;
};

int main()
{
    WebSite *fx = new WebSite("产品展示");
    fx->use();

    WebSite *fy = new WebSite("产品展示");
    fy->use();

    WebSite *fz = new WebSite("产品展示");
    fz->use();

    WebSite *fl = new WebSite("博客");
    fl->use();

    WebSite *fm = new WebSite("博客");
    fm->use();

    WebSite *fn = new WebSite("博客");
    fn->use();

    return 0;
}
