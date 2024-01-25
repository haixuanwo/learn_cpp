/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-17 14:24:38
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-24 22:20:05
 * @Description: file content
 */

/**
 * @brief
 * 抽象产品、具体产品
 * 抽象工厂、具体工厂
 *
 */

#include <iostream>
using std::cout;
using std::endl;

class ProductA
{
public:
    ~ProductA() { }
    virtual const char* getName() = 0;
};

class ConcreteProductAX : public ProductA
{
public:
    ~ConcreteProductAX() { }

    const char* getName()
    {
        return "A-X";
    }
};

class ConcreteProductAY : public ProductA
{
public:
    ~ConcreteProductAY() { }

    const char* getName()
    {
        return "A-Y";
    }
};

class ProductB
{
public:
    ~ProductB() { }
    virtual const char* getName() = 0;
};

class ConcreteProductBX : public ProductB
{
public:
    ~ConcreteProductBX() { }

    const char* getName()
    {
        return "B-X";
    }
};

class ConcreteProductBY : public ProductB
{
public:
    ~ConcreteProductBY() { }

    const char* getName()
    {
        return "B-Y";
    }
};

class AbstractFactory
{
public:
    virtual ~AbstractFactory() {};
    virtual ProductA *createProductA() = 0;
    virtual ProductB *createProductB() = 0;
};

class ConcreteFactoryX : public AbstractFactory
{
public:
    ~ConcreteFactoryX() {};

    ProductA *createProductA()
    {
        return new ConcreteProductAX;
    }

    ProductB *createProductB()
    {
        return new ConcreteProductBX;
    }
};

class ConcreteFactoryY : public AbstractFactory
{
public:
    ~ConcreteFactoryY() {};

    ProductA *createProductA()
    {
        return new ConcreteProductAY;
    }

    ProductB *createProductB()
    {
        return new ConcreteProductBY;
    }
};

int main()
{
    AbstractFactory *factoryX = new ConcreteFactoryX();
    AbstractFactory *factoryY = new ConcreteFactoryY();

    ProductA *productXA = factoryX->createProductA();
    ProductB *productXB = factoryX->createProductB();

    ProductA *productYA = factoryY->createProductA();
    ProductB *productYB = factoryY->createProductB();

    cout << productXA->getName() << endl;
    cout << productXB->getName() << endl;
    cout << productYA->getName() << endl;
    cout << productYB->getName() << endl;

    delete factoryX;
    delete factoryY;
    delete productXA;
    delete productXB;
    delete productYA;
    delete productYB;

    return 0;
}
