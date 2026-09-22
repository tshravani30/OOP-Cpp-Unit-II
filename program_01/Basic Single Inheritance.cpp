#include <iostream>       // Includes the input/output stream library.
                          // It provides cout and other standard I/O facilities.

#include <string>         // Includes the string class for storing text.

#include <utility>        // Provides utility functions such as std::move.


// ---------------- BASE CLASS ----------------
class Person              // Defines a class named Person.
{
protected:                // Members below this are accessible inside
                          // Person and its derived classes.

    std::string name;     // Declares a string variable named name.

public:                   // Members below this are accessible from outside.

    explicit Person(std::string personName)
        : name(std::move(personName))
    {
        // Constructor of Person.
        // personName receives the person's name.
        // std::move transfers the string efficiently into name.
    }

    void displayName() const
    {
        // Function used to display the person's name.
        // const means this function does not modify the object.

        std::cout << "Name: " << name << '\n';
        // cout displays "Name: " followed by name.
        // '\n' moves the cursor to the next line.
    }
};


// ---------------- DERIVED CLASS ----------------
class Student : public Person
{
    // Student publicly inherits from Person.
    // Therefore Student gets accessible members of Person.

private:

    int rollNumber;
    // Student's private data member for storing roll number.

public:

    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll)
    {
        // Student constructor.
        // First, Person constructor is called.
        // Then rollNumber is initialized with roll.
    }

    void displayStudent() const
    {
        // Function to display Student information.

        displayName();
        // Calls the inherited function from Person.

        std::cout << "Roll Number: " << rollNumber << '\n';
        // Displays the student's roll number.
    }
};


// ---------------- MAIN FUNCTION ----------------
int main()
{
    Student student("Amit", 101);
    // Creates a Student object.
    // "Amit" is passed as the name.
    // 101 is passed as the roll number.

    student.displayStudent();
    // Calls Student's displayStudent() function.

    return 0;
    // Terminates the program successfully.
}
