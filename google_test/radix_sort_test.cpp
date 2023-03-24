//
// Created by Tarik SEN on 17.03.2023.
// Radix Sort algorithm test.
//

#include <gtest/gtest.h>
#include <wheel/sort/sort.hpp>

#include <vector>
#include <list>
#include <forward_list>


#define RADIX_SORT_TEST(TAG, CONTAINER, MIN, MAX, N)                                              \
    TEST(RadixSort, TAG) {                                                                        \
        std::vector vec = wheel::getRandomArray(MIN, MAX, N);                                     \
        CONTAINER c{vec.begin(), vec.end()};                                                      \
                                                                                                  \
        std::sort(vec.begin(), vec.end());                                                        \
        wheel::radix_sort(c.begin(), c.end());                                                    \
                                                                                                  \
        ASSERT_TRUE(std::equal(c.begin(), c.end(), vec.begin()));                                 \
    }



RADIX_SORT_TEST(Forward, std::forward_list<int>, 0, 10'000, 1000)

RADIX_SORT_TEST(Bidirectional, std::list<int>, 0, 10'000, 1000)

RADIX_SORT_TEST(RandomAccess, std::vector<int>, 0, 10'000, 1000)

RADIX_SORT_TEST(Experiment001, std::vector<int>, 0, INT32_MAX, 10'000)

RADIX_SORT_TEST(Experiment002, std::vector<int>, 0, 10'000, 1)

RADIX_SORT_TEST(Experiment003, std::vector<int>, 0, INT32_MAX, 1453)