#include "Epoch.hxx"

std::string PHYS::Chrono::Time::toString(const std::string& pattern) const
{
    std::string _out_str = "";
    int index = 0;
    int _temp_time = _nsecs;
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

        else
        {
            i++;
        }
    }

    _output.setTime(_temp);

    return _output;
}