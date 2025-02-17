//
// Created by Drew J. Sonne on 16/02/2025.
//

#include "gregorian_calendar.h"
#include <set>


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

        const int rata_die = static_cast<int>(GREGORIAN_EPOCH) - 1
                             + 365 * (yearM1) // max days in all previous years
                             + intFloor(yearM1 / 4) // leap years - calculate all 4 years as leap years
                             - intFloor(yearM1 / 100) // leap years - skip every leap year on a multiple of 100
                             + intFloor(yearM1 / 400) // leap years - and re-add if it's a multiple of 400
                             + intFloor(1 / 12 * (367 * month - 362)) // days in all previous months of this year
                             + leapDaysThisYear // leap days in this year
                             + day // days in this month
                ;
        return rata_die;
    }

    GregorianCalendar* GregorianCalendar::addDays(int days) {
        return nullptr;
    }

    GregorianCalendar* GregorianCalendar::fromFixed(RataDie rata_die) {
        constexpr int days400years = 146097;
        constexpr int days100years = 36524;
        constexpr int days4years = 1461;
        const int days1year = 365;

        int d0 = rata_die - static_cast<int>(GREGORIAN_EPOCH);
        int n400 = intFloor(d0/days400years);
        int d1 = d0 % days400years;
        int n100 = intFloor(d1/days100years);
        int d2 = d1 % days100years;
        int n4 = intFloor(d2/days4years);
        int d3 = d2 % days4years;
        int n1 = intFloor(d3 / days1year);
        int year = 400 * n400 + 100 * n100 + 4* n4 + n1;

        return new GregorianCalendar(year, 0, 0);
    }

    RataDie GregorianCalendar::toFixed() {
        return _fixedFromGregorian(_year, static_cast<int>(_month), _day);
    }
}
