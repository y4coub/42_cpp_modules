#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

Base *generate(void)
{
    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    std::cout << "<--- Pointer --->" << std::endl;
    if (dynamic_cast<A *>(p))
        std::cout << "This is A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "This is B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "This is C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
    std::cout << "<--- ------- --->" << std::endl;
}

void identify(Base &p)
{
    std::cout << "<--- Reference --->" << std::endl;
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A cast succeeded" << std::endl;
    }
    catch (std::bad_cast &)
    {
        std::cout << "A cast failed" << std::endl;
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B cast succeeded" << std::endl;
    }
    catch (std::bad_cast &)
    {
        std::cout << "B cast failed" << std::endl;
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C cast succeeded" << std::endl;
    }
    catch (std::bad_cast &)
    {
        std::cout << "C cast failed" << std::endl;
    }
    std::cout << "<--- --------- --->" << std::endl;
}

int main()
{
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}