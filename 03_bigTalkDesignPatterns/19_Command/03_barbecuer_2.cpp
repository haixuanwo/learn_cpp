/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-27 10:01:16
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
#include <ctime>
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
    Waiter()
    {
        commands = new list<Command *>();
    }

    void set_order(Command *command)
    {
        if (typeid(BakeChickenWingCommand) == typeid(*command))
        {
            cout << "服务员：鸡翅没有了，请点别的烧烤。" << endl;
        }
        else
        {
            time_t now = time(nullptr);
            commands->push_back(command);
            std::cout << "增加订单: " << std::string(typeid(*command).name()).substr(2)
               << " 时间："<< ctime(&now) << std::endl;
        }
    }

    void cancel_order(Command *command)
    {
        list<Command *>::iterator itList;

        for (itList = commands->begin(); itList != commands->end();)
        {
            if (command == *itList)
            {
                itList = commands->erase( itList);
                break;
            }
            else
            {
                itList++;
            }
        }
    }

    void notify()
    {
        for (auto &&command : *commands)
        {
            command->excute_command();
        }
    }

private:
    list<Command *> *commands;
};


int main()
{
    Barbecure *boy = new Barbecure();

    Command *bakeMuttonCommand1 = new BakeMuttonCommand(boy);
    Command *bakeMuttonCommand2 = new BakeMuttonCommand(boy);
    Command *BakeChickenWingCommand1 = new BakeChickenWingCommand(boy);

    Waiter *girl = new Waiter();
    girl->set_order(bakeMuttonCommand1);
    girl->set_order(bakeMuttonCommand2);
    girl->set_order(BakeChickenWingCommand1);
    girl->notify();

    return 0;
}
