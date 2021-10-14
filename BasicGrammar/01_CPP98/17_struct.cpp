
#include <iostream>
using namespace std;

struct A
{
    // 默认为public
    int id;

    void sleep()
    {
        cout<<"sleep"<<endl;
    }
};

int main()
{
    struct A a;
    a.id = 200;

    cout<<a.id<<endl;
    a.sleep();
    cout<<sizeof(a)<<endl;

    return 0;
}

