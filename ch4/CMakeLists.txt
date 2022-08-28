cmake_minimum_required(VERSION 3.0)
project(useSophus)

find_package(Sophus REQUIRED)

find_package(fmt REQUIRED)
set(FMT_LIBRARIES fmt::fmt)

# Eigen
include_directories("/usr/include/eigen3")
add_executable(useSophus useSophus.cpp)
target_link_libraries(useSophus Sophus::Sophus ${FMT_LIBRARIES}  fmt)

add_subdirectory(example)
