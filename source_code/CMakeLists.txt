cmake_minimum_required(VERSION 3.16)
project(ABCproject2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_RELEASE "-g -std=c++17 -O2")

set(CMAKE_CXX_FLAGS_ASAN "-g -std=c++17 -Wall -Werror -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(ABCproject2 main.cpp RoadTransport.h RoadTransport.cpp Truck.h Truck.cpp Random.h Random.cpp TableOutput.h TableOutput.cpp Container.h Container.cpp Bus.h Bus.cpp Car.h Car.cpp)
