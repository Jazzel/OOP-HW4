// ? imports
#include <algorithm>
#include <string>
#include <vector>

// ? header files
#include "Transaction.hpp"

// ? namespaces
using namespace std;

/**
 * ? @brief Deposit inherited from Transaction
 * * creates deposits for the Bank::accounts vector
 *
 * ? @attributes
 * * inherited from parent class (Transaction)
 *
 * ? @functions
 * * inherited from parent class (Transaction)
 *
 * ? @constructors
 * * Deposit(): empty constructor
 * * Deposit(int, std::string):
 * *   - takes 2 params int and string
 * *   - and passes it to Transaction constructor
 *
 */
class Deposit : public Transaction
{
public:
    Deposit() : Transaction()
    {
    }

    Deposit(int _amount, std::string _date) : Transaction(_amount, _date)
    {
    }
};

/**
 * ? @brief Withdrawal inherited from Transaction
 * * creates withdrawals for the Bank::accounts vector
 *
 * ? @attributes
 * * inherited from parent class (Transaction)
 * * bool status - for the status of withdrawal - Successful or Denied
 *
 * ? @functions
 * * getStatus(): getter for status variable
 *
 * ? @constructors
 * * Withdrawal(): empty constructor
 * * Withdrawal(int, std::string, bool):
 * *   - takes 2 params int and string
 * *   - and passes it to Transaction constructor
 * *   - third param sets the value of status variable
 *
 */
class Withdrawal : public Transaction
{
private:
    bool status;

public:
    Withdrawal() : Transaction(), status(false)
    {
    }

    Withdrawal(int _amount, std::string _date, bool _status) : Transaction(_amount, _date), status(_status)
    {
    }

    string getStatus()
    {
        return status ? "Successful" : "Denied";
    }
};
