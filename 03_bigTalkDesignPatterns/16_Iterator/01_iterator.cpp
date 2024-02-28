/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-22 11:57:08
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-26 17:42:38
 * @Description: file content
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class ConcreteAggregate;

class Iterator
{
public:
    virtual ~Iterator() { }
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool is_done() const = 0;
    virtual int current_item() const = 0;
};

class Aggregate
{
public:
    virtual ~Aggregate() { }
    virtual Iterator *create_iterator() = 0;
};

class ConcreteAggregate : public Aggregate
{
public:
  ConcreteAggregate(const unsigned int size)
  {
    list = new int[size]();
    count = size;
  }

  ~ConcreteAggregate()
  {
    delete[] list;
  }

  Iterator *create_iterator()
  {
    return nullptr;
  };

  unsigned int size() const
  {
    return count;
  }

  int at(unsigned int index)
  {
    return list[index];
  }

private:
  int *list;
  unsigned int count;
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(ConcreteAggregate *l) : list(l), index(0)
    {

    }

    ~ConcreteIterator()
    {

    }

    void first()
    {
        index = 0;
    }

    void next()
    {
        index++;
    }

    bool is_done() const
    {
        return (index >= list->size());
    }

    int current_item() const
    {
        if (is_done())
        {
            return -1;
        }

        return list->at(index);
    }

private:
    ConcreteAggregate *list;
    unsigned int index;
};

int main()
{
    unsigned int size = 5;
    ConcreteAggregate list = ConcreteAggregate(size);

    Iterator *it = list.create_iterator();
    while (!it->is_done())
    {
        cout << "Item value: " << it->current_item() << endl;
        it->next();
    }

    return 0;
}
