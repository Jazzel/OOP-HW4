#include <algorithm>
#include <string>
#include <vector>

#include "Date.hpp"
#include "Months.hpp"

using namespace std;

class Deposit
{
private:
    // std::string code;
    double amount;
    Date date;

public:
    Deposit() : amount(0), date(Date())
    {
    }

    Deposit(double _amount, std::string _date) : amount(_amount)
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
    }

    double getAmount()
    {
        return amount;
    }

    std::string getDate()
    {
        return date.getFormatedDate();
    }
};
