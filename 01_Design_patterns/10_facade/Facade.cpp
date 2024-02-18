
#include <iostream>

class SubsystemA
{
public:
    SubsystemA()
    {
        std::cout << "SubsystemA" << std::endl;
    }

    void suboperation()
    {
        std::cout << "Subsystem A method" << std::endl;
    }
};

class SubsystemB
{
public:
    SubsystemB()
    {
        std::cout << "SubsystemB" << std::endl;
    }

    void suboperation()
    {
        std::cout << "Subsystem B method" << std::endl;
    }
};

class SubsystemC
{
public:
    SubsystemC()
    {
        std::cout << "SubsystemC" << std::endl;
    }

    void suboperation()
    {
        std::cout << "Subsystem C method" << std::endl;
    }
};

class Facade
{
public:
    // 在构造函数中，虽然没有显式地进行实例化，但指针被赋值为子系统对象的地址。因此，指针指向了有效的内存位置，可以通过指针来访问子系统对象的成员函数。
    Facade() : subsystemA(), subsystemB(), subsystemC()
    // Facade() : subsystemA(new SubsystemA()), subsystemB(new SubsystemB()), subsystemC(new SubsystemC())
    {
        std::cout << "Facade" << std::endl;
    }

    void operation1()
    {
        subsystemA->suboperation();
        subsystemB->suboperation();
    }

    void operation2()
    {
        subsystemC->suboperation();
    }

private:
    SubsystemA *subsystemA;
    SubsystemB *subsystemB;
    SubsystemC *subsystemC;
};

int main()
{
    Facade *facade = new Facade();

    facade->operation1();
    facade->operation2();

    delete facade;
    return 0;
}
