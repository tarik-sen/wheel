//
// Created by Tarik SEN on 18.03.2023.
// Shell Sort algorithm test.
//

#include <gtest/gtest.h>
#include <wheel/sort/sort.hpp>
#include <wheel/util.hpp>

#include <vector>
#include <list>


#define SHELL_SORT_TEST(TAG, CONTAINER, MIN, MAX, N, COMPARE)                                     \
    TEST(ShellSort, TAG) {                                                                        \
        std::vector vec = wheel::getRandomArray(MIN, MAX, N);                                     \
        CONTAINER c{vec.begin(), vec.end()};                                                      \
                                                                                                  \
        std::sort(vec.begin(), vec.end(), COMPARE);                                               \
        wheel::shell_sort(c.begin(), c.end(), COMPARE);                                           \
                                                                                                  \
        ASSERT_TRUE(std::equal(c.begin(), c.end(), vec.begin()));                                 \
    }




SHELL_SORT_TEST(LessRandomAccess, std::vector<int>, INT32_MIN, INT32_MAX, 1'000, std::less<>())

SHELL_SORT_TEST(GreaterRandomAccess, std::vector<int>, INT32_MIN, INT32_MAX, 1'111, std::greater<>())

SHELL_SORT_TEST(Experiment001, std::vector<float>, -500.0f, 500.0f, 1, std::greater<>())

SHELL_SORT_TEST(Experiment002, std::vector<double>, -500.0, 500.0, 100, std::greater<>())

SHELL_SORT_TEST(Experiment003, std::vector<double>, -100.0, 100.0, 1000, std::less<>())