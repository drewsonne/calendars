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

        GregorianCalendar(int year, Month month, int day);

        const int year;
        const Month month;
        const int day;

        [[nodiscard]]
        DayOfWeek dayOfWeek() const;

        GregorianCalendar *addDays(int days) override;

        GregorianCalendar *fromFixed(RataDie rata_die) override;

        static RataDie fixedNewYear(int year);

        static RataDie fixedYearEnd(int year);

        [[nodiscard]]
        RataDie toFixed() const override;

        static int yearFromFixed(RataDie rata_die);

        static bool isLeapYear(int year);

    protected:
        static RataDie fixedFrom(int year, int month, int day);
    };
}


#endif //GREGORIAN_CALENDAR_H
