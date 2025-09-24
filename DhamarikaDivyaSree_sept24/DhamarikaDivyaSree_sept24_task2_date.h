#ifndef DATE_H
#define DATE_H

// class Date definition
class Date 
{
public:
    Date( int = 1, int = 1, int = 2000 ); // default constructor with validation

    void print() const;   // print date as mm/dd/yyyy
    void nextDay();       // increment the day by 1

private:
    int month;
    int day;
    int year;

    // utility function to check if year is leap year
    bool isLeapYear(int y) const;

    // utility function to return number of days in a month
    int daysInMonth(int m, int y) const;
}; // end class Date

#endif
