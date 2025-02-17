#ifndef CALENDARS_LIBRARY_H
#define CALENDARS_LIBRARY_H

namespace calendar {
    typedef int RataDie;

    class Calendar {
    public:
        explicit Calendar(RataDie rata_die, RataDie epoch);

        const RataDie rata_die;
        const RataDie epoch;

        int daysUntil(const Calendar *cal) const;

        virtual ~Calendar() = default;

        virtual Calendar *addDays(int days) = 0;

        virtual Calendar *fromFixed(RataDie rata_die) = 0;

        [[nodiscard]]
        virtual RataDie toFixed() const = 0;

        static int intFloor(int val);

        static int intFloor(double val);
    };
}; // namespace calendars

#endif //CALENDARS_LIBRARY_H
