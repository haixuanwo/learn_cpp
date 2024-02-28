/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 15:01:32
 * @Description: file content
 */

#include <list>
#include <string>
#include <iostream>
using namespace std;

class Memento
{
public:
    Memento(string state)
    {
        this->state = state;
    }

    void set_state(string state)
    {
        this->state = state;
    }

    string get_state()
    {
        return state;
    }

private:
    string state;
};

class Originator
{
public:
    void set_state(string state)
    {
        this->state = state;
    }

    string get_state()
    {
        return state;
    }

    Memento *create_memento()
    {
        return new Memento(state);
    }

    void set_memento(Memento *memento)
    {
        state = memento->get_state();
    }

    void show()
    {
        cout << "State = " << state << endl;
    }
private:
    string state;
};

class Caretaker
{
public:
    void set_memento(Memento *memento)
    {
        this->memento = memento;
    }

    Memento *get_memento()
    {
        return memento;
    }

private:
    Memento *memento;
};

int main()
{
    Originator *o = new Originator();
    o->set_state("On");
    o->show();

    Caretaker *c = new Caretaker();
    c->set_memento(o->create_memento());

    o->set_state("Off");
    o->show();

    o->set_memento(c->get_memento());
    o->show();

    return 0;
}
