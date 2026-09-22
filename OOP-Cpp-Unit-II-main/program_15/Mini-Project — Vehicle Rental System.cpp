#include <iostream>
// Provides cout.

#include <string>
// Provides string.

#include <utility>
// Provides move.


class Vehicle
{
protected:

    std::string registrationNumber;
    // Stores vehicle registration number.

    double ratePerDay;
    // Stores rental rate per day.

public:

    Vehicle(std::string registration,
            double rate)
        : registrationNumber(std::move(registration)),
          ratePerDay(rate)
    {
        // Constructor initializes registration number
        // and daily rental rate.
    }

    virtual double calculateRent(int days) const
    {
        // Virtual function.
        // Derived classes can override it.

        return ratePerDay * days;
        // Normal rent = rate per day × number of days.
    }

    virtual void display() const
    {
        // Displays common vehicle details.

        std::cout << "Registration: "
                  << registrationNumber << '\n';

        std::cout << "Rate per day: "
                  << ratePerDay << '\n';
    }

    virtual ~Vehicle() = default;
    // Virtual destructor.
};


class Car : public Vehicle
{
private:

    int numberOfDoors;
    // Stores number of car doors.

public:

    Car(std::string registration,
        double rate,
        int doors)
        : Vehicle(std::move(registration), rate),
          numberOfDoors(doors)
    {
        // Calls Vehicle constructor.
        // Initializes numberOfDoors.
    }

    void display() const override
    {
        // Overrides Vehicle's display().

        Vehicle::display();
        // Calls the base-class display()
        // to show common information.

        std::cout << "Doors: "
                  << numberOfDoors << '\n';
        // Displays number of doors.
    }
};


class Bike : public Vehicle
{
private:

    int engineCapacity;
    // Stores engine capacity in cc.

public:

    Bike(std::string registration,
         double rate,
         int capacity)
        : Vehicle(std::move(registration), rate),
          engineCapacity(capacity)
    {
        // Initializes Vehicle and engine capacity.
    }

    double calculateRent(int days) const override
    {
        // Overrides the normal rent calculation.

        return ratePerDay * days * 0.9;
        // Applies 90% of normal rent,
        // effectively giving a 10% reduction.
    }

    void display() const override
    {
        // Overrides display().

        Vehicle::display();
        // Displays common vehicle information.

        std::cout << "Engine Capacity: "
                  << engineCapacity
                  << " cc\n";
    }
};


int main()
{
    Car car("MH12AB1234", 2000.0, 5);
    // Creates a Car.
    // Registration = MH12AB1234
    // Rate = 2000 per day
    // Doors = 5

    Bike bike("MH12CD5678", 800.0, 150);
    // Creates a Bike.
    // Registration = MH12CD5678
    // Rate = 800 per day
    // Engine = 150 cc

    std::cout << "Car Details\n";
    // Displays heading.

    car.display();
    // Displays car information.

    std::cout << "Rent for 3 days: "
              << car.calculateRent(3)
              << "\n\n";
    // Calculates car rent:
    // 2000 × 3 = 6000.

    std::cout << "Bike Details\n";
    // Displays heading.

    bike.display();
    // Displays bike information.

    std::cout << "Rent for 3 days: "
              << bike.calculateRent(3)
              << '\n';
    // Bike rent:
    // 800 × 3 × 0.9 = 2160.

    return 0;
}
