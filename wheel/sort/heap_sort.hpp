//
// Created by Tarik SEN on 17.03.2023.
// Heap Sort algorithm implementation.
//

#ifndef WHEEL_HEAP_SORT_HPP
#define WHEEL_HEAP_SORT_HPP

#include <iterator>
#include <vector>
#include <functional>
#include <wheel/util.hpp>


namespace wheel {

    template <std::bidirectional_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void heap_sort(Iterator start, Iterator end, Compare comp=Compare{}) {
        // Heapify function
        std::function<void(Iterator, int, int)> heapify = [&comp, &heapify](Iterator start, int n, int s) -> void {
            int left_n = 2 * n + 1;

            if (left_n >= s)
                return;

            int new_ind = n;
            Iterator root = start, left = start;
            std::advance(root, n);
            std::advance(left, left_n);

            Iterator cur_max = root;

            if (comp(*cur_max, *left)) {
                cur_max = left;
                new_ind = left_n;
            }
            if (left_n + 1 < s && comp(*cur_max, *wheel::next(left))) {
                cur_max = wheel::next(left);
                new_ind = left_n + 1;
            }

            if (new_ind != n) {
                std::iter_swap(root, cur_max);

                heapify(start, new_ind, s);
            }
        };

        int s = std::distance(start, end);

        // Create Max-Heap
        for (int n = s / 2 - 1; n >= 0; n--)
            heapify(start, n, s);

        // Heap Sort
        while (s > 0) {
            std::iter_swap(start, --end);
            heapify(start, 0, --s);
        }
    }


    template <std::random_access_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void heap_sort(Iterator start, Iterator end, Compare comp=Compare{}) {
        // Heapify function
        std::function<void(Iterator, Iterator, Iterator)> heapify = [&comp, &heapify](Iterator start, Iterator root, Iterator end) -> void {
            Iterator left = root, right = root;
            std::advance(left,  root - start + 1);
            std::advance(right, root - start + 2);

            if (left >= end)
                return;

            Iterator cur_max = root;

            if (comp(*cur_max, *left))
                cur_max = left;
            if (right < end && comp(*cur_max, *right))
                cur_max = right;

            if (cur_max != root) {
                std::iter_swap(root, cur_max);

                heapify(start, cur_max, end);
            }
        };

        // Create Max-Heap
        for (Iterator n = start + (end - start) / 2 - 1; n >= start; --n)
            heapify(start, n, end);

        // Heap Sort
        while (start < end) {
            std::iter_swap(start, --end);
            heapify(start, start, end);
        }
    }

}


#endif //WHEEL_HEAP_SORT_HPP
