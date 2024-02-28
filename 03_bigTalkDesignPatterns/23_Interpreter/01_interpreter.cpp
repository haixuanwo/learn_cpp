/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-28 14:03:29
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Context
{
public:
    void set_input(string input)
    {
        this->input = input;
    }

    string get_input()
    {
        return input;
    }

    void set_output(string output)
    {
        this->output = output;
    }

    string get_output()
    {
        return output;
    }

private:
    string input;
    string output;
};

class AbstractExpression
{
public:
    virtual void interpret(Context *context) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
    void interpret(Context *context)
    {
        cout << "终端解释器" << endl;
    }
};

class NonterExpression : public AbstractExpression
{
public:
    void interpret(Context *context)
    {
        cout << "非终端解释器" << endl;
    }
};

int main()
{
    Context *context = new Context();

    list<AbstractExpression *> l;
    l.push_back(new TerminalExpression());
    l.push_back(new NonterExpression());
    l.push_back(new TerminalExpression());
    l.push_back(new TerminalExpression());

    for (auto &&i : l)
    {
        i->interpret(context);
    }

    return 0;
}
