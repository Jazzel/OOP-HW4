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
    std::vector<Account> accounts = bank->getAllAccounts();
    for (int i = 0; i < accounts.size(); i++)
    {
        std::cout << accounts[i].getAccountCode() << std::endl;
        std::cout << accounts[i].getAccountBalance() << std::endl;
        std::cout << accounts[i].getAccountStatus() << std::endl;
        std::cout << accounts[i].getAccountTitle() << std::endl;
        std::vector<Deposit> deposits = accounts[i].getDeposits();
        std::vector<Withdrawal> withdrawals = accounts[i].getWithdrawals();
        for (int i = 0; i < deposits.size(); i++)
        {
            std::cout << deposits[i].getAmount() << std::endl;
            std::cout << deposits[i].getDate() << std::endl;
        }
        for (int i = 0; i < withdrawals.size(); i++)
        {
            std::cout << withdrawals[i].getAmount() << std::endl;
            std::cout << withdrawals[i].getDate() << std::endl;
        }
    }
}

int main()
{
    Bank *bank = new Bank();
    readFile(bank);
    writeFile(bank);

    delete bank;
    bank = NULL;
    return 0;
}
