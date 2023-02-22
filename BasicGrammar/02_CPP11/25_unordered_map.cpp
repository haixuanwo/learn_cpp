
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

typedef enum{
    FUNC_ADD,
    FUNC_MINUS,
}FuncId;

int add(int lhs, int rhs, const string &info)
{
    int value = lhs + rhs;
    cout<<info<<" add func lhs["<<lhs<<"] + rhs["<<rhs<<"]"<<" = "<<value<<endl;
    return value;
}

int sub(int lhs, int rhs, const string &info)
{
    int value = lhs - rhs;
    cout<<info<<" minus func lhs["<<lhs<<"] - rhs["<<rhs<<"]"<<" = "<<value<<endl;
    return value;
}

using callback = std::function<int(int lhs, int rhs, const string &info)>;

int main()
{
    unordered_map<FuncId, callback> funcMap = {
        {FUNC_ADD, add},
        {FUNC_MINUS, sub}
    };

    funcMap[FUNC_ADD](1, 2, "txh");
    funcMap[FUNC_MINUS](3, 4, "thf");
    return 0;
}
