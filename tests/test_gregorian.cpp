//
// Created by Drew J. Sonne on 11/02/2025.
//

#include <string>
#include <string_view>
#include <vector>
#include <gtest/gtest.h>

#include "../src/gregorian_calendar.h"

TEST(GregorianCalendar, Properties) {
  GregorianCalendar gc(2025, 2, 16);
  ASSERT_EQ(gc.year() , 2025);
  ASSERT_EQ(gc.month() , 2);
  ASSERT_EQ(gc.day() , 16);
}
TEST(GregorianCalendar, DataRie) {
  GregorianCalendar gc(0,);
}