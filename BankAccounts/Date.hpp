// ? imports
#include <string>

/**
 * ? @brief Date
 * * stores dates for the transactions of the bank accounts
 *
 * ? @attributes
 * * day, month and year as integers
 *
 * ? @functions
 * * getFormatedDate():
 * *   - formats the attributes to make it a valid date with the slashes (/) in between
 *
 * ? @constructors
 * * Date(): empty constructor
 * * Date(int, int, int):
 * *   - takes 3 params and fills the attributes of the class with the inputs
 */
class Date
{
private:
    int day, month, year;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 21;
    }

    Date(int _day, int _month, int _year)
    {
        day = _day;
        month = _month;
        year = _year;
    }

    std::string getFormatedDate()
    {
        std::string _day = day < 10 ? "0" + std::to_string(day) : std::to_string(day);
        std::string _month = month < 10 ? "0" + std::to_string(month) : std::to_string(month);
        std::string formatedDate = _day + "/" + _month + "/" + std::to_string(year);
        return formatedDate;
    }
};
