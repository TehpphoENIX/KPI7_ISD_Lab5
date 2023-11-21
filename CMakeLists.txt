cmake_minimum_required(VERSION 3.5.0)
project(Lab5TDDExample VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Lab5TDDExample main.cpp)

#Tests
add_executable(Test1 tests/test1.cpp)
add_test(Buffer_dont_overflow Test1)

add_executable(Test2 tests/test2.cpp)
add_test(Buffer_output_is_correct Test2)

add_executable(Test3 tests/test3.cpp)
add_test(Buffer_is_cleaned_correctly Test3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
