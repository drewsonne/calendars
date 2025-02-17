#ifndef CALENDARS_LIBRARY_H
#define CALENDARS_LIBRARY_H

namespace calendar {
    typedef int RataDie;

    class Calendar {
    public:
        explicit Calendar(RataDie rata_die, RataDie epoch);

        virtual ~Calendar() = default;

        [[nodiscard]] RataDie rataDie() const;

        [[nodiscard]] RataDie epoch() const;

        virtual Calendar *addDays(int days) = 0;

        virtual Calendar *fromFixed(RataDie rata_die) = 0;

        virtual RataDie toFixed() = 0;

        static int intFloor(int val);

        static int intFloor(double val);

    protected:
        RataDie _rata_die;
        RataDie _epoch;
    };
}; // namespace calendars

#endif //CALENDARS_LIBRARY_H
