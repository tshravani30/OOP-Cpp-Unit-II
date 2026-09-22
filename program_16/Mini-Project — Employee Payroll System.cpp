#include <iostream>
// Provides cout.

#include <string>
// Provides string.

#include <utility>
// Provides move.


class Employee
{
protected:

    int employeeId;
    // Stores employee ID.

    std::string name;
    // Stores employee name.

public:

    Employee(int id,
             std::string employeeName)
        : employeeId(id),
          name(std::move(employeeName))
    {
        // Initializes employee ID and name.
    }

    virtual double calculateSalary() const = 0;
    // Pure virtual function.
    // Makes Employee an abstract class.
    // Every derived class must implement salary calculation.

    void displayBasicDetails() const
    {
        // Displays common employee information.

        std::cout << "Employee ID: "
                  << employeeId << '\n';

        std::cout << "Name: "
                  << name << '\n';
    }

    virtual ~Employee() = default;
    // Virtual destructor for safe polymorphic use.
};


// ---------------- PERMANENT EMPLOYEE ----------------

class PermanentEmployee : public Employee
{
private:

    double basicSalary;
    // Stores basic salary.

    double allowance;
    // Stores additional allowance.

public:

    PermanentEmployee(int id,
                      std::string employeeName,
                      double basic,
                      double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra)
    {
        // Calls Employee constructor.
        // Initializes salary and allowance.
    }

    double calculateSalary() const override
    {
        // Implements Employee's pure virtual function.

        return basicSalary + allowance;
        // Permanent salary = basic + allowance.
    }
};


// ---------------- CONTRACT EMPLOYEE ----------------

class ContractEmployee : public Employee
{
private:

    double hourlyRate;
    // Stores payment per hour.

    int hoursWorked;
    // Stores number of hours worked.

public:

    ContractEmployee(int id,
                     std::string employeeName,
                     double rate,
                     int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours)
    {
        // Initializes all employee information.
    }

    double calculateSalary() const override
    {
        // Implements Employee's pure virtual function.

        return hourlyRate * hoursWorked;
        // Contract salary =
        // hourly rate × hours worked.
    }
};


// ---------------- PAYSLIP FUNCTION ----------------

void displayPaySlip(const Employee& employee)
{
    // Accepts any Employee-derived object
    // through a base-class reference.

    employee.displayBasicDetails();
    // Displays common employee details.

    std::cout << "Salary: "
              << employee.calculateSalary()
              << "\n\n";
    // Calls the appropriate overridden salary function.
};


// ---------------- MAIN FUNCTION ----------------

int main()
{
    PermanentEmployee permanentEmployee(
        101,
        "Asha",
        40000.0,
        8000.0);
    // Creates permanent employee.
    // Salary = 40000 + 8000 = 48000.

    ContractEmployee contractEmployee(
        102,
        "Vikas",
        500.0,
        80);
    // Creates contract employee.
    // Salary = 500 × 80 = 40000.

    displayPaySlip(permanentEmployee);
    // Displays permanent employee payslip.

    displayPaySlip(contractEmployee);
    // Displays contract employee payslip.

    return 0;
    // Ends the program successfully.
}
