//
// Created by Drew J. Sonne on 16/02/2025.
//

#ifndef GREGORIAN_CALENDAR_H
#define GREGORIAN_CALENDAR_H
#include "calendar.h"


namespace calendar::gregorian {
    enum class Month {
        January = 1,
        February = 2,
        March = 3,
        April = 4,
        May = 5,
        June = 6,
        July = 7,
        August = 8,
        September = 9,
        October = 10,
        November = 11,
        December = 12
    };

    enum class DayOfWeek {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    class GregorianCalendar : Calendar {
    public:
        GregorianCalendar(int year, int month, int day);

        [[nodiscard]] int year() const;

        [[nodiscard]] Month month() const;

        [[nodiscard]] int day() const;

        [[nodiscard]] DayOfWeek day_of_week() const;

        GregorianCalendar &add_days(int days);

    protected:
        int _year;
        Month _month;
        int _day;

    private:
        static RataDie _fixedFromGregorian(int year, int month, int day);
    };
}


#endif //GREGORIAN_CALENDAR_H
