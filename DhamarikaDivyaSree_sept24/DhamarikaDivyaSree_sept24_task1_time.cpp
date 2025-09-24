#include <iostream>
#include <iomanip>
#include "Time.h"

// Constructor: initializes time
Time::Time( int hr, int min, int sec ) 
{ 
    setTime( hr, min, sec ); 
}

// set all values together
void Time::setTime( int h, int m, int s )
{
    setHour( h );   
    setMinute( m ); 
    setSecond( s ); 
}

// validate hour
void Time::setHour( int h )
{
    hour = ( h >= 0 && h < 24 ) ? h : 0; 
}

// validate minute
void Time::setMinute( int m )
{
    minute = ( m >= 0 && m < 60 ) ? m : 0;
}

// validate second
void Time::setSecond( int s )
{
    second = ( s >= 0 && s < 60 ) ? s : 0;
}

// getters int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

// print time in 24-hour format (HH:MM:SS)
void Time::printUniversal() const
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":"
              << std::setw(2) << getSecond();
}

// print time in 12-hour format (HH:MM:SS AM/PM)
void Time::printStandard() const
{
    std::cout << ( (getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12 )
              << ":" << std::setfill('0') << std::setw(2) << getMinute()
              << ":" << std::setw(2) << getSecond()
              << ( hour < 12 ? " AM" : " PM" );
}

// tick function increments by 1 second
void Time::tick()
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
            }
        }
    }
}
