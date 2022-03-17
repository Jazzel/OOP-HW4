#include <string>
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
        std::string _year = std::to_string(year);
        std::string formatedDate = _day + "/" + _month + "/" + _year;
        return formatedDate;
    }
};
