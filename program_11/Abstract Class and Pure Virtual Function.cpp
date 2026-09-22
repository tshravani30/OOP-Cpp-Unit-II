#include <iostream>
// Provides cout.


class Shape
{
public:

    virtual double area() const = 0;
    // Pure virtual function.
    // Shape does not provide a normal implementation.

    virtual ~Shape() = default;
    // Virtual destructor.
};


class Rectangle : public Shape
{
private:

    double length;
    // Stores rectangle length.

    double width;
    // Stores rectangle width.

public:

    Rectangle(double givenLength,
              double givenWidth)
        : length(givenLength),
          width(givenWidth)
    {
        // Initializes length and width.
    }

    double area() const override
    {
        // Implements Shape's pure virtual function.

        return length * width;
        // Rectangle area = length × width.
    }
};


class Circle : public Shape
{
private:

    double radius;
    // Stores circle radius.

public:

    explicit Circle(double givenRadius)
        : radius(givenRadius)
    {
        // Initializes radius.
    }

    double area() const override
    {
        // Implements Shape's pure virtual function.

        return 3.141592653589793
               * radius * radius;
        // Circle area = πr².
    }
};


int main()
{
    Rectangle rectangle(5.0, 3.0);
    // Creates rectangle.

    Circle circle(2.0);
    // Creates circle.

    std::cout << "Rectangle Area: "
              << rectangle.area() << '\n';

    std::cout << "Circle Area: "
              << circle.area() << '\n';

    return 0;
}
