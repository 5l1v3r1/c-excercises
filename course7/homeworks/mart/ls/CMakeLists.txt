cmake_minimum_required(VERSION 3.0)

find_package(Boost REQUIRED COMPONENTS filesystem program_options)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_executable(ls ls.cc)
target_link_libraries(ls Boost::filesystem Boost::program_options)
