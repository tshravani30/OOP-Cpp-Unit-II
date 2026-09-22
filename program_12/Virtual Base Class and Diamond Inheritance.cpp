#include <iostream>
// Provides cout.

#include <string>
// Provides string.

#include <utility>
// Provides move.


class Person
{
protected:

    std::string name;
    // Stores person's name.

public:

    explicit Person(std::string personName)
        : name(std::move(personName))
    {
        // Initializes name.
    }

    void displayName() const
    {
        std::cout << "Name: "
                  << name << '\n';
    }
};


class Student : virtual public Person
{
public:

    Student()
        : Person("Unknown")
    {
        // Constructor for Student.
    }
};


class Employee : virtual public Person
{
public:

    Employee()
        : Person("Unknown")
    {
        // Constructor for Employee.
    }
};


class TeachingAssistant :
    public Student,
    public Employee
{
public:

    explicit TeachingAssistant(
        std::string assistantName)
        : Person(std::move(assistantName)),
          Student(),
          Employee()
    {
        // TeachingAssistant directly initializes
        // the shared virtual Person base.
    }
};


int main()
{
    TeachingAssistant assistant("Riya");
    // Creates TeachingAssistant object.

    assistant.displayName();
    // Uses the single shared Person part.

    return 0;
}
