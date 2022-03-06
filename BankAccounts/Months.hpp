#include <cctype>

namespace Months
{
    enum Option
    {
        Invalid = 0,
        January = 1,
        February = 2,
        March = 3,
        April = 4,
        May = 5,
        June = 6,
        July = 7,
        August = 8,
        September = 9,
        October = 10,
        November = 11,
        December = 12,
    };

}
Months::Option resolveMonths(std::string input)
{
    std::for_each(input.begin(), input.end(), [](char &c)
                  { c = ::tolower(c); });

    if (input == "january" || input == "jan")
        return Months::Option::January;
    if (input == "february" || input == "feb")
        return Months::Option::February;
    if (input == "march" || input == "mar")
        return Months::Option::March;
    if (input == "april" || input == "apr")
        return Months::Option::April;
    if (input == "may")
        return Months::Option::May;
    if (input == "june" || input == "jun")
        return Months::Option::June;
    if (input == "july" || input == "jul")
        return Months::Option::July;
    if (input == "august" || input == "aug")
        return Months::Option::August;
    if (input == "september" || input == "sept")
        return Months::Option::September;
    if (input == "october" || input == "oct")
        return Months::Option::October;
    if (input == "november" || input == "nov")
        return Months::Option::November;
    if (input == "december" || input == "dec")
        return Months::Option::December;

    return Months::Option::Invalid;
}