/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-06-05 20:12:37
 * @LastEditors: Clark
 * @LastEditTime: 2022-06-19 16:14:11
 * @Description: file content
 */

#include <string>
#include <cctype>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
append
assign
back
compare
copy
c_str
erase
find
find_first_of
find_first_not_of
find_last_of
find_last_not_of
front
insert
length
size
replase
resize
substr
swap
*/

static void test1_init()
{
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    string s5(s4);
    string s6("tanxiaohai");

    cout<<"s1: "<<s1<<endl;
    cout<<"s2: "<<s2<<endl;
    cout<<"s3: "<<s3<<endl;
    cout<<"s4: "<<s4<<endl;
    cout<<"s5: "<<s5<<endl;
    cout<<"s6: "<<s6<<endl;
    printf("print:[%s]\n", s6.c_str());

    // 相加
    auto s7 = s5 + s6;
    cout<<"s7: "<<s7<<endl;
    cout<<"empty["<<s7.empty()<<"]"<<"size("<<s7.size()<<")"<<endl;

    // 相等
    if (s5 == s6)
        cout<<"s5["<<s5<<"] == s6["<<s6<<"]"<<endl;
    else
        cout<<"s5["<<s5<<"] != s6["<<s6<<"]"<<endl;

    // 从流中获取一行
    string s8;
    while(getline(cin, s8))
    {
        if (!s8.empty())
        {
            auto len = s8.size();
            cout<<"len: "<<len<<" "<<s8<<endl;
        }
    }


}

static void test2_properties()
{
    string s = "abc123";
    char c = 'a';
    // 字母或数字
    cout<<"isalnum[1]: "<<isalnum('1')<<endl;
    cout<<"isalnum[a]: "<<isalnum('a')<<endl;
    cout<<"isalnum[?]: "<<isalnum('?')<<endl;

    // 字母
    cout<<"isalpha[x]: "<<isalpha('x')<<endl;
    cout<<"isalpha[1]: "<<isalpha('1')<<endl;

    // 数字
    cout<<"isdigit[1]: "<<isdigit('1')<<endl;
    cout<<"isdigit[A]: "<<isdigit('A')<<endl;

    // 十六进制数字
    cout<<"isxdigit[1]: "<<isxdigit('1')<<endl;
    // cout<<"isxdigit[0x1]: "<<isxdigit("0x1")<<endl;

    // 小写字母
    cout<<"islower[a]: "<<islower('a')<<endl;
    cout<<"islower[A]: "<<islower('A')<<endl;

    // 大写字母
    cout<<"isupper[a]: "<<isupper('a')<<endl;
    cout<<"isupper[A]: "<<isupper('A')<<endl;

    // 空格
    cout<<"isspace[A]: "<<isspace('A')<<endl;
    cout<<"isspace[' ']: "<<isspace(' ')<<endl;

    // 大小写转换
    cout<<"tolower[A] :"<<tolower('A')<<endl;
    cout<<"toupper[a] :"<<toupper('a')<<endl;

    string name = "tanxiaohai520";
    for (auto &c : name)
    {
        if (islower(c))
        {
            c = toupper(c);
        }
    }
    cout<<"tanxiaohai520 :"<<name<<endl;
}

static void test3_size_length()
{
    string s{"tanxiaohai"};
    cout<<s<<endl;

    cout<<"size :"<<s.size()<<" length :"<<s.length()<<endl;
}

int main()
{
    // test1_init();
    // test2_properties();
    test3_size_length();
    return 0;
}
