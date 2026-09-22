#include <iostream>
// Includes the input/output library for cout.


// ---------------- BASE CLASS ----------------
class Base
{
public:

    void show() const
    {
        // Public function of Base class.

        std::cout << "Base public function\n";
        // Displays a message.
    }
};


// ---------------- PUBLIC INHERITANCE ----------------
class PublicDerived : public Base
{
    // Base's public members remain public.
};


// ---------------- PRIVATE INHERITANCE ----------------
class PrivateDerived : private Base
{
public:

    void callBaseShow() const
    {
        // This function is inside PrivateDerived.

        show();
        // Calls Base's show().
        // It is accessible internally because of inheritance.
    }
};


int main()
{
    PublicDerived publicObject;
    // Creates an object of PublicDerived.

    publicObject.show();
    // Valid because show() remains public.

    PrivateDerived privateObject;
    // Creates an object of PrivateDerived.

    privateObject.callBaseShow();
    // Valid because callBaseShow() is public.

    // privateObject.show();
    // ERROR:
    // show() became private through private inheritance.

    return 0;
}
