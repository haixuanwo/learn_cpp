/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-22 15:27:41
 * @Description: file content
 */
#include <string>
#include <iostream>
using namespace std;

class TestPaperA
{
public:
    void test_question1()
    {
        cout << "杨过得到，后来给郭靖，练成倚天剑、屠龙刀的玄铁可能是[ ] a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维" << endl;
        cout << "答案是：b" << endl;
    }

    void test_question2()
    {
        cout << "杨过、程英、陆无双铲除了情花，造成[ ] a.使这种植物不再害人 b.使一种珍稀物种灭绝c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化" << endl;
        cout << "答案是：a" << endl;
    }

    void test_question3()
    {
        cout << "蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药[ ] a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量的生牛奶 e.以上全不对" << endl;
        cout << "答案是：c" << endl;
    }
};

class TestPaperB
{
public:
    void test_question1()
    {
        cout << "杨过得到，后来给郭靖，练成倚天剑、屠龙刀的玄铁可能是[ ] a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维" << endl;
        cout << "答案是：d" << endl;
    }

    void test_question2()
    {
        cout << "杨过、程英、陆无双铲除了情花，造成[ ] a.使这种植物不再害人 b.使一种珍稀物种灭绝c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化" << endl;
        cout << "答案是：b" << endl;
    }

    void test_question3()
    {
        cout << "蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药[ ] a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量的生牛奶 e.以上全不对" << endl;
        cout << "答案是：a" << endl;
    }
};

int main(int argc, char *argv[])
{

    cout << "学生甲抄的试卷：" << endl;
    TestPaperA *studentA = new TestPaperA();
    studentA->test_question1();
    studentA->test_question2();
    studentA->test_question3();

    cout << "学生乙抄的试卷：" << endl;
    TestPaperB *studentB = new TestPaperB();
    studentB->test_question1();
    studentB->test_question2();
    studentB->test_question3();

    return 0;
}
