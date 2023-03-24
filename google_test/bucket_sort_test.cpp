//
// Created by Tarik SEN on 17.03.2023.
// Bucket Sort algorithm test.
//

#include <gtest/gtest.h>
#include <wheel/sort/sort.hpp>
#include <wheel/util.hpp>

#include <vector>
#include <list>
#include <forward_list>


#define BUCKET_SORT_TEST(TAG, CONTAINER, MIN, MAX, N, BUCKET)                                     \
    TEST(BucketSort, TAG) {                                                                       \
        std::vector vec = wheel::getRandomArray(MIN, MAX, N);                                     \
        CONTAINER c{vec.begin(), vec.end()};                                                      \
                                                                                                  \
        std::sort(vec.begin(), vec.end());                                                        \
        wheel::bucket_sort(c.begin(), c.end(), BUCKET);                                           \
                                                                                                  \
        ASSERT_TRUE(std::equal(c.begin(), c.end(), vec.begin()));                                 \
    }



BUCKET_SORT_TEST(Forward, std::forward_list<int>, 0, 10'000, 1'000, 10)

BUCKET_SORT_TEST(Bidirectional, std::list<int>, 0, 10'000, 1'001, 20)

BUCKET_SORT_TEST(RandomAccess, std::vector<int>, 0, 10'000, 1'000, 40)

BUCKET_SORT_TEST(Experiment001, std::list<float>, 0.0f, 10'000.0f, 1'000, 60)

BUCKET_SORT_TEST(Experiment002, std::vector<double>, 0.0, 100'000.0, 1, 53)

BUCKET_SORT_TEST(Experiment003, std::vector<double>, 0.0, 10'000.0, 1'000, 100)