#include <iostream>
// Provides cout.


class Academic
{
protected:

    int academicMarks;
    // Stores academic marks.

public:

    explicit Academic(int marks)
        : academicMarks(marks)
    {
        // Initializes academic marks.
    }

    void showAcademic() const
    {
        std::cout << "Academic Marks: "
                  << academicMarks << '\n';
    }
};


class Sports
{
protected:

    int sportsMarks;
    // Stores sports marks.

public:

    explicit Sports(int marks)
        : sportsMarks(marks)
    {
        // Initializes sports marks.
    }

    void showSports() const
    {
        std::cout << "Sports Marks: "
                  << sportsMarks << '\n';
    }
};


class Student : public Academic,
                public Sports
{
    // Student inherits from both Academic and Sports.

public:

    Student(int academic, int sports)
        : Academic(academic),
          Sports(sports)
    {
        // Calls both base-class constructors.
    }

    void showTotal() const
    {
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks
                  << '\n';
        // Adds marks from both base classes.
    }
};


int main()
{
    Student student(80, 15);
    // Creates Student with 80 academic marks
    // and 15 sports marks.

    student.showAcademic();
    // Displays academic marks.

    student.showSports();
    // Displays sports marks.

    student.showTotal();
    // Displays total.

    return 0;
}
