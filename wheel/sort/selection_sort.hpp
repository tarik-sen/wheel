//
// Created by Tarik SEN on 16.03.2023.
// Selection Sort algorithm implementation.
//

#ifndef WHEEL_SELECTION_SORT_HPP
#define WHEEL_SELECTION_SORT_HPP

#include <iterator>
#include <wheel/util.hpp>


namespace wheel {

    // One-Edged selection sort.
    template<std::forward_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void selection_sort(Iterator start, Iterator end, Compare comp = Compare{}) {
        for (Iterator i = start; i != end; ++i) {
            Iterator cur_min = i;
            for (Iterator j = i; j != end; ++j) {
                if (comp(*j, *cur_min))
                    cur_min = j;
            }

            if (i != cur_min)
                std::iter_swap(i, cur_min);
        }
    }


    // Double-Edged selection sort.
    template<std::bidirectional_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void selection_sort(Iterator start, Iterator end, Compare comp = Compare{}) {
        for (Iterator i = start; i != wheel::prev(end) && i != end; ++i, --end) {
            Iterator cur_min = i, cur_max = i;
            for (Iterator j = wheel::next(i); j != end; ++j) {
                if (comp(*j, *cur_min))
                    cur_min = j;
                else if (comp(*cur_max, *j))
                    cur_max = j;
            }

            if (i != cur_min)
                std::iter_swap(i, cur_min);

            cur_max = comp(*cur_max, *cur_min) ? cur_min : cur_max;
            if (cur_max != wheel::prev(end))
                std::iter_swap(wheel::prev(end), cur_max);
        }
    }

}

#endif //WHEEL_SELECTION_SORT_HPP
