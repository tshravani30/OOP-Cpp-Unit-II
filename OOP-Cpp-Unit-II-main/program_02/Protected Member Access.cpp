#include <iostream>       // Provides std::cout.
#include <string>         // Provides std::string.
#include <utility>        // Provides std::move.


// ---------------- BASE CLASS ----------------
class Employee
{
protected:

    std::string name;
    // Protected variable.
    // Developer can directly access this variable.

public:

    explicit Employee(std::string employeeName)
        : name(std::move(employeeName))
    {
        // Employee constructor.
        // Stores employeeName inside name.
    }
};


// ---------------- DERIVED CLASS ----------------
class Developer : public Employee
{
private:

    std::string language;
    // Private variable storing programming language.

public:

    Developer(std::string employeeName,
              std::string programmingLanguage)
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage))
    {
        // Calls Employee constructor.
        // Initializes language.
    }

    void display() const
    {
        // Displays Developer information.

        std::cout << "Developer: " << name << '\n';
        // name is protected in Employee,
        // so Developer can access it directly.

        std::cout << "Language: " << language << '\n';
        // Displays programming language.
    }
};


int main()
{
    Developer developer("Neha", "C++");
    // Creates Developer object.

    developer.display();
    // Displays developer information.

    return 0;
}
