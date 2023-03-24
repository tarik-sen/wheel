//
// Created by Tarik SEN on 16.03.2023.
// Generic Google Benchmark
// Present the run speed of each sort algorithm on same data set.
// TEST_NUM, TEST_LENGTH, TEST_MIN and TEST_MAX macro's can be changed to get results on a different data set.
//

#include <benchmark/benchmark.h>
#include <vector>
#include <list> 
#include <forward_list>

#include <wheel/sort/sort.hpp>
#include <wheel/util.hpp>

#define TEST_NUM 1
#define TEST_LENGTH 500
#define TEST_MAX 1000
#define TEST_MIN 0

#define SORT_BENCHMARK(TAG, CONTAINER, SORT_ALGORITHM) \
    static void TAG(benchmark::State& state) { \
        sortBenchmark<CONTAINER>(state, [](auto start, auto end) { SORT_ALGORITHM(start, end); }); \
    } \
    BENCHMARK(TAG)->DenseRange(0, TEST_NUM-1)->Unit(benchmark::kMillisecond);

#define SORT_BENCHMARK_1(TAG, CONTAINER, SORT_ALGORITHM, ARG_1) \
    static void TAG(benchmark::State& state) { \
        sortBenchmark<CONTAINER>(state, [](auto start, auto end) { SORT_ALGORITHM(start, end, ARG_1); }); \
    } \
    BENCHMARK(TAG)->DenseRange(0, TEST_NUM-1)->Unit(benchmark::kMillisecond);


// Benchmark Data
std::vector<std::vector<int>> benchmark_data(TEST_NUM, wheel::getRandomArray(TEST_MIN, TEST_MAX, TEST_LENGTH));


template <typename Container, typename SortAlgorithm>
void sortBenchmark(benchmark::State& state, SortAlgorithm sortAlgorithm) {
    long data_set_id = state.range(0);

    for (auto _: state) {
        state.PauseTiming();
        Container copy_container(benchmark_data[data_set_id].begin(), benchmark_data[data_set_id].end());
        state.ResumeTiming();

        sortAlgorithm(copy_container.begin(), copy_container.end());
    }
}


SORT_BENCHMARK(bubbleSortForward, std::forward_list<int>, wheel::bubble_sort)
SORT_BENCHMARK(bubbleSortBidirectional, std::list<int>, wheel::bubble_sort)
SORT_BENCHMARK(bubbleSortRandomAccess, std::vector<int>, wheel::bubble_sort)

SORT_BENCHMARK(selectionSortForward, std::forward_list<int>, wheel::selection_sort)
SORT_BENCHMARK(selectionSortBidirectional, std::list<int>, wheel::selection_sort)
SORT_BENCHMARK(selectionSortRandomAccess, std::vector<int>, wheel::selection_sort)

SORT_BENCHMARK(insertionSortBidirectional, std::list<int>, wheel::insertion_sort)
SORT_BENCHMARK(insertionSortRandomAccess, std::vector<int>, wheel::insertion_sort)

SORT_BENCHMARK(cocktailSortBidirectional, std::list<int>, wheel::cocktail_sort)
SORT_BENCHMARK(cocktailSortRandomAccess, std::vector<int>, wheel::cocktail_sort)

SORT_BENCHMARK(shellSortRandomAccess, std::vector<int>, wheel::shell_sort)

SORT_BENCHMARK(mergeSortForward, std::forward_list<int>, wheel::merge_sort)
SORT_BENCHMARK(mergeSortBidirectional, std::list<int>, wheel::merge_sort)
SORT_BENCHMARK(mergeSortRandomAccess, std::vector<int>, wheel::merge_sort)

SORT_BENCHMARK(heapSortBidirectional, std::list<int>, wheel::heap_sort)
SORT_BENCHMARK(heapSortRandomAccess, std::vector<int>, wheel::heap_sort)

SORT_BENCHMARK(quickSortForward, std::forward_list<int>, wheel::quick_sort)
SORT_BENCHMARK(quickSortBidirectional, std::list<int>, wheel::quick_sort)
SORT_BENCHMARK(quickSortRandomAccess, std::vector<int>, wheel::quick_sort)

SORT_BENCHMARK_1(bucketSortForward10, std::forward_list<int>, wheel::bucket_sort, 10)
SORT_BENCHMARK_1(bucketSortBidirectional10, std::list<int>, wheel::bucket_sort, 10)
SORT_BENCHMARK_1(bucketSortRandomAccess10, std::vector<int>, wheel::bucket_sort, 10)

SORT_BENCHMARK_1(bucketSortForward100, std::forward_list<int>, wheel::bucket_sort, 100)
SORT_BENCHMARK_1(bucketSortBidirectional100, std::list<int>, wheel::bucket_sort, 100)
SORT_BENCHMARK_1(bucketSortRandomAccess100, std::vector<int>, wheel::bucket_sort, 100)

SORT_BENCHMARK_1(bucketSortForward1000, std::forward_list<int>, wheel::bucket_sort, 1000)
SORT_BENCHMARK_1(bucketSortBidirectional1000, std::list<int>, wheel::bucket_sort, 1000)
SORT_BENCHMARK_1(bucketSortRandomAccess1000, std::vector<int>, wheel::bucket_sort, 1000)

SORT_BENCHMARK_1(unstableCountingSortForward, std::forward_list<int>, wheel::counting_sort, -1)
SORT_BENCHMARK_1(unstableCountingSortBidirectional, std::list<int>, wheel::counting_sort, -1)
SORT_BENCHMARK_1(unstableCountingSortRandomAccess, std::vector<int>, wheel::counting_sort, -1)

SORT_BENCHMARK_1(stableCountingSortBidirectional, std::list<int>, wheel::stable_counting_sort, -1)
SORT_BENCHMARK_1(stableCountingSortRandomAccess, std::vector<int>, wheel::stable_counting_sort, -1)

SORT_BENCHMARK(radixSortForward, std::forward_list<int>, wheel::radix_sort)
SORT_BENCHMARK(radixSortBidirectional, std::list<int>, wheel::radix_sort)
SORT_BENCHMARK(radixSortRandomAccess, std::vector<int>, wheel::radix_sort)

SORT_BENCHMARK(gravitySortForward, std::forward_list<int>, wheel::gravity_sort)
SORT_BENCHMARK(gravitySortBidirectional, std::list<int>, wheel::gravity_sort)
SORT_BENCHMARK(gravitySortRandomAccess, std::vector<int>, wheel::gravity_sort)

SORT_BENCHMARK(stdSortRandomAccess, std::vector<int>, std::sort)



BENCHMARK_MAIN();
