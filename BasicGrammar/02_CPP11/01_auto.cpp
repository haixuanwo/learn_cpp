/**
 * @author haixuanwo
 * @email haixuanwo_clark@hotmail.com
 * @date 2020-07-11
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief auto关键字，自动类型推导
 * 1、在定义时必须初始化
 * 2、
 */

int main()
{
    // 1、自动类型推导
    auto v = new vector<int>;
    v->push_back(1);
    v->push_back(2);
    cout<<v->back()<<"\t"<<v->front()<<endl;

    // 2、与具体类型混合使用
    int x = 100;
    auto *p = &x;
    const auto y = x;
    cout<<"x:"<<*p<<"\t y:"<<y<<endl;

    // 3、auto的限制
    // （1）必须在定义时初始化
    // （2）不能在参数中使用
    // （3）在类中不能修饰非静态成员
    // （4）不能定义数组 auto array[] = {1, 2}
    // （5）不能作用于模板 A<auto>
    // （6）应用容器迭代器、泛型编程

    // 4、auto对CV限定符推导规则：指针或引用保留，其他丢弃
    const int a = 100;
    auto b = a;
    b = 120;

    const int *p_ = &a;
    auto q = p_;
    //*q = 110;

    // 5、抛弃引用类型，直接推导出原始类型
    int &m = x;
    auto n = m;
    n = 119;
    cout<<"m = "<<m<<"\t"<<"n = "<<n<<endl;

    return 0;
}

