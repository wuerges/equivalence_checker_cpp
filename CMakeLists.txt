cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -march=native")


project(EQUIV_CHECK)
# add_subdirectory("ext-libs/rapidcheck")
add_subdirectory("src")

enable_testing()
add_subdirectory("test")