// ? imports
#include <cctype>
/**
 * ? @brief Months - namespace
 * * contains enum for Month options
 * * converts Month to numerical month
 *
 * ? @functions
 * * resolveMonths(std::string):
 * *   - takes input as string and
 * *     returns integer according to given input
 */
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
    input = input.substr(0, 3);

    if (input == "jan")
        return Months::Option::January;
    if (input == "feb")
        return Months::Option::February;
    if (input == "mar")
        return Months::Option::March;
    if (input == "apr")
        return Months::Option::April;
    if (input == "may")
        return Months::Option::May;
    if (input == "jun")
        return Months::Option::June;
    if (input == "jul")
        return Months::Option::July;
    if (input == "aug")
        return Months::Option::August;
    if (input == "sept")
        return Months::Option::September;
    if (input == "oct")
        return Months::Option::October;
    if (input == "nov")
        return Months::Option::November;
    if (input == "dec")
        return Months::Option::December;

    return Months::Option::Invalid;
}