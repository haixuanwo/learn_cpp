/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 11:10:10
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Context;

class State
{
public:
    virtual void handle(Context *context) = 0;
};

class Context
{
public:
    Context(State *state)
    {
        this->state = state;
    }

    void set_state(State *state)
    {
        this->state = state;
    }

    State *get_state()
    {
        return state;
    }

    void request()
    {
        state->handle(this);
    }

private:
    State *state;
};


class ConcreteStateA : public State
{
public:
    void handle(Context *context);
};

class ConcreteStateB : public State
{
public:
    void handle(Context *context);
};

void ConcreteStateA::handle(Context *context)
{
    context->set_state(new ConcreteStateB());
    cout << "ConcreteStateA handle" << endl;
}

void ConcreteStateB::handle(Context *context)
{
    context->set_state(new ConcreteStateA());
    cout << "ConcreteStateB handle" << endl;
}

int main()
{
    Context *c = new Context(new ConcreteStateA());
    c->request();
    c->request();
    c->request();
    c->request();

    return 0;
}
