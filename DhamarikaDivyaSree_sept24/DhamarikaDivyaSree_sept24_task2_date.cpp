#include <iostream>
#include "Date.h"

// constructor with validation
Date::Date( int m, int d, int y )
{
    // validate year (>=1900 for example)
    year = (y >= 1900) ? y : 2000;

    // validate month (1–12)
    month = (m >= 1 && m <= 12) ? m : 1;

    // validate day based on month and leap year
    int maxDay = daysInMonth(month, year);
    day = (d >= 1 && d <= maxDay) ? d : 1;
}

// utility: check leap year
bool Date::isLeapYear(int y) const
{
    return ( (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0) );
}

// utility: days in a month
int Date::daysInMonth(int m, int y) const
{
    switch(m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;// this case will return 31 for the months which has last date as 31
        case 4: case 6: case 9: case 11: return 30;//this case will return 30 for the months which has last date as 30

        case 2: return isLeapYear(y) ? 29 : 28;// this case if for February to return according to the leapyear and normal year
        default: return 31; 
    }
}

// increment date by 1 day
void Date::nextDay()
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

// print Date in the format mm/dd/yyyy
void Date::print() const
{ 
    std::cout << month << '/' << day << '/' << year; 
}
