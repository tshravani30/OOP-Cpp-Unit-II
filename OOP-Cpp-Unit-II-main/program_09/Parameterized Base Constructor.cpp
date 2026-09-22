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
        // Parameterized Person constructor.
    }
};


class Student : public Person
{
private:

    int rollNumber;
    // Stores student's roll number.

public:

    Student(std::string studentName, int roll)
        : Person(std::move(studentName)),
          rollNumber(roll)
    {
        // Person(...) initializes the base class.
        // rollNumber(roll) initializes Student's member.
    }

    void display() const
    {
        std::cout << "Name: " << name << '\n';
        // Displays inherited protected name.

        std::cout << "Roll Number: "
                  << rollNumber << '\n';
        // Displays roll number.
    }
};


int main()
{
    Student student("Kiran", 24);
    // Creates Student object.

    student.display();
    // Displays information.

    return 0;
}
