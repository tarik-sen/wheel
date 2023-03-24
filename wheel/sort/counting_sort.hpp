//
// Created by Tarik SEN on 17.03.2023.
// Counting Sort algorithm implementation.
//

#ifndef WHEEL_COUNTING_SORT_HPP
#define WHEEL_COUNTING_SORT_HPP

#include <iterator>
#include <vector>


namespace wheel {

    // Unstable counting sort, max is the max element container has.
    template <std::forward_iterator Iterator> requires std::integral<std::iter_value_t<Iterator>>
    void counting_sort(Iterator start, Iterator end, int max=-1) {
        if (max < 0)
            max = *std::max_element(start, end);

        std::vector<int> count(max + 1);

        for (Iterator i = start; i != end; ++i)
            ++count[*i];

        for (int i = 0; i < count.size(); ++i) {
            while (count[i]--) {
                *start = i;
                ++start;
            }
        }
    }


    // Stable counting sort, max is the max element container has.
    template <std::bidirectional_iterator Iterator> requires std::integral<std::iter_value_t<Iterator>>
    void stable_counting_sort(Iterator start, Iterator end, int max=-1) {
        if (max < 0)
            max = *std::max_element(start, end);

        std::vector<int> sorted_data(std::distance(start, end));
        std::vector<int> count(max + 1);

        for (Iterator i = start; i != end; ++i)
            ++count[*i];

        for (int i = 1; i <= max; ++i)
            count[i] += count[i-1];

        for (auto i = --end; i != start; --i)
            sorted_data[--count[*i]] = *i;

        sorted_data[--count[*start]] = *start;

        std::copy(sorted_data.begin(), sorted_data.end(), start);
    }

}

#endif //WHEEL_COUNTING_SORT_HPP
