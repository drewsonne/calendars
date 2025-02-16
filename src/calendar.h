#ifndef CALENDARS_LIBRARY_H
#define CALENDARS_LIBRARY_H

namespace calendar {

    typedef int RataDie;

    class Calendar {
      public:
        explicit Calendar(RataDie rata_die);
        ~Calendar() = default;
        RataDie rata_die;
        Calendar& add_days(int days);
    };

    namespace gregorian {
        class GregorianCalendar : public Calendar {
          public:
            GregorianCalendar(int year, int month, int day);
            explicit GregorianCalendar(RataDie rata_die);
            int year();
            int month();
            int day();
            int day_of_week();
            GregorianCalendar& add_days(int days);
        };
    }; // namespace gregorian

}; // namespace calendars

#endif //CALENDARS_LIBRARY_H