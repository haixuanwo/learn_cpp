/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 09:40:43
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Barbecure
{
public:
    void bake_mutton()
    {
        cout << "烤羊肉串！" << endl;
    }

    void bake_chicken_wing()
    {
        cout << "烤鸡翅！" << endl;
    }
};

class Command
{
public:
    Command(Barbecure *receiver)
    {
        this->receiver = receiver;
    }

    virtual void excute_command() = 0;

// private:
    Barbecure *receiver;
};

class BakeMuttonCommand : public Command
{
public:
    BakeMuttonCommand(Barbecure *receiver) : Command(receiver)
    {
    }

    void excute_command()
    {
        receiver->bake_mutton();
    }
};

class BakeChickenWingCommand : public Command
{
public:
    BakeChickenWingCommand(Barbecure *receiver) : Command(receiver)
    {
    }

    void excute_command()
    {
        receiver->bake_chicken_wing();
    }
};

class Waiter
{
public:
    void set_order(Command *command)
    {
        this->command = command;
    }

    void notify()
    {
        command->excute_command();
    }

private:
    Command *command;
};


int main()
{
    Barbecure *boy = new Barbecure();

    Command *bakeMuttonCommand1 = new BakeMuttonCommand(boy);
    Command *bakeMuttonCommand2 = new BakeMuttonCommand(boy);
    Command *BakeChickenWingCommand1 = new BakeChickenWingCommand(boy);

    Waiter *girl = new Waiter();
    girl->set_order(bakeMuttonCommand1);
    girl->notify();

    girl->set_order(bakeMuttonCommand2);
    girl->notify();

    girl->set_order(BakeChickenWingCommand1);
    girl->notify();

    return 0;
}
