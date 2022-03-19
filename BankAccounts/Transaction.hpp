// ? imports
#include <algorithm>
#include <string>
#include <vector>

// ? headerfiles
#include "Date.hpp"
#include "Months.hpp"

/**
 * ? @brief Transaction
 * * creates the transactions for the bank accounts
 * * parent class for Deposits and Withdrawals
 *
 * ? @attributes
 * * amount of type int
 * * date of type Date class
 *
 * ? @functions
 * * getAmount(): getter for amount variable
 * * getDate(): getter for date variable (formats it with Date::getFormatedDate)
 *
 * ? @constructors
 * * Transaction(): default constructor
 * * Transaction(int, string):
 * *   - converts date string to numbers
 * *   - month to numerical month with the help of Months::resolveMonths
 * *   - creates object for Date class with numerical day, month and year
 * *   - int param value is assigned to amount variables
 * *   - Date object is assigned to date variable
 * *   -
 *
 */
class Transaction
{
private:
    int amount;
    Date date;

public:
    Transaction() : amount(0), date(Date())
    {
    }

    Transaction(int _amount, std::string _date)
    {
        std::replace(_date.begin(), _date.end(), '-', ' ');
        _date = _date + " ";

        std::vector<std::string> words;

        size_t pos = 0;
        while ((pos = _date.find(" ")) != std::string::npos)
        {
            words.push_back(_date.substr(0, pos));
            _date.erase(0, pos + 1);
        }

        int day = stoi(words[0]);
        int month = resolveMonths(words[1]);
        int year = words.size() > 2 ? stoi(words[2]) : 21;

        date = Date(day, month, year);
        amount = _amount;
    }

    int getAmount()
    {
        return amount;
    }

    std::string getDate()
    {
        return date.getFormatedDate();
    }
};
