//
// Created by Tarik SEN on 16.03.2023.
// Implementation of general purposed utility functions.
//

#ifndef WHEEL_UTIL_HPP
#define WHEEL_UTIL_HPP


#include <vector>
#include <cstdint>
#include <iostream>
#include <functional>
#include <iterator>
#include <random>


namespace wheel {
    template <typename Arithmetic> requires std::integral<Arithmetic> || std::floating_point<Arithmetic>
    std::vector<Arithmetic> getRandomArray(Arithmetic start, Arithmetic end, int n) {
        std::random_device dvc;
        std::mt19937 mersenne_engine {dvc()};
        std::vector<Arithmetic> res(n);

        if constexpr (std::integral<Arithmetic>) {
            std::uniform_int_distribution dist{start, end};
            auto generator = [&dist, &mersenne_engine]() { return dist(mersenne_engine); };
            generate(res.begin(), res.end(), generator);
        }
        else {
            std::uniform_real_distribution dist{start, end};
            auto generator = [&dist, &mersenne_engine]() { return dist(mersenne_engine); };
            generate(res.begin(), res.end(), generator);
        }

        return res;
    }

    template <std::forward_iterator Iterator, typename Arithmetic, typename Operator=std::plus<Arithmetic>> requires
            (std::integral<Arithmetic> || std::floating_point<Arithmetic>) &&
            std::predicate<Operator, Arithmetic, Arithmetic>
    Arithmetic accumulate(Iterator start, Iterator end, Arithmetic s, Operator op=Operator{}) {
        while (start != end) {
            s = op(s, *start);
            start++;
        }

        return s;
    }

    template <std::bidirectional_iterator Iterator>
    inline Iterator prev(Iterator it) {
        return --it;
    }

    template <std::forward_iterator Iterator>
    inline Iterator next(Iterator it) {
        return ++it;
    }

    template <std::forward_iterator Iterator>
    void print_range(Iterator start, Iterator end) {
        for (std::forward_iterator auto it = start; it != end; ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}


#endif //WHEEL_UTIL_HPP
