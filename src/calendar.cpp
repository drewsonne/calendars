#include "calendar.h"

#include <iostream>

namespace calendar {
    Calendar::Calendar(
        const RataDie rata_die,
        const RataDie epoch
    ) : rata_die(rata_die),
        epoch(epoch) {
    }

    int Calendar::daysUntil(const Calendar *cal) const {
        return cal->toFixed() - toFixed();
    }

    int Calendar::intFloor(const int val) {
        return static_cast<int>(std::floor(val));
    }

    int Calendar::intFloor(const double val) {
        return static_cast<int>(std::floor(val));
    }
};
