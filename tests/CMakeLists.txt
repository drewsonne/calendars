enable_testing()

project(calendar_tests)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 'lib' is the folder with Google Test sources
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'test_calendar' is the target name
# 'test_calendar.cpp' is the source file with tests
add_executable(
        test_calendar
        test_calendar.cpp
)

target_link_libraries(
        test_calendar
        gtest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_calendar)