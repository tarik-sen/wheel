//
// Created by Tarik SEN on 16.03.2023.
// Quick Sort algorithm implementation.
//

#ifndef WHEEL_QUICK_SORT_HPP
#define WHEEL_QUICK_SORT_HPP

#include <iterator>
#include <wheel/util.hpp>
#include <wheel/sort/sort.hpp>


namespace wheel {

    // Pivot is taken as first element.
    template<std::forward_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void quick_sort(Iterator start, Iterator end, Compare comp = Compare{}, int block = 10) {
        if (start == end || wheel::next(start) == end)
            return;

        if (block >= std::distance(start, end)) {
            wheel::selection_sort(start, end, comp);
            return;
        }


        // Partition Code
        Iterator pivot = start;
        Iterator i = start;
        for (Iterator j = wheel::next(start); j != end; j++) {
            if (comp(*j, *pivot)) {
                ++i;
                std::iter_swap(i, j);
            }
        }
        std::iter_swap(i, pivot);

        quick_sort(start, i, comp, block);
        quick_sort(wheel::next(i), end, comp, block);
    }


    // Pivot is taken as last element.
    template<std::bidirectional_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void quick_sort(Iterator start, Iterator end, Compare comp = Compare{}, int block = 10) {
        if (start == end || wheel::next(start) == end)
            return;

        if (block >= std::distance(start, end)) {
            wheel::selection_sort(start, end, comp);
            return;
        }


        // Partition Code
        Iterator pivot = wheel::prev(end);
        Iterator i = wheel::prev(start);
        for (Iterator j = start; j != pivot; j++) {
            if (comp(*j, *pivot)) {
                ++i;
                std::iter_swap(i, j);
            }
        }
        i++;
        std::iter_swap(i, pivot);

        quick_sort(start, i, comp, block);
        quick_sort(wheel::next(i), end, comp, block);
    }


    // NOTE: update the implementation so that the pivot is selected randomly.
    template<std::random_access_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void quick_sort(Iterator start, Iterator end, Compare comp = Compare{}, int block = 10) {
        if (start >= end)
            return;

        if (block >= end - start) {
            wheel::selection_sort(start, end, comp);
            return;
        }

        // Partition Code
        Iterator pivot = end-1;
        Iterator i = start-1;
        for (Iterator j = start; j != pivot; j++) {
            if (comp(*j, *pivot)) {
                ++i;
                std::iter_swap(i, j);
            }
        }
        i++;
        std::iter_swap(i, pivot);

        quick_sort(start, i, comp, block);
        quick_sort(i+1, end, comp, block);
    }
}

#endif //WHEEL_QUICK_SORT_HPP
