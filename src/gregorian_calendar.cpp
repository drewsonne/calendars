//
// Created by Drew J. Sonne on 16/02/2025.
//

#include "gregorian_calendar.h"
#include <set>


namespace calendar::gregorian {
    constexpr RataDie GREGORIAN_EPOCH = 1;

    constexpr int DAYS_400_YEARS = 146097;
    constexpr int DAYS_100_YEARS = 36524;
    constexpr int DAYS_4_YEARS = 1461;
    constexpr int DAYS_1_YEAR = 365;

    constexpr int YEARS_4 = 4;
    constexpr int YEARS_100 = 100;
    constexpr int YEARS_400 = 400;

    const std::set LEAP_YEAR_SKIPS = {100, 200, 300};


    GregorianCalendar::GregorianCalendar(
        const int year,
        const Month month,
        const int day
    ) : Calendar(
            fixedFrom(year, static_cast<int>(month), day),
            GREGORIAN_EPOCH
        ),
        year(year), month(month), day(day) {
    }

    GregorianCalendar::GregorianCalendar(
        const int year,
        const int month,
        const int day
    ): GregorianCalendar(
        year, static_cast<Month>(month), day
    ) {
    }


    bool GregorianCalendar::isLeapYear(const int year) {
        return year % 4 == 0 && !LEAP_YEAR_SKIPS.contains(year % YEARS_400);
    }

    RataDie GregorianCalendar::fixedFrom(
        const int year,
        const int month,
        const int day
    ) {
        const int yearM1 = year - 1;

        int thisYearLeapDayOffset;
        if (month <= 2) {
            thisYearLeapDayOffset = 0;
        } else {
            if (isLeapYear(year)) {
                thisYearLeapDayOffset = 1;
            } else {
                thisYearLeapDayOffset = 2;
            }
        }

        return GREGORIAN_EPOCH - 1
               + DAYS_1_YEAR * yearM1 // max days in all previous years
               + intFloor(yearM1 / YEARS_4) // leap years - calculate all 4 years as leap years
               - intFloor(yearM1 / YEARS_100) // leap years - skip every leap year on a multiple of 100
               + intFloor(yearM1 / YEARS_400) // leap years - and re-add if it's a multiple of 400
               + intFloor(1 / 12 * (367 * month - 362)) // days in all previous months of this year
               - thisYearLeapDayOffset // offset depending on leap year
               + day; // days in this month
    }

    GregorianCalendar *GregorianCalendar::addDays(int days) {
        return nullptr;
    }

    int GregorianCalendar::yearFromFixed(RataDie rata_die) {
        const int d0 = rata_die - static_cast<int>(GREGORIAN_EPOCH);
        const int d1 = d0 % DAYS_400_YEARS;
        const int d2 = d1 % DAYS_100_YEARS;
        const int d3 = d2 % DAYS_4_YEARS;

        const int n400 = intFloor(d0 / DAYS_400_YEARS);
        const int n100 = intFloor(d1 / DAYS_100_YEARS);
        const int n4 = intFloor(d2 / DAYS_4_YEARS);
        const int n1 = intFloor(d3 / DAYS_1_YEAR);

        return YEARS_400 * n400
               + YEARS_100 * n100
               + YEARS_4 * n4
               + n1;
    }

    GregorianCalendar *GregorianCalendar::fromFixed(const RataDie rata_die) {
        // Calculate the year
        const int year = yearFromFixed(rata_die);

        // Calculate the prior-days
        const int priorDays = rata_die - fixedNewYear(year);

        // Calculate the correction
        int correction;
        if (rata_die < fixedFrom(year, 3, 1)) {
            correction = 0;
        } else if (isLeapYear(year)) {
            correction = 1;
        } else {
            correction = 2;
        }

        // Calculate the month
        const int month = intFloor(
            1 / 367 * (12 * (priorDays + correction) + 373)
        );

        // Calculate the day
        const int day = rata_die - fixedFrom(year, month, 1) + 1;

        return new GregorianCalendar(year, month, day);
    }

    RataDie GregorianCalendar::toFixed() const {
        return fixedFrom(year, static_cast<int>(month), day);
    }

    RataDie GregorianCalendar::fixedNewYear(const int year) {
        return fixedFrom(year, 1, 1);
    }

    RataDie GregorianCalendar::fixedYearEnd(const int year) {
        return fixedFrom(year, 12, 31);
    }
}
