cmake_minimum_required(VERSION 3.20)
project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)
add_executable(snake main.cpp)
set(SFML_DIR "D:\\CLion_2021.2.1\\MyProjects\\lib\\sfml\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(snake sfml-graphics sfml-audio)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)
