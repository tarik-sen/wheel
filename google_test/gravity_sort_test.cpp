//
// Created by Tarik SEN on 22.03.2023.
// Gravity Sort (Bead Sort) algorithm test
//

#include <gtest/gtest.h>
#include <wheel/sort/sort.hpp>
#include <wheel/util.hpp>

#include <vector>
#include <list>
#include <forward_list>


#define GRAVITY_SORT_TEST(TAG, CONTAINER, MIN, MAX, N)                                            \
    TEST(GravitySort, TAG) {                                                                      \
        std::vector vec = wheel::getRandomArray(MIN, MAX, N);                                     \
        CONTAINER c{vec.begin(), vec.end()};                                                      \
                                                                                                  \
        std::sort(vec.begin(), vec.end());                                                        \
        wheel::gravity_sort(c.begin(), c.end());                                                  \
                                                                                                  \
        ASSERT_TRUE(std::equal(c.begin(), c.end(), vec.begin()));                                 \
    }



GRAVITY_SORT_TEST(Forward, std::forward_list<int>, 0, 1000, 1000)

GRAVITY_SORT_TEST(Bidirectional, std::list<int>, 0, 1000, 1001)

GRAVITY_SORT_TEST(RandomAccess, std::vector<int>, 0, 1000, 999)

GRAVITY_SORT_TEST(Experiment001, std::vector<int>, 0, 1000, 1)

GRAVITY_SORT_TEST(Experiment002, std::vector<int>, 0, 10000, 100)

GRAVITY_SORT_TEST(Experiment003, std::vector<int>, 0, 1000, 1453)