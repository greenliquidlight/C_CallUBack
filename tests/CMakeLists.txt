cmake_minimum_required(VERSION 3.20)

# fetch google test to use for testing
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

# Add test executables
add_executable(self_test self_test.cpp)
add_executable(C_Callback_test test_C_Callback.cpp)

# Link against google test and the C_Callback library
target_link_libraries(self_test gtest_main C_Callback)
target_link_libraries(C_Callback_test gtest_main C_Callback)

add_test(NAME self_test COMMAND self_test)
add_test(NAME C_Callback_test COMMAND C_Callback_test)
