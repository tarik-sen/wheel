# Wheel
Wheel is a header-only C++ library that contains generic algorithms as well as implementation of 13 different sorting algorithms.
Most of the sort algorithms implemented in such a way that it can be used to sort any container which implements any Iterator type (forward, bidirectional or random access) and their corresponding begin() and end() methods.

## Sample Benchmark
<img src=docs/benchmark_result.png width=500px>

## How to use it?
Just include the sort algorithm(s) and compile with -std=c++20 option, no linkage with the library, since it contains only headers with templates!
```bash
#include <iostream>
#include <list>
#include <wheel/sort/sort.hpp>


int main() {
    std::list l{3, 7, 1, 5, 2, 9};

    wheel::merge_sort(l.begin(), l.end());

    for (auto i: l)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```
> All sort algorithms can be included with wheel/sort/sort.hpp
  Sort algorithms also can be included individually like wheel/sort/selection_sort.hpp

## Installation
### Requirements:
  - Compiler that supports C++20
  - CMake
  - Google Test (OPTIONAL)
  - Google Benchmark (OPTIONAL)
  

> ⚠️ Above requirements can be installed with numerous ways.
This is just one way to install them on debian and ubuntu based distributions.
For more about installation of these requirements please refer their own documentations.

```bash
sudo apt install gcc cmake libbenchmark-dev libgtest-dev
```

### Installing the library
```bash
git clone 'https://github.com/tarik-sen/wheel.git' && cd wheel
mkdir build && cd build
cmake ..
sudo make install
```

### Testing the library
> ⚠️ Tests are written with 'Google Test' so installation of the optional requirement is a must.
```bash
cd google_test
mkdir build && cd build
cmake ..
cmake --build .
./GoogleTest
```
Tests can be run individually like this
```bash
g++ quick_sort_test.cpp -std=c++20 -lgtest -lgtest_main -pthread -o quick_sort_test
```

### Benchmarking the library
> ⚠️ Benchmarks are written with 'Google Benchmark' so installation of the optional requirement is a must.
```bash
cd google_benchmark
g++ generic_benchmark.cpp -std=c++20 -lbenchmark -lpthread -o sort_benchmark
./sort_benchmark
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

