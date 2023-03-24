cmake_minimum_required(VERSION 3.10)

project(wheel VERSION 1.2.4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(wheel INTERFACE)
target_include_directories(wheel INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/wheel
)


# Install the library
install(DIRECTORY wheel/ DESTINATION include/wheel)