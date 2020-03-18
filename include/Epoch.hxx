#ifndef __EPOCH_HXX__
#define __EPOCH_HXX__

#include "Units.hxx"

#include <string>
#include <iostream>

namespace PHYS
{
    namespace Chrono
    {
        class Time
        {
            private:
                int _nsecs = 0;
            public:
                Time(){};
                Time(const int& nsecs) : _nsecs(nsecs) {}
                void addMSecs(const int& msecs);
                void addSecs(const int& secs);
                void addMins(const int& mins);
                void addHours(const int& hrs);
                void addDays(const int& days);
                void addYears(const int& years);
                int nSecs() const {return _nsecs;}
                std::string toString(const std::string& pattern) const;
                Time& operator++();
                Time& operator--();
                Time operator+() const {return Time(_nsecs);}
                Time operator-() const {return Time(-_nsecs);}
            
            friend Time operator+ (const Time& t1, const Time& t2)
            {
                return Time(t1.nSecs() + t2.nSecs());
            }

            friend Time operator- (const Time& t1, const Time& t2)
            {
                return Time(t1.nSecs() - t2.nSecs());
            }

            friend std::ostream& operator<< (std::ostream& os, const Time t)
            {
                os << t.toString("HH:MM:SS");
                return os;
            }
        };

        enum class month
        {
            January,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
        };

        class Date
        {
            private:
                int _day = 0;
                int _month = 0;
                int _year = 0;
            public:
                Date(){};
                std::string toString(const std::string& pattern) const;
        };

        class DateTime
        {
            private:
                Date _date;
                Time _time;
            public:
                DateTime(){};
                Time time() const {return _time;}
                Date date() const {return _date;}
                void setDate(Date& date) {_date = date;}
                void setTime(Time& time) {_time = time;}
            
            friend std::ostream& operator<< (std::ostream& os, const DateTime t)
            {
                os << "DateTime(" << t._date.toString("YYYY-mm-DD") << ", " << t._time.toString("HH:MM:SS") << ")";
                return os;
            }
        };       
        DateTime fromString(const std::string& time_str, const std::string& pattern);
    };
};


#endif