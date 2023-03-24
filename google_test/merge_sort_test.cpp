//
// Created by Tarik SEN on 17.03.2023.
// Merge Sort algorithm test.
//

#include <gtest/gtest.h>
#include <wheel/sort/sort.hpp>
#include <wheel/util.hpp>

#include <vector>
#include <list>
#include <forward_list>


#define MERGE_SORT_TEST(TAG, CONTAINER, MIN, MAX, N, COMPARE)                                     \
    TEST(MergeSort, TAG) {                                                                        \
        std::vector vec = wheel::getRandomArray(MIN, MAX, N);                                     \
        CONTAINER c{vec.begin(), vec.end()};                                                      \
                                                                                                  \
        std::sort(vec.begin(), vec.end(), COMPARE);                                               \
        wheel::merge_sort(c.begin(), c.end(), COMPARE);                                           \
                                                                                                  \
        ASSERT_TRUE(std::equal(c.begin(), c.end(), vec.begin()));                                 \
    }



MERGE_SORT_TEST(LessForward, std::forward_list<int>, INT32_MIN, INT32_MAX, 1'000, std::less<>())

MERGE_SORT_TEST(LessBidirectional, std::list<int>, INT32_MIN, INT32_MAX, 1'000, std::less<>())

MERGE_SORT_TEST(LessRandomAccess, std::vector<int>, INT32_MIN, INT32_MAX, 1'000, std::less<>())

MERGE_SORT_TEST(GreaterForward, std::forward_list<int>, INT32_MIN, INT32_MAX, 1'001, std::greater<>())

MERGE_SORT_TEST(GreaterBidirectional, std::list<int>, INT32_MIN, INT32_MAX, 1'001, std::greater<>())

MERGE_SORT_TEST(GreaterRandomAccess, std::vector<int>, INT32_MIN, INT32_MAX, 1'001, std::greater<>())

MERGE_SORT_TEST(Experiment001, std::list<float>, -500.0f, 500.0f, 1, std::greater<>())

MERGE_SORT_TEST(Experiment002, std::vector<double>, -500.0, 500.0, 100, std::greater<>())

MERGE_SORT_TEST(Experiment003, std::vector<double>, -100.0, 100.0, 1000, std::less<>())