#include <iostream>
// Provides cout.


class Account
{
private:

    double balance;
    // Private variable.
    // Normally outside classes cannot access it.

    friend class Auditor;
    // Gives Auditor permission to access
    // Account's private members.

public:

    explicit Account(double initialBalance)
        : balance(initialBalance)
    {
        // Initializes account balance.
    }
};


class Auditor
{
public:

    void inspect(const Account& account) const
    {
        // Receives Account object by const reference.

        std::cout << "Account Balance: "
                  << account.balance << '\n';
        // Auditor can access private balance
        // because Auditor is a friend class.
    }
};


int main()
{
    Account account(5000.0);
    // Creates Account with balance 5000.

    Auditor auditor;
    // Creates Auditor object.

    auditor.inspect(account);
    // Auditor checks account balance.

    return 0;
}
