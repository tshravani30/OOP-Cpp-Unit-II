#include <iostream>
// Provides cout.


class Vehicle
{
public:

    virtual void move() const
    {
        // virtual allows derived classes to provide
        // their own implementation.

        std::cout << "Vehicle is moving\n";
    }

    virtual ~Vehicle() = default;
    // Virtual destructor.
    // Allows safe destruction through a base pointer/reference.
};


class Car : public Vehicle
{
public:

    void move() const override
    {
        // Overrides Vehicle::move().

        std::cout << "Car moves on roads\n";
    }
};


class Boat : public Vehicle
{
public:

    void move() const override
    {
        // Overrides Vehicle::move().

        std::cout << "Boat moves on water\n";
    }
};


int main()
{
    Car car;
    // Creates Car object.

    Boat boat;
    // Creates Boat object.

    car.move();
    // Calls Car's move().

    boat.move();
    // Calls Boat's move().

    return 0;
}
