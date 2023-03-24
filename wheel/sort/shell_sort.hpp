//
// Created by Tarik SEN on 18.03.2023.
// Shell Sort algorithm implementation.
//

#ifndef WHEEL_SHELL_SORT_HPP
#define WHEEL_SHELL_SORT_HPP

#include <iterator>
#include <concepts>


namespace wheel {

    // forward_iterator & bidirectional iterator versions are omitted due to low performance.

    template <std::random_access_iterator Iterator, typename Compare=std::less<>> requires
            std::predicate<Compare, std::iter_value_t<Iterator>, std::iter_value_t<Iterator>> &&
            std::movable<std::iter_value_t<Iterator>>
    void shell_sort(Iterator start, Iterator end, Compare comp=Compare{}) {
        int n = end - start;
        int gap = 1;

        while (gap <= n / 3)
            gap = 3 * gap + 1;

        while (gap > 0) {
            for (Iterator i = start + gap; i != end; ++i) {
                auto temp = std::move(*i);
                Iterator j = i;
                for (; j - gap >= start && comp(temp, *(j - gap)); j -= gap)
                    *j = std::move(*(j - gap));

                *j = std::move(temp);
            }

            gap = (gap - 1) / 3;
        }
    }

}


#endif //WHEEL_SHELL_SORT_HPP
