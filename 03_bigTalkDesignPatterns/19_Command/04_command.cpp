/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 10:11:13
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Receiver
{
public:
    void action()
    {
        cout << "执行请求！" << endl;
    }
};

class Command
{
public:
    Command(Receiver *receiver)
    {
        this->receiver = receiver;
    }

    virtual void execute() = 0;

// private:
    Receiver *receiver;
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver *receiver) : Command(receiver)
    {
    }

    void execute()
    {
        receiver->action();
    }
};

class Invoker
{
public:
    void set_command(Command *command)
    {
        this->command = command;
    }

    void execute_command()
    {
        command->execute();
    }

private:
    Command *command;
};

int main()
{
    Receiver *r = new Receiver();
    Command *c = new ConcreteCommand(r);
    Invoker *i = new Invoker();

    i->set_command(c);
    i->execute_command();

    return 0;
}
