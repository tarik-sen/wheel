//
// Created by Tarik SEN on 17.03.2023.
// Bucket Sort algorithm implementation.
//

#ifndef WHEEL_BUCKET_SORT_HPP
#define WHEEL_BUCKET_SORT_HPP

#include <iterator>
#include <vector>

#include <wheel/sort/sort.hpp>
#include <wheel/util.hpp>

namespace wheel {

    template<std::forward_iterator Iterator> requires
            std::integral<std::iter_value_t<Iterator>> ||
            std::floating_point<std::iter_value_t<Iterator>>
    void bucket_sort(Iterator start, Iterator end, unsigned int bucket) {
        auto min_max = std::minmax_element(start, end);
        Iterator min_elem = min_max.first;
        Iterator max_elem = min_max.second;

        if (*min_elem == *max_elem)
            return;

        double bucket_size = static_cast<double>(*max_elem - *min_elem + 0.000001) / bucket;
        std::vector<std::vector<std::iter_value_t<Iterator>>> bucket_vec(bucket);

        for (Iterator it = start; it != end; ++it) {
            auto bucket_ind = static_cast<int>((*it - *min_elem) / bucket_size);
            bucket_vec[bucket_ind].push_back(*it);
        }

        for (auto& arr: bucket_vec)
            wheel::quick_sort(arr.begin(), arr.end());

        for (auto& arr: bucket_vec)
            start = std::copy(arr.begin(), arr.end(), start);
    }

}


#endif //WHEEL_BUCKET_SORT_HPP
