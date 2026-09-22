#include <iostream>       // Provides cout.
#include <string>         // Provides string.
#include <utility>        // Provides move.


class Person
{
protected:

    std::string name;
    // Protected name can be accessed by derived classes.

public:

    explicit Person(std::string personName)
        : name(std::move(personName))
    {
        // Initializes name.
    }

    void showPerson() const
    {
        // Displays person information.

        std::cout << "Name: " << name << '\n';
    }
};


class Employee : public Person
{
protected:

    int employeeId;
    // Stores employee ID.

public:

    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)),
          employeeId(id)
    {
        // Calls Person constructor.
        // Initializes employeeId.
    }

    void showEmployee() const
    {
        std::cout << "Employee ID: "
                  << employeeId << '\n';
    }
};


class Manager : public Employee
{
private:

    int teamSize;
    // Stores number of team members.

public:

    Manager(std::string managerName,
            int id,
            int size)
        : Employee(std::move(managerName), id),
          teamSize(size)
    {
        // Calls Employee constructor.
        // Initializes teamSize.
    }

    void showManager() const
    {
        showPerson();
        // Calls Person's function.

        showEmployee();
        // Calls Employee's function.

        std::cout << "Team Size: "
                  << teamSize << '\n';
    }
};


int main()
{
    Manager manager("Ravi", 501, 8);
    // Creates Manager object.

    manager.showManager();
    // Displays all inherited and own information.

    return 0;
}
