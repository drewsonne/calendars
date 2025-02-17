#include "calendar.h"

#include <iostream>

namespace calendar {
    Calendar::Calendar(const RataDie rata_die, const RataDie epoch) : _rata_die(rata_die), _epoch(epoch) {}

    RataDie Calendar::rataDie() const {
        return _rata_die;
    }

    RataDie Calendar::epoch() const {
        return _epoch;
    }

    int Calendar::intFloor(const int val) {
        return static_cast<int>(std::floor(val));
    }

    int Calendar::intFloor(const double val) {
        return static_cast<int>(std::floor(val));
    }
};
