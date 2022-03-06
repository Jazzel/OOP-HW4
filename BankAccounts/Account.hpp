#include <vector>
#include <string>

#include "Deposit.hpp"
#include "Withdrawal.hpp"

class Account
{
private:
    std::string title;
    std::string code;
    double balance;
    double initialBalance;
    bool status;
    std::vector<Deposit> depositTransactions;
    std::vector<Withdrawal> withdrawalTransactions;

public:
    Account()
    {
        title = "";
        code = "";
        initialBalance = balance = 0;
        status = 0;
    }

    Account(std::string _title, std::string _code, double _initialDeposit)
    {
        title = _title;
        code = _code;
        initialBalance = balance = _initialDeposit;
        status = 1;
    }

    void depositAmount(double _amount, std::string _date)
    {
        Deposit deposit(_amount, _date);
        balance += _amount;
        depositTransactions.push_back(deposit);
    }

    void withdrawAmount(double _amount, std::string _date)
    {
        if (balance > _amount)
        {
            Withdrawal withdraw(_amount, _date, true);
            balance -= _amount;
        }
        else
        {
            Withdrawal withdraw(_amount, _date, false);
        }
    }

    std::string getAccountCode()
    {
        return code;
    }
    bool getAccountStatus()
    {
        return status;
    }
    std::string getAccountTitle()
    {
        return title;
    }
    double getAccountBalance()
    {
        return balance;
    }
    std::vector<Deposit> getDeposits()
    {
        return depositTransactions;
    }
    std::vector<Withdrawal> getWithdrawals()
    {
        return withdrawalTransactions;
    }
};
