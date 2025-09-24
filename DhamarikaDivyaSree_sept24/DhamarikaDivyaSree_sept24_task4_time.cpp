#include "Time.h"

// constructor; initializes time and validates values
Time::Time(int hr, int min, int sec)
{
    if (!setTime(hr, min, sec)) { // if invalid, set to 0
        hour = 0;
        minute = 0;
        second = 0;
    }
}

// set full time; returns false if any part is invalid
bool Time::setTime(int h, int m, int s)
{
    bool valid = true;
    if (!setHour(h)) valid = false;     // validate hour
    if (!setMinute(m)) valid = false;   // validate minute
    if (!setSecond(s)) valid = false;   // validate second
    return valid;
}

// set individual parts; return false if invalid
bool Time::setHour(int h)
{
    if (h >= 0 && h < 24) { hour = h; return true; }
    return false;
}

bool Time::setMinute(int m)
{
    if (m >= 0 && m < 60) { minute = m; return true; }
    return false;
}

bool Time::setSecond(int s)
{
    if (s >= 0 && s < 60) { second = s; return true; }
    return false;
}

// getters
int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

// print in universal format HH:MM:SS
void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
              << std::setw(2) << minute << ":" 
              << std::setw(2) << second;
}

// print in standard format HH:MM:SS AM/PM
void Time::printStandard() const
{
    int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    std::string ampm = (hour < 12) ? "AM" : "PM";

    std::cout << displayHour << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setw(2) << second << " " << ampm;
}
