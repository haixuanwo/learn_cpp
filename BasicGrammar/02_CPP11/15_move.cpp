#include <iostream>
using namespace std;


// move 将左值强制转化为右值

class CModeDemo
{
public:
    CModeDemo():num(new int(0))
    {
        cout<<"construct !"<<endl;
    }

    // 拷贝构造函数
    CModeDemo(const CModeDemo &d):num(new int(*d.num))
    {
        cout<<"copy construct!"<<endl;
    }

    // 移动构造函数
    CModeDemo(CModeDemo &&d):num(d.num)
    {
        d.num = NULL;
        cout<<"move construct!"<<endl;
    }

    ~CModeDemo()
    {
        cout<<"dis construct!"<<endl;
    }

    int *num;
};

int main(int argc, char * argv [ ])
{
    CModeDemo demo;
    cout<<"demo2:\n";
    CModeDemo demo2 = demo;

    cout<<"demo3:\n";
    CModeDemo demo3 = std::move(demo);
    demo = demo2; // 报错
    //cout<<*(demo.num)<<endl;
    return 0;
}

