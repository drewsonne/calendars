//
// Created by Drew J. Sonne on 11/02/2025.
//

#include "../src/calendar.h"
#include <string>
#include <string_view>
#include <vector>
#include <gtest/gtest.h>
#include <gtest/gtest-death-test.h>

TEST(Simple, Boolean)
{
  ASSERT_TRUE(true);
}
TEST(Simple, Cpp17StringView)
{
  const char* c = "test";
  std::string s{c};
  std::string_view sv{s};
  std::vector<std::string_view> vsv{sv};
  EXPECT_EQ(sv, s);
  EXPECT_EQ(sv, s.c_str());
  EXPECT_EQ(sv, "test");
}