
namespace Choices
{
    enum Option
    {
        CREATE = 0,
        DEPOSIT = 1,
        WITHDRAW = 2,
        INVALID = 3,
    };

}
Choices::Option resolveOption(std::string input)
{
    if (input == "Create")
        return Choices::Option::CREATE;
    if (input == "Deposit")
        return Choices::Option::DEPOSIT;
    if (input == "Withdrawal")
        return Choices::Option::WITHDRAW;
    return Choices::Option::INVALID;
}