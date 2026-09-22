#include <iostream>
// Provides cout.


class Academic
{
public:

    void display() const
    {
        std::cout << "Academic information\n";
    }
};


class Sports
{
public:

    void display() const
    {
        std::cout << "Sports information\n";
    }
};


class Student : public Academic,
                public Sports
{
public:

    void displayAll() const
    {
        Academic::display();
        // Explicitly calls Academic's display().

        Sports::display();
        // Explicitly calls Sports' display().
    }
};


int main()
{
    Student student;
    // Creates Student object.

    student.Academic::display();
    // Calls Academic version explicitly.

    student.Sports::display();
    // Calls Sports version explicitly.

    student.displayAll();
    // Calls both functions through displayAll().

    return 0;
}
