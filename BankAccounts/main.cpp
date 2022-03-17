#include <iostream>
#include <vector>
#include <fstream>

#include "Bank.hpp"
#include "Choices.hpp"

// ! -------------- Constants
const std::string INPUTFILE = "bankinput.txt";
const std::string OUTPUTFILE = "bankoutput.txt";

void initCommands(std::string command, std::ifstream *file, Bank *bank)
{
    std::string title, code, date;
    double initialDeposit, amount;

    switch (resolveOption(command))
    {
    case Choices::Option::CREATE:
    {
        *file >> title >> code >> initialDeposit;
        // std::cout << "Create " << title << " " << code << " " << initialDeposit << std::endl;
        bank->createBankAccount(title, code, initialDeposit);
        break;
    }

    case Choices::Option::DEPOSIT:
    {
        *file >> code >> amount >> date;
        // std::cout << "Depoist " << code << " " << amount << " " << date << std::endl;
        bank->getAccount(code).depositAmount(amount, date);
        // std::cout << " ---------- " << bank->getAccount(code).getDeposits().size() << endl;
        break;
    }

    case Choices::Option::WITHDRAW:
    {
        *file >> code >> amount >> date;
        // std::cout << "Withdrawal " << code << " " << amount << " " << date << std::endl;
        bank->getAccount(code).withdrawAmount(amount, date);
        break;
    }

    default:
        break;
    }
}

void readFile(Bank *bank)
{
    std::ifstream *file = new std::ifstream;
    file->open(INPUTFILE);

    std::string command;

    while (!file->eof())
    {
        *file >> command;
        initCommands(command, file, bank);
    }
    file->close();
}

void writeFile(Bank *bank)
{
    std::ofstream *file = new std::ofstream;
    file->open(OUTPUTFILE);
    std::vector<Account> accounts = bank->getAllAccounts();
    for (int i = 0; i < accounts.size(); i++)
    {
        accounts[i].updateStatus();
        *file << "Account Title: " << accounts[i].getAccountTitle() << std::endl;
        *file << "Account Code: " << accounts[i].getAccountCode() << std::endl;
        *file << "Initial Balance: " << accounts[i].getInitialBalance() << std::endl;
        *file << "Available Balance: " << accounts[i].getAccountBalance() << std::endl;
        accounts[i].getAccountStatus() ? *file << "Current Status: Active" : *file << "Current Status: Dormant";
        *file << std::endl;

        std::vector<Deposit> deposits = accounts[i].getDeposits();
        std::vector<Withdrawal> withdrawals = accounts[i].getWithdrawals();
        if (deposits.size())
        {
            int count = 1;
            *file << "Deposits:" << std::endl;
            for (int i = 0; i < deposits.size(); i++)
            {
                *file << count << ". " << deposits[i].getAmount() << " on " << deposits[i].getDate() << std::endl;
                count++;
            }
        }
        if (withdrawals.size())
        {
            int count = 1;
            *file << "Withdrawals:" << std::endl;
            for (int i = 0; i < withdrawals.size(); i++)
            {
                *file << count << ". " << withdrawals[i].getAmount() << " on " << withdrawals[i].getDate() << " " << withdrawals[i].getStatus() << std::endl;
                count++;
            }
        }
        *file << "----------------------------------------" << std::endl;

        // std::cout << "Account Title: " << accounts[i].getAccountTitle() << std::endl;
        // std::cout << "Account Code: " << accounts[i].getAccountCode() << std::endl;
        // std::cout << "Initial Balance: " << accounts[i].getInitialBalance() << std::endl;
        // std::cout << "Available Balance: " << accounts[i].getAccountBalance() << std::endl;
        // accounts[i].getAccountStatus() ? std::cout << "Current Status: Active" : std::cout << "Current Status: Dormant";
        // std::cout << std::endl;

        // std::vector<Deposit> deposits = accounts[i].getDeposits();
        // std::vector<Withdrawal> withdrawals = accounts[i].getWithdrawals();
        // if (deposits.size())
        // {
        //     std::cout << "Deposits:" << std::endl;
        //     for (int i = 0; i < deposits.size(); i++)
        //     {
        //         std::cout << deposits[i].getAmount() << " on " << deposits[i].getDate() << std::endl;
        //     }
        // }
        // if (withdrawals.size())
        // {
        //     std::cout << "Withdrawals:" << std::endl;
        //     for (int i = 0; i < withdrawals.size(); i++)
        //     {
        //         std::cout << withdrawals[i].getAmount() << " on " << withdrawals[i].getDate() << " " << withdrawals[i].getStatus() << std::endl;
        //     }
        // }
        // std::cout << "----------------------------------------" << std::endl;
    }
}

int main()
{
    Bank *bank = new Bank();
    readFile(bank);
    writeFile(bank);

    // bank.createBankAccount("test", "test", 1000);
    // std::vector<Account> accounts = bank.getAllAccounts();
    // Account acc = bank.getAccount("test");
    // // std::cout << acc.getAccountBalance() << std::endl;
    // bank.getAccount("test").depositAmount(1000, "11-March");
    // std::cout
    //     << acc.getAccountBalance() << std::endl;
    // std::vector<Deposit> deposits = acc.getDeposits();
    // std::cout << deposits.size();

    // .depositAmount(1000, "11-March");

    // std::cout << "----------" << std::endl;
    // for (int i = 0; i < accounts.size(); i++)
    // {
    //     Account acc2 = bank.getAccount(accounts[i].getAccountCode());
    //     // acc.depositAmount(1000, "11-March");

    //     std::cout << acc2.getAccountTitle() << std::endl;
    //     std::cout << acc2.getAccountBalance() << std::endl;
    //     std::vector<Deposit> deposits2 = acc2.getDeposits();
    //     std::cout << deposits2.size();
    //     // accounts[i].depositAmount(1000, "11-March");
    //     // std::vector<Deposit> deposits1 = accounts[i].getDeposits();
    //     // std::cout << deposits.size();
    // }

    // delete bank;
    // bank = NULL;

    // Account account("test", "test", 1000);
    // std::cout << account.getAccountBalance() << std::endl;
    // account.depositAmount(1000, "11-March");
    // std::cout << account.getAccountBalance() << std::endl;
    // std::vector<Deposit> deposits = account.getDeposits();
    // for (int i = 0; i < deposits.size(); i++)
    // {
    //     std::cout << deposits[i].getAmount() << std::endl;
    //     std::cout << deposits[i].getDate() << std::endl;
    // }
    return 0;
}
