//DateAndTime.h
#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <iostream>
#include <iomanip>

// DateAndTime class definition
class DateAndTime
{
public:
    // constructor with default values
    DateAndTime(int = 1, int = 1, int = 2000, int = 0, int = 0, int = 0);

    // getters and setters for time 
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // getters and setters date 
    void setDate(int, int, int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // tick: advance one second
    void tick();

    // print functions
    void printUniversal() const; // YYYY/MM/DD HH:MM:SS
    void printStandard() const;  // MM/DD/YYYY HH:MM:SS AM/PM

private:
    // time members
    int hour;   // 0–23
    int minute; // 0–59
    int second; // 0–59

    // date members
    int month;  // 1–12
    int day;    // 1–31 (validated)
    int year;   // >= 1900

    // helpers
    bool isLeapYear(int y) const;// for leapyear check
    int daysInMonth(int m, int y) const;// for date checking in a particular month and also the maxday
    void nextDay(); // advance date by one day
};

#endif
