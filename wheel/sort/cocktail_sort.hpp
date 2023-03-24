//
// Created by Tarik SEN on 18.03.2023.
// Cocktail Sort algorithm implementation.
//

#ifndef WHEEL_COCKTAIL_SORT_HPP
#define WHEEL_COCKTAIL_SORT_HPP

#include <iterator>
#include <concepts>

#include <wheel/util.hpp>


namespace wheel {

    template<std::bidirectional_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>>
    void cocktail_sort(Iterator start, Iterator end, Compare comp = Compare{}) {
        while (start != end) {
            // First Part - Find maximum
            Iterator cur_max = start;
            for (Iterator i = wheel::next(start); i != end; ++i) {
                if (comp(*cur_max, *i))
                    cur_max = i;
            }
            if (--end != cur_max)
                std::iter_swap(end, cur_max);

            // Break if done
            if (start == end)
                break;

            // Second Part - Find minimum
            Iterator cur_min = start;
            for (Iterator i = wheel::prev(end); i != start; --i) {
                if (comp(*i, *cur_min))
                    cur_min = i;
            }

            if (start != cur_min)
                std::iter_swap(start, cur_min);
            ++start;
        }

    }

}


#endif //WHEEL_COCKTAIL_SORT_HPP
