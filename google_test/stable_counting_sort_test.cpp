//
// Created by Tarik SEN on 17.03.2023.
// Stable Counting Sort algorithm test.
//

#include <gtest/gtest.h>
#include <wheel/sort/sort.hpp>

#include <vector>
#include <list>


#define STABLE_COUNTING_SORT_TEST(TAG, CONTAINER, MIN, MAX, N, MAX_VAL)                           \
    TEST(StableCountingSort, TAG) {                                                               \
        std::vector vec = wheel::getRandomArray(MIN, MAX, N);                                     \
        CONTAINER c{vec.begin(), vec.end()};                                                      \
                                                                                                  \
        std::sort(vec.begin(), vec.end());                                                        \
        wheel::stable_counting_sort(c.begin(), c.end(), MAX_VAL);                                 \
                                                                                                  \
        ASSERT_TRUE(std::equal(c.begin(), c.end(), vec.begin()));                                 \
    }



STABLE_COUNTING_SORT_TEST(BidirectionalU, std::list<int>, 0, 10'000, 1'000, -1)
STABLE_COUNTING_SORT_TEST(BidirectionalM, std::list<int>, 0, 10'000, 1'000, 10'000)

STABLE_COUNTING_SORT_TEST(RandomAccessU, std::vector<int>, 0, 10'000, 1'000, -1)
STABLE_COUNTING_SORT_TEST(RandomAccessM, std::vector<int>, 0, 10'000, 1'000, 10'000)

STABLE_COUNTING_SORT_TEST(Experiment001, std::vector<int>, 0, 100'000, 10'000, -1)
STABLE_COUNTING_SORT_TEST(Experiment002, std::vector<int>, 0, 10, 100, -1)