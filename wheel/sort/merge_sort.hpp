//
// Created by Tarik SEN on 17.03.2023.
// Merge Sort algorithm implementation.
//

#ifndef WHEEL_MERGE_SORT_HPP
#define WHEEL_MERGE_SORT_HPP

#include <iterator>
#include <vector>
#include <functional>

#include <wheel/util.hpp>

namespace wheel {

    template<std::forward_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void merge_sort(Iterator start, Iterator end, Compare comp = Compare{}) {
        if (start == end || wheel::next(start) == end)
            return;

        Iterator mid = start;
        std::advance(mid, std::distance(start, end) / 2);
        merge_sort(start, mid, comp);
        merge_sort(mid, end, comp);

        // Merge Part
        std::vector<std::iter_value_t<Iterator>> arr_left(start, mid);
        std::vector<std::iter_value_t<Iterator>> arr_right(mid, end);

        unsigned size_left = arr_left.size();
        unsigned size_right = arr_right.size();
        unsigned i = 0, j = 0;
        while (i < size_left && j < size_right) {
            if (comp(arr_left[i], arr_right[j]))
                *start = arr_left[i++];
            else
                *start = arr_right[j++];
            ++start;
        }

        while (i < size_left) {
            *start = arr_left[i++];
            ++start;
        }

        while (j < size_right) {
            *start = arr_right[j++];
            ++start;
        }

    }


    // Usage of std::inplace_merge to get rid of code repetition.
    template<std::random_access_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void merge_sort(Iterator start, Iterator end, Compare comp = Compare{}) {
        if (start + 1 >= end)
            return;

        Iterator mid = start + (end - start) / 2;
        merge_sort(start, mid, comp);
        merge_sort(mid, end, comp);

        std::inplace_merge(start, mid, end, comp);
    }
}

#endif //WHEEL_MERGE_SORT_HPP
