project(HelloSLAM)

set(CMAKE_BUILD_TYPE "Debug")

# add_executable(helloSLAM helloSLAM.cpp)

# compile this file to a library (without SHARED it compiles a static .a library)
add_library(hello_calc_shared SHARED libHelloCalc.cpp)

add_executable(useCalc helloSLAM.cpp)
target_link_libraries(useCalc hello_calc_shared)