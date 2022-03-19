// ? imports
#include <vector>
#include <string>
#include <iostream>

// ? header files
#include "DepositWithdrawal.hpp"

// ? namespaces
using namespace std;

/**
 * ? @brief Account
 * * creates account for the bank::accounts vector
 *
 * ? @attributes
 * * title: string type
 * * code: string type
 * * balance: int type
 * * initialBalance: int type
 * * status: bool type
 * * depositTransactions: vector of type Deposit class
 * * withdrawalTransactions: vector of type Withdrawal class
 *
 * ? @functions
 * * depositAmount(): creates Deposit object and pushes it in depositTransactions
 * * withdrawAmount(): creates Withdrawal object and pushes it in withdrawalTransactions
 * * getAccountCode(): getter for account code
 * * getAccountStatus(): getter for account status
 * * getAccountTitle(): getter for account title
 * * getAccountBalance(): getter for account balance
 * * getInitialBalance(): getter for account initial balance
 * * getDeposits(): getter for account deposits
 * * getWithdrawals(): getter for account withdrawals
 * * updateStatus(): updates status for account - 0: Dormant or 1: Active
 *
 * ? @constructor
 * * Account(): default instructor
 * * Account(std::string, std::string, int):
 * *   - takes first param formats name according to requirment
 * *   - assigns second param to code
 * *   - assigns third param to balance and initialBalance
 * *   - assigns empty object to vectors depositTransactions, withdrawalTransactions
 */
class Account
{
private:
    std::string title;
    std::string code;
    int balance;
    int initialBalance;
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

    Account(std::string _title, std::string _code, int _initialDeposit)
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

    void depositAmount(int _amount, std::string _date)
    {
        Deposit deposit(_amount, _date);
        depositTransactions.push_back(deposit);
        balance += _amount;
    }

    void withdrawAmount(int _amount, std::string _date)
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
    int getAccountBalance()
    {
        return balance;
    }
    int getInitialBalance()
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
