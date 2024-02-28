/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-28 12:57:09
 * @Description: file content
 */

#include <map>
#include <string>
#include <iostream>
using namespace std;

class User
{
public:
    User(string name)
    {
        this->name = name;
    }

    void set_name(string name)
    {
        this->name = name;
    }

    string get_name()
    {
        return name;
    }

private:
    string name;
};

class WebSite
{
public:
    virtual void use(User *user) = 0;
};

class ConcreteWebSite : public WebSite
{
public:
    ConcreteWebSite(string name)
    {
        this->name = name;
    }

    void use(User *user)
    {
        cout << "网站分类：" << name << "用户：" << user->get_name() << endl;
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
    fx->use(new User("小菜"));

    WebSite *fy = f->get_webSite_category("产品展示");
    fy->use(new User("大鸟"));

    WebSite *fz = f->get_webSite_category("产品展示");
    fz->use(new User("娇娇"));

    WebSite *fl = f->get_webSite_category("博客");
    fl->use(new User("老顽童"));

    WebSite *fm = f->get_webSite_category("博客");
    fm->use(new User("桃谷六仙"));

    WebSite *fn = f->get_webSite_category("博客");
    fn->use(new User("南海鳄神"));

    cout << "网站分类总数为：" << f->get_webSite_count() << endl;

    return 0;
}
