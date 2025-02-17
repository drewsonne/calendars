#include "calendar.h"

#include <iostream>

namespace calendar {
    Calendar::Calendar(const RataDie rata_die, const RataDie epoch) : _rata_die(rata_die), _epoch(epoch) {}

    RataDie Calendar::rata_die() const {
        return _rata_die;
    }

    RataDie Calendar::epoch() const {
        return _epoch;
    }
};
