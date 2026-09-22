#include <iostream>       // Provides cout.
#include <string>         // Provides string.
#include <utility>        // Provides move.


class Vehicle
{
protected:

    std::string registrationNumber;
    // Stores vehicle registration number.

public:

    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration))
    {
        // Initializes registration number.
    }

    void start() const
    {
        std::cout << "Vehicle "
                  << registrationNumber
                  << " started\n";
    }
};


class Car : public Vehicle
{
public:

    explicit Car(std::string registration)
        : Vehicle(std::move(registration))
    {
        // Calls Vehicle constructor.
    }

    void openBoot() const
    {
        std::cout << "Car boot opened\n";
    }
};


class Bike : public Vehicle
{
public:

    explicit Bike(std::string registration)
        : Vehicle(std::move(registration))
    {
        // Calls Vehicle constructor.
    }

    void helmetReminder() const
    {
        std::cout << "Please wear a helmet\n";
    }
};


int main()
{
    Car car("MH12AB1234");
    // Creates Car object.

    Bike bike("MH12CD5678");
    // Creates Bike object.

    car.start();
    // Calls inherited Vehicle function.

    car.openBoot();
    // Calls Car's own function.

    bike.start();
    // Calls inherited Vehicle function.

    bike.helmetReminder();
    // Calls Bike's own function.

    return 0;
}
