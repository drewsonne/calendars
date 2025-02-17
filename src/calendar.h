#ifndef CALENDARS_LIBRARY_H
#define CALENDARS_LIBRARY_H

namespace calendar {
    typedef int RataDie;

    class Calendar {
    public:
        explicit Calendar(RataDie rata_die, RataDie epoch);

        virtual ~Calendar() = default;

        [[nodiscard]] RataDie rata_die() const;

        [[nodiscard]] RataDie epoch() const;

        virtual Calendar &add_days(int days);

    protected:
        virtual RataDie to_rata_die() = 0;

        RataDie _rata_die;
        RataDie _epoch;
    };
}; // namespace calendars

#endif //CALENDARS_LIBRARY_H
