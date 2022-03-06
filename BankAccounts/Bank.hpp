#include <vector>
#include <string>
#include "Account.hpp"

class Bank
{
private:
    std::vector<Account> accounts;

public:
    Bank()
    {
    }

    void createBankAccount(std::string title, std::string code, double initialDeposit)
    {
        Account account(title, code, initialDeposit);
        accounts.push_back(account);
    }

    std::vector<Account> getAllAccounts()
    {
        return accounts;
    }

    Account getAccount(std::string code)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountCode() == code)
            {
                // std::cout << accounts[i].getAccountCode();
                return accounts[i];
            }
        }
    }
};
