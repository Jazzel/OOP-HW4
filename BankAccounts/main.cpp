// ? imports
#include <iostream>
#include <vector>
#include <fstream>

// ? headerfiles
#include "Bank.hpp"
#include "Choices.hpp"

// ! -------------- Constants
const std::string INPUTFILE = "bankinput.txt";
const std::string OUTPUTFILE = "bankoutput.txt";

/**
 * ? @brief initCommands()
 * * takes command, file stream pointer and bank pointer
 * * reads data from the input file
 * * calls bank functions according to command
 *
 * ? @param command
 * * string - Deposit, Withdraw, Create
 * ? @param file
 * * file stream pointer
 * ? @param bank
 * * bank class object pointer
 */
void initCommands(std::string command, std::ifstream *file, Bank *bank)
{
    std::string title, code, date;
    int initialDeposit, amount;

    switch (resolveOption(command))
    {
    case Choices::Option::CREATE:
    {
        *file >> title >> code >> initialDeposit;
        bank->createBankAccount(title, code, initialDeposit);
        break;
    }

    case Choices::Option::DEPOSIT:
    {
        *file >> code >> amount >> date;
        bank->getAccount(code).depositAmount(amount, date);
        break;
    }

    case Choices::Option::WITHDRAW:
    {
        *file >> code >> amount >> date;
        bank->getAccount(code).withdrawAmount(amount, date);
        break;
    }

    default:
        break;
    }
}

/**
 * ? @brief readFile
 * * creates a file stream pointer to read the input file
 * * calls the "initCommands" helper to initialize bank accounts
 * * INPUTFILE is defined as global variable above
 *
 * ? @param bank
 * * bank class object pointer
 */
void readFile(Bank *bank)
{
    //* creating file stream
    std::ifstream *file = new std::ifstream;
    file->open(INPUTFILE);

    std::string command;

    // * reading the file till the end of the line
    while (!file->eof())
    {
        *file >> command;
        initCommands(command, file, bank);
    }
    // * closing file stream
    file->close();

    // * deletes file pointer and assign null to it.
    delete file;
    file = NULL;
}
/**
 * ? @brief writeFile
 * * creates a file stream pointer to write in the output file
 * * gets all the accounts as vector from Bank::getAllAccounts helper
 * * gets all the data using getter functions defined in the Account class
 * * writes the details of accounts in the output file
 * * OUTPUTFILE is defined as global variable above
 *
 *
 * ? @param bank
 * * bank class object pointer
 */
void writeFile(Bank *bank)
{
    //* creating file stream
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
        // * checking if deposits exists or not
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
        // * checking if withdrawals exists or not
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
    }
    // * closing file stream
    file->close();
    // * deletes file pointer and assign null to it.
    delete file;
    file = NULL;
}

/**
 * ? @brief main
 * * creates bank object and reads the input file
 * * does the functionality and writes the bank output file
 *
 * ? @return void
 */
void main()
{
    // * creates bank pointer
    Bank *bank = new Bank();
    // * helper function calls
    readFile(bank);
    writeFile(bank);

    // * delete and assigns null to bank pointer
    delete bank;
    bank = NULL;
}
