#ifndef TIME_H
#define TIME_H

// Time abstract data type definition
class Time 
{
public:
    Time( int = 0, int = 0, int = 0 ); // constructor with default args

    // set functions
    void setTime( int, int, int ); // set hour, minute, second
    void setHour( int );           // validate & set hour
    void setMinute( int );         // validate & set minute
    void setSecond( int );         // validate & set second

    // get functions (marked const since they don't modify object)
    int getHour() const;   
    int getMinute() const; 
    int getSecond() const; 

    // printing functions (const → safe for const objects)
    void printUniversal() const; 
    void printStandard() const;  

    void tick(); // increments time by one second

private:
    int hour;   // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
}; // end class Time

#endif