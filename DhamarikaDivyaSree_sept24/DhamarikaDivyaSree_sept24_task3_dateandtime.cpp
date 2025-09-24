//DateAndTime.cpp
#include "DateAndTime.h"

// constructor
DateAndTime::DateAndTime(int m, int d, int y, int h, int min, int s)
{
    setDate(m, d, y);
    setTime(h, min, s);
}

// ---------------- TIME ----------------
void DateAndTime::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void DateAndTime::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
}

void DateAndTime::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;
}

void DateAndTime::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0;
}

int DateAndTime::getHour() const { return hour; }
int DateAndTime::getMinute() const { return minute; }
int DateAndTime::getSecond() const { return second; }

// ---------------- DATE ----------------
void DateAndTime::setDate(int m, int d, int y)
{
    year = (y >= 1900) ? y : 2000;
    month = (m >= 1 && m <= 12) ? m : 1;

    int maxDay = daysInMonth(month, year);
    day = (d >= 1 && d <= maxDay) ? d : 1;
}

void DateAndTime::setDay(int d)
{
    int maxDay = daysInMonth(month, year);
    day = (d >= 1 && d <= maxDay) ? d : 1;
}

void DateAndTime::setMonth(int m)
{
    month = (m >= 1 && m <= 12) ? m : 1;
}

void DateAndTime::setYear(int y)
{
    year = (y >= 1900) ? y : 2000;
}

int DateAndTime::getDay() const { return day; }
int DateAndTime::getMonth() const { return month; }
int DateAndTime::getYear() const { return year; }

// ---------------- HELPERS ----------------
bool DateAndTime::isLeapYear(int y) const
{
    return ( (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0) );
}

int DateAndTime::daysInMonth(int m, int y) const
{
    switch (m)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(y) ? 29 : 28;
        default: return 31;
    }
}

// advance date by one day
void DateAndTime::nextDay()
{
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// tick function for changing to next day as well
void DateAndTime::tick()
{
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
        if (minute >= 60) {
            minute = 0;
            hour++;
            if (hour >= 24) {
                hour = 0;
                nextDay(); // rollover to next day
            }
        }
    }
}

// print function for printing both time(24hrs format) and date
void DateAndTime::printUniversal() const
{
    std::cout << year << "/"
              << std::setfill('0') << std::setw(2) << month << "/"
              << std::setw(2) << day << " "
              << std::setw(2) << hour << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second;
}
// prints 12hr format time with am/pm along with date
void DateAndTime::printStandard() const
{
    int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    std::string ampm = (hour < 12) ? "AM" : "PM";

    std::cout << std::setfill('0') << std::setw(2) << month << "/"
              << std::setw(2) << day << "/" << year << " "
              << displayHour << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second << " " << ampm;
}
