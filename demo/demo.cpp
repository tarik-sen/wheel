//
// Created by Tarik SEN on 22.03.2023.
// Demonstration of some sort functions.
//

#include <iostream>
#include <ranges>
#include <forward_list>
#include <list>

#include <wheel/sort/sort.hpp>
#include <wheel/util.hpp>


using namespace std;


int main() {
    std::cout << "________________ Merge Sort ________________" << endl;
    std::forward_list merge_forward_list{3, 7, 1, 5, 2, 9};
    std::list merge_bidirectional_list{3, 7, 1, 5, 2, 9};
    std::vector merge_vec{3, 7, 1, 5, 2, 9};

    wheel::merge_sort(merge_forward_list.begin(), merge_forward_list.end());
    std::cout << "After sorting forward list:               ";
    wheel::print_range(merge_forward_list.begin(), merge_forward_list.end());

    wheel::merge_sort(merge_bidirectional_list.begin(), merge_bidirectional_list.end());
    std::cout << "After sorting bidirectional list:         ";
    wheel::print_range(merge_bidirectional_list.begin(), merge_bidirectional_list.end());

    wheel::merge_sort(merge_vec.begin(), merge_vec.end());
    std::cout << "After sorting vector:                     ";
    wheel::print_range(merge_vec.begin(), merge_vec.end());

    std::cout << "\n\n";



    std::cout << "________________ Selection Sort ________________" << endl;
    std::vector selection_vec = wheel::getRandomArray(INT32_MIN, INT32_MAX, 100);

    wheel::selection_sort(selection_vec.begin(), selection_vec.end());
    std::cout << "After sorting vector:                     ";
    wheel::print_range(selection_vec.begin(), selection_vec.end());

    std::cout << "\n\n";



    std::cout << "________________ Bucket Sort ________________" << endl;
    std::vector bucket_vec = wheel::getRandomArray(0, 1000, 100);

    wheel::bucket_sort(bucket_vec.begin(), bucket_vec.end(), 100);
    std::cout << "After sorting vector:                     ";
    wheel::print_range(bucket_vec.begin(), bucket_vec.end());

    std::cout << "\n\n";

    return 0;
}
