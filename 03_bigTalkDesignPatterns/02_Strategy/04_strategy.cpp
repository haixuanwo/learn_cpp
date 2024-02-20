/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-20 14:55:02
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-20 15:03:44
 * @Description: file content
 */

#include <iostream>
using namespace std;

class Strategy
{
public:
    virtual void algorithm_interface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    void algorithm_interface()
    {
        cout << "ConcreteStrategyA" << endl;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    void algorithm_interface()
    {
        cout << "ConcreteStrategyB" << endl;
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    void algorithm_interface()
    {
        cout << "ConcreteStrategyC" << endl;
    }
};

class Context
{
public:
    Context(Strategy *strategy)
    {
        _strategy = strategy;
    }

    void context_interface()
    {
        _strategy->algorithm_interface();
    }

    Strategy *_strategy;
};

int main()
{
    Context *context;

    context = new Context(new ConcreteStrategyA());
    context->context_interface();
    delete context;

    context = new Context(new ConcreteStrategyB());
    context->context_interface();
    delete context;

    context = new Context(new ConcreteStrategyC());
    context->context_interface();
    delete context;

    return 0;
}
