//
// Created by Drew J. Sonne on 16/02/2025.
//

#include "gregorian_calendar.h"
#include <set>
#include <cmath>


namespace calendar::gregorian {
    const RataDie GREGORIAN_EPOCH = 1;

    GregorianCalendar::GregorianCalendar(const int year, const int month, const int day): Calendar(
        _fixedFromGregorian(year, month, day), GREGORIAN_EPOCH) {
        _year = year;
        _month = static_cast<Month>(month);
        _day = day;
    }

    int GregorianCalendar::year() const {
        return _year;
    }

    Month GregorianCalendar::month() const {
        return _month;
    }

    int GregorianCalendar::day() const {
        return _day;
    }

    RataDie GregorianCalendar::_fixedFromGregorian(const int year, const int month, const int day) {
        const std::set hundredYearSkips = {100, 200, 300};
        const int yearM1 = year - 1;

        int leapDaysThisYear;
        if (month <= 2) {
            leapDaysThisYear = 0;
        } else {
            if (year % 4 == 0 && (!hundredYearSkips.contains(year % 400))) {
                leapDaysThisYear = -1;
            } else {
                leapDaysThisYear = -2;
            }
        }

        return GREGORIAN_EPOCH - static_cast<RataDie>(1
               + 365 * (yearM1) // max days in all previous years
               + std::floor(yearM1 / 4) // leap years - calculate all 4 years as leap years
               - std::floor(yearM1 / 100) // leap years - skip every leap year on a multiple of 100
               + std::floor(yearM1 / 400) // leap years - and re-add if it's a multiple of 400
               + std::floor(1 / 12 * (367 * month - 362)) // days in all previous months of this year
               + leapDaysThisYear // leap days in this year
               + day // days in this month
        );
    }
}
