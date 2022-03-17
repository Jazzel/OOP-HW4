#include <vector>
#include <string>
#include <iostream>

#include "Deposit.hpp"
#include "Withdrawal.hpp"

using namespace std;

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
        depositTransactions = {};
        withdrawalTransactions = {};
    }

    Account(std::string _title, std::string _code, double _initialDeposit)
    {
        std::replace(_title.begin(), _title.end(), '_', ' ');
        _title = _title + " ";

        std::vector<std::string> words;

        size_t pos = 0;
        while ((pos = _title.find(" ")) != std::string::npos)
        {
            words.push_back(_title.substr(0, pos));
            _title.erase(0, pos + 1);
        }
        title = words[1] + " " + words[0];

        code = _code;
        initialBalance = balance = _initialDeposit;
        status = 1;
        depositTransactions = {};
        withdrawalTransactions = {};
    }

    void depositAmount(double _amount, std::string _date)
    {
        Deposit deposit(_amount, _date);
        depositTransactions.push_back(deposit);
        balance += _amount;
    }

    void withdrawAmount(double _amount, std::string _date)
    {
        if (balance > _amount)
        {
            Withdrawal withdraw(_amount, _date, true);
            withdrawalTransactions.push_back(withdraw);

            balance -= _amount;
        }
        else
        {
            Withdrawal withdraw(_amount, _date, false);
            withdrawalTransactions.push_back(withdraw);
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
    double getInitialBalance()
    {
        return initialBalance;
    }
    std::vector<Deposit> getDeposits()
    {
        return depositTransactions;
    }
    std::vector<Withdrawal> getWithdrawals()
    {
        return withdrawalTransactions;
    }

    void updateStatus()
    {
        if (balance < 5000)
        {
            status = 0;
        }
    }
};
