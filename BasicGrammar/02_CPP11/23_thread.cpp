/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-07-01 12:48:11
 * @LastEditors: Clark
 * @LastEditTime: 2022-07-01 13:03:09
 * @Description: file content
 */

#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
using namespace std;

mutex m;

void f(const vector<double>& v, double *res)
{
    if (0 == v.size())
    {
        *res = 0;
    }
    else
    {
        *res = v[0];
    }

    unique_lock<mutex> lck{m};
    cout<<"I'm f() res["<<*res<<"]"<<endl;
}

//struct F{
class F{
public:
    F(const vector<double>& vv, double *p):v{vv},res{p}{}
    void operator()()
    {
        if (0 == v.size())
        {
            *res = 0;
        }
        else
        {
            *res = v[0];
        }

        unique_lock<mutex> lck{m};
        cout<<"I'm F() res["<<*res<<"]"<<endl;
    }

private:
    const vector<double>& v;
    double *res;
};

void user()
{
    double res1;
    double res2;
    vector<double> v1;
    vector<double> v2;

    for (size_t i = 0; i < 5; i++)
    {
        v1.push_back(1.123);
        v2.push_back(1.123);
    }

    thread t1 {f, v1, &res1};
    thread t2 {F{v2, &res2}};

    t1.join();
    t2.join();
}

int main()
{
    user();
}
