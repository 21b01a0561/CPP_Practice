#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>

class Time 
{
public:
    // constructor with default arguments; sets to 0 if invalid
    Time(int hr = 0, int min = 0, int sec = 0);

    // set functions; return false if invalid
    bool setTime(int h, int m, int s);
    bool setHour(int h);
    bool setMinute(int m);
    bool setSecond(int s);

    // getters
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // print functions
    void printUniversal() const; // HH:MM:SS
    void printStandard() const;  // HH:MM:SS AM/PM

private:
    int hour;   // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59
};

#endif
