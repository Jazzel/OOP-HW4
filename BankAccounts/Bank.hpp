// ? imports
#include <vector>
#include <string>

// ? headerfiles
#include "Account.hpp"

/**
 * ? @brief Bank
 * * stores the accounts of users in vector
 * * creates bank accounts and returns bank accounts
 * * get single account with the help of Account::code (string)
 *
 * ? @attributes
 * * accounts vector of type Account class
 *
 * ? @functions
 * * createBankAccount(std::string, std::string, int):
 * *   - create Account object with code, title and initial ammount
 * *   - and adds it in the accounts vector
 *
 * * getAllAccounts():
 * *   - returns accounts vector
 *
 * * getAccount(std::string):
 * *   - loops on the accounts vector and
 * *   - returns single account with the help of Account::code
 *
 */
class Bank
{
private:
    std::vector<Account> accounts;

public:
    Bank()
    {
        accounts = {};
    }

    void createBankAccount(std::string title, std::string code, int initialDeposit)
    {
        Account account(title, code, initialDeposit);
        accounts.push_back(account);
    }

    std::vector<Account> &getAllAccounts()
    {
        return accounts;
    }

    Account &getAccount(std::string code)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountCode() == code)
            {
                return accounts[i];
            }
        }
    }
};
