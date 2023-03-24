//
// Created by Tarik SEN on 16.03.2023.
// Bubble Sort algorithm implementation.
//

#ifndef WHEEL_BUBBLE_SORT_HPP
#define WHEEL_BUBBLE_SORT_HPP

#include <iterator>
#include <wheel/util.hpp>

namespace wheel {

    template<std::forward_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void bubble_sort(Iterator start, Iterator end, Compare comp = Compare{}) {
        for (Iterator i = start; wheel::next(i) != end; ++i) {
            for (Iterator j = start; wheel::next(j) != end; ++j) {
                if (comp(*wheel::next(j), *j))
                    std::iter_swap(j, wheel::next(j));
            }
        }
    }


    template<std::bidirectional_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void bubble_sort(Iterator start, Iterator end, Compare comp = Compare{}) {
        Iterator border = --end;
        for (Iterator i = start; i != end; ++i, --border) {
            for (Iterator j = start; j != border; ++j) {
                if (comp(*wheel::next(j), *j))
                    std::iter_swap(j, wheel::next(j));
            }
        }
    }

}

#endif //WHEEL_BUBBLE_SORT_HPP
