//
// Created by Tarik SEN on 22.03.2023.
// Gravity Sort (Bead Sort) algorithm implementation
//

#ifndef WHEEL_GRAVITY_SORT_HPP
#define WHEEL_GRAVITY_SORT_HPP

#include <iterator>
#include <concepts>
#include <vector>
#include <cstring>
#include <iostream>


namespace wheel {

    template <std::forward_iterator Iterator> requires std::integral<std::iter_value_t<Iterator>>
    void gravity_sort(Iterator start, Iterator end) {
        auto max_elem = *std::max_element(start, end);
        int size = std::distance(start, end);

        // Creating bead matrix
        auto* bead_matrix = new(std::nothrow) unsigned char[size*max_elem];
        if (!bead_matrix) {
            std::cout << "Memory allocation failed\n";
            return;
        }

        memset(bead_matrix, 0, sizeof(unsigned char) * size * max_elem);

        Iterator cur_it = start;
        for (int i = 0; i < size; ++i, ++cur_it)
            for (int j = 0; j < *cur_it; ++j)
                bead_matrix[i*max_elem + j] = 1;

        // Sum every bead on every column and move them to bottom.
        for (int j=0; j < max_elem; ++j) {
            int sum = 0;
            for (int i = 0; i < size; ++i) {
                sum += bead_matrix[i*max_elem + j];
                bead_matrix[i*max_elem + j] = 0;
            }

            for (int i = size-sum; i < size; ++i)
                bead_matrix[i*max_elem + j] = 1;

        }


        // Get the sorted array
        for (int i=0; i < size; ++i) {
            int num = 0;
            while (num < max_elem && bead_matrix[i*max_elem + num])
                ++num;

            *start++ = num;
        }

        delete[] bead_matrix;

    }

}


#endif //WHEEL_GRAVITY_SORT_HPP
