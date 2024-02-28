/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-28 12:52:10
 * @Description: file content
 */

#include <map>
#include <string>
#include <iostream>
using namespace std;

class WebSite
{
public:
    virtual void use() = 0;
};

class ConcreteWebSite : public WebSite
{
public:
    ConcreteWebSite(string name)
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

class WebSiteFactory
{
public:
    WebSiteFactory()
    {
    }

    WebSite *get_webSite_category(string key)
    {
        if (flyweights.end() == flyweights.find(key))
        {
            flyweights[key] = new ConcreteWebSite(key);
        }

        return flyweights[key];
    }

    int get_webSite_count()
    {
        return flyweights.size();
    }

private:
    map<string, WebSite *> flyweights;
};

int main()
{
    WebSiteFactory *f = new WebSiteFactory();

    WebSite *fx = f->get_webSite_category("产品展示");
    fx->use();

    WebSite *fy = f->get_webSite_category("产品展示");
    fy->use();

    WebSite *fz = f->get_webSite_category("产品展示");
    fz->use();

    WebSite *fl = f->get_webSite_category("博客");
    fl->use();

    WebSite *fm = f->get_webSite_category("博客");
    fm->use();

    WebSite *fn = f->get_webSite_category("博客");
    fn->use();

    cout << "网站分类总数为：" << f->get_webSite_count() << endl;

    return 0;
}
