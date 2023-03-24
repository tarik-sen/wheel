cmake_minimum_required(VERSION 3.10)

project(google_tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(GoogleTest quick_sort_test.cpp bubble_sort_test.cpp selection_sort_test.cpp insertion_sort_test.cpp bucket_sort_test.cpp counting_sort_test.cpp stable_counting_sort_test.cpp radix_sort_test.cpp merge_sort_test.cpp heap_sort_test.cpp shell_sort_test.cpp cocktail_sort_test.cpp gravity_sort_test.cpp)
target_link_libraries(GoogleTest gtest gtest_main)