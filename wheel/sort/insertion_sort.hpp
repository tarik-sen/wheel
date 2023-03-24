//
// Created by Tarik SEN on 16.03.2023.
// Insertion Sort algorithm implementation.
//

#ifndef WHEEL_INSERTION_SORT_HPP
#define WHEEL_INSERTION_SORT_HPP

#include <iterator>
#include <concepts>
#include <wheel/util.hpp>


namespace wheel {

    template <std::bidirectional_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>> &&
            std::movable<std::iter_value_t<Iterator>>
    void insertion_sort(Iterator start, Iterator end, Compare comp=Compare{}) {
        for (Iterator i = wheel::next(start); i != end; ++i) {
            auto temp = std::move(*i);
            Iterator j = i;
            for (; j != start && comp(temp, *(wheel::prev(j))) ; --j)
                *j = std::move(*wheel::prev(j));

            *j = std::move(temp);
        }
    }

}

#endif //WHEEL_INSERTION_SORT_HPP
