//
// Created by Tarik SEN on 17.03.2023.
// Radix Sort algorithm implementation.
//

#ifndef WHEEL_RADIX_SORT_HPP
#define WHEEL_RADIX_SORT_HPP

#include <iterator>
#include <concepts>
#include <vector>

namespace wheel {

    template <std::forward_iterator Iterator> requires std::integral<std::iter_value_t<Iterator>>
    void radix_sort(Iterator start, Iterator end) {
        auto bucket_sort = [](Iterator start, Iterator end, int pos) -> void {
            std::vector<std::vector<int>> bucket_vec(10);

            for (Iterator it = start; it != end; ++it)
                bucket_vec[(*it / pos) % 10].push_back(*it);

            for (auto& bucket: bucket_vec)
                start = std::copy(bucket.begin(), bucket.end(), start);

        };

        int max_elem = *std::max_element(start, end);
        for (int pos=1; max_elem / pos > 0; pos*=10)
            bucket_sort(start, end, pos);
    }

}


#endif //WHEEL_RADIX_SORT_HPP
