#include <iostream>
// Provides cout.


class Base
{
public:

    Base()
    {
        // Base constructor.

        std::cout << "Base constructor\n";
    }

    ~Base()
    {
        // Base destructor.

        std::cout << "Base destructor\n";
    }
};


class Derived : public Base
{
public:

    Derived()
    {
        // Derived constructor.

        std::cout << "Derived constructor\n";
    }

    ~Derived()
    {
        // Derived destructor.

        std::cout << "Derived destructor\n";
    }
};


int main()
{
    Derived object;
    // Creating Derived object first calls Base constructor,
    // then Derived constructor.

    return 0;
    // Before program ends, destructors are called.
}
