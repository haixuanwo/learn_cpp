/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-28 15:15:01
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Context
{
public:
    void set_text(string text)
    {
        this->text = text;
    }

    string get_text()
    {
        return text;
    }

private:
    string text;
};

class Expression
{
public:
    void interpret(Context *context)
    {
        stringstream ss;
        string key;
        double value;

        string remainText = context->get_text();
        ss << remainText;
        ss >> key >> value;

        remainText = remainText.substr(remainText.find(" ") + 1);
        remainText = remainText.substr(remainText.find(" ") + 1);

        if (remainText.length() < 3)
        {
            remainText = "";
        }

        context->set_text(remainText);
        excute(key, value);
    }

    virtual void excute(string, double) = 0;

    ~Expression() { }
};

class Scale : public Expression
{
public:
    void excute(string key, double value)
    {
        switch ((int)value)
        {
            case 1:
            {
                cout << "bass " << endl;
                break;
            }
            case 2:
            {
                cout << "alto " << endl;
                break;
            }
            case 3:
            {
                cout << "treble " << endl;
                break;
            }
            default:
            {
                break;
            }
        }
    }
};

class Note : public Expression
{
public:
    void excute(string key, double value)
    {
        cout << key[0] << endl;
    }
};

class ExpressionFactory
{
public:
    Expression *create_expression(Context *context)
    {
        char key = context->get_text()[0];
        if ('O' == key)
        {
            return new Scale();
        }
        else
        {
            return new Note();
        }
    }
};

int main()
{
    ExpressionFactory *expression_factory_ = new ExpressionFactory();
    Context *context_ = new Context();
    context_->set_text("O 2 E 0.5 G 0.5 A 3");

    while(context_->get_text().length())
    {
        Expression *expression_ = expression_factory_->create_expression(context_);
        expression_->interpret(context_);
        delete expression_;
    }

    return 0;
}
