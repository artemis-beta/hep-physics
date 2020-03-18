#include "Epoch.hxx"

std::string PHYS::Chrono::Time::toString(const std::string& pattern) const
{
    std::string _out_str = (_nsecs < 0) ? "-" : "";
    int index = 0;
    int _temp_time = abs(_nsecs);
    while(index < pattern.size())
    {
        if(pattern[index] == 'H')
        {
            int out_str_hr = int(_temp_time/PHYS::Units::hr);
            if(out_str_hr < 10) _out_str += "0";
            _out_str += std::to_string(out_str_hr);
            index += (pattern[index+1] == 'H') ? 2 : 1;
            _temp_time -= out_str_hr*PHYS::Units::hr;
        }
        else if(pattern[index] == 'M')
        {
            int out_str_min = int(_temp_time/PHYS::Units::min);
            if(out_str_min < 10) _out_str += "0";
            _out_str += std::to_string(out_str_min);
            index += (pattern[index+1] == 'M') ? 2 : 1;
            _temp_time -= out_str_min*PHYS::Units::min;
        }
        else if(pattern[index] == 'S')
        {
            int out_str_s = int(_temp_time/PHYS::Units::sec);
            if(out_str_s < 10) _out_str += "0";
            _out_str += std::to_string(out_str_s);
            index += (pattern[index+1] == 'S') ? 2 : 1;
            _temp_time -= out_str_s*PHYS::Units::sec;
        }
        else
        {
            _out_str += pattern[index];
            index++;
        }
        
    }

    return _out_str;
}

std::string PHYS::Chrono::Date::toString(const std::string& pattern) const
{
    const int _days_in_4_years = 365.25*4;
    int _nleapyears = int(_ndays / _days_in_4_years);
    int _n_remaining = int((_ndays-_nleapyears*_days_in_4_years)/365);
    const int _year = _nleapyears*4+_n_remaining;
    const std::string _year_str = std::to_string(_year);
    int _days_remaining = (_ndays-_nleapyears*_days_in_4_years) % 365;
    bool _is_leap_year = _n_remaining == 0;

    int _counter = 0;
    int _current_month = 0;

    while(_counter < _days_remaining)
    {
        _counter += getDaysInMonth(month(_current_month));
        _current_month++;
    }
    _counter -= getDaysInMonth(month(_current_month-1));
    const std::string _month_str = ((_current_month < 11) ? "0" : "")+std::to_string(_current_month-1);
    const int _day = _days_remaining - _counter;
    const std::string _day_str = ((_day < 10) ? "0" : "")+std::to_string(_day);

    return _year_str+"-"+_month_str+"-"+_day_str;
}

void PHYS::Chrono::Time::addMSecs(const int& msecs)
{
    _nsecs += msecs*PHYS::Units::ms;
}

void PHYS::Chrono::Time::addSecs(const int& secs)
{
    _nsecs += secs*PHYS::Units::sec;
}

void PHYS::Chrono::Time::addMins(const int& mins)
{
    _nsecs += mins*PHYS::Units::min;
}

void PHYS::Chrono::Time::addHours(const int& hours)
{
    _nsecs += hours*PHYS::Units::hr;
}

void PHYS::Chrono::Time::addDays(const int& days)
{
    _nsecs += days*PHYS::Units::day;
}

void PHYS::Chrono::Time::addYears(const int& years)
{
    _nsecs += years*PHYS::Units::yr;
}

PHYS::Chrono::DateTime PHYS::Chrono::fromString(const std::string& time_str, const std::string& pattern)
{
    DateTime _output;
    Time _temp;
    Date _temp_date;
    int i = 0;
    while(i < time_str.size())
    {
        if(pattern[i] == 'H')
        {
            if(i+1 < pattern.size() && pattern[i+1] == 'H')
            {
                int n_10_hr = int(time_str[i]-'0');
                int n_1_hr = int(time_str[i+1]-'0');
                if(n_10_hr > 0) _temp.addHours(10*n_10_hr);
                _temp.addHours(n_1_hr);
                i += 2;
            }
            else
            {
                int n_1_hr = int(time_str[i]-'0');
                _temp.addHours(n_1_hr);
                i++;
            }
           
        }

        else if(pattern[i] == 'M')
        {
            
            if(i+1 < pattern.size() && pattern[i+1] == 'M')
            {
                int n_10_min = int(time_str[i]-'0');
                int n_1_min = int(time_str[i+1]-'0');
                if(n_10_min > 0) _temp.addMins(10*n_10_min);
                _temp.addMins(n_1_min);
                i += 2;
            }
            else
            {
                int n_1_min = int(time_str[i]-'0');
                _temp.addMins(n_1_min);
                i++;
            }
           
        }

        else if(pattern[i] == 'S')
        {
            
            if(i+1 < pattern.size() && pattern[i+1] == 'S')
            {
                int n_10_s = int(time_str[i]-'0');
                int n_1_s = int(time_str[i+1]-'0');
                if(n_10_s > 0) _temp.addSecs(10*n_10_s);
                _temp.addSecs(n_1_s);
                i += 2;
            }
            else
            {
                int n_1_s = int(time_str[i]-'0');
                _temp.addSecs(n_1_s);
                i++;
            }
           
        }
        else if(pattern[i] == 'D')
        {
            if(i+1 < pattern.size() && pattern[i+1] == 'D')
            {
                int n_10_d = int(time_str[i]-'0');
                int n_1_d = int(time_str[i+1]-'0');
                if(n_10_d > 0) _temp_date.addDays(10*n_10_d);
                _temp_date.addDays(n_1_d);
                i += 2;
            }
            else
            {
                int n_1_d = int(time_str[i]-'0');
                _temp.addDays(n_1_d);
                i++;
            }
        }

        else if(pattern[i] == 'm')
        {
            if(i+1 < pattern.size() && pattern[i+1] == 'm')
            {
                const int _month_int = std::stoi(time_str.substr(i, 2));
                
                for(int j{0}; j < _month_int; ++j)
                {
                    const int _month_days = getDaysInMonth(month(j));
                    _temp_date.addDays(_month_days);
                }
                i += 2;
                
            }
            else
            {
                const int _month_int = std::stoi(time_str.substr(i, 1));
                
                for(int j{0}; j < _month_int; ++j)
                {
                    const int _month_days = getDaysInMonth(month(j));
                    _temp_date.addDays(_month_days);
                }
                i++;
            }
            
        }

        else if(pattern[i] == 'Y')
        {
            int j = 0;
            while(pattern[i+j] == 'Y'){j+=1;}
            const int _year = std::stoi(time_str.substr(i, j));
            const int _nleapyears = int(_year/4);
            _temp_date.addDays(_nleapyears*366);
            _temp_date.addDays((_year-_nleapyears)*365);
            i += j;
        }

        else
        {
            i++;
        }
    }

    _output.setTime(_temp);
    _output.setDate(_temp_date);

    return _output;
}

PHYS::Chrono::Time& PHYS::Chrono::Time::operator++()
{
    _nsecs++;
    return *this;
}

PHYS::Chrono::Time& PHYS::Chrono::Time::operator--()
{
    _nsecs--;
    return *this;
}

const int PHYS::Chrono::getDaysInMonth(month m, bool leap_year)
{
    int _ndays_month = -1;
    switch(m)
        {
            case month::January:
                _ndays_month = 31;
                break;
            case month::February:
                if(leap_year) _ndays_month = 29;
                else _ndays_month = 28;
                break;
            case month::March:
                _ndays_month = 31;
                break;
            case month::April:
                _ndays_month = 30;
                break;
            case month::May:
                _ndays_month = 31;
                break;
            case month::June:
                _ndays_month = 30;
                break;
            case month::July:
                _ndays_month = 31;
                break;
            case month::August:
                _ndays_month = 31;
                break;
            case month::September:
                _ndays_month = 30;
                break;
            case month::October:
                _ndays_month = 31;
                break;
            case month::November:
                _ndays_month = 30;
                break;
            default:
                _ndays_month = 31;
        }
    return _ndays_month;
}