cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(self_test self_test.cpp)
target_link_libraries(self_test gtest_main)

add_test(NAME self_test COMMAND self_test)
