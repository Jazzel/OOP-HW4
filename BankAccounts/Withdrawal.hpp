
class Withdrawal
{
private:
    double amount;
    Date date;
    bool status;

public:
    Withdrawal()
    {
    }

    Withdrawal(double _amount, std::string _date, bool _status)
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

        amount = _amount;
        date = Date(day, month, year);
        status = _status;
    }

    double getAmount()
    {
        return amount;
    }

    std::string getDate()
    {
        return date.getFormatedDate();
    }

    string getStatus()
    {
        return status ? "Successful" : "Denied";
    }
};