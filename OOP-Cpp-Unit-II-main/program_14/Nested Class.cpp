#include <iostream>
// Provides cout.

#include <string>
// Provides string.

#include <utility>
// Provides move.


class University
{
public:

    class Department
    {
        // Department is nested inside University.

    private:

        std::string name;
        // Stores department name.

    public:

        explicit Department(
            std::string departmentName)
            : name(std::move(departmentName))
        {
            // Initializes department name.
        }

        void display() const
        {
            std::cout << "Department: "
                      << name << '\n';
        }
    };
};


int main()
{
    University::Department department(
        "Artificial Intelligence and Data Science");
    // Creates Department object using
    // University::Department syntax.

    department.display();
    // Displays department name.

    return 0;
}
