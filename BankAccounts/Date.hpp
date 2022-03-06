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
        std::string formatedDate = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
        return formatedDate;
    }
};
