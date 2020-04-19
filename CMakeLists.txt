cmake_minimum_required (VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -march=native")


project(EQUIV_CHECK)
add_library(Lib src/lib.cxx)
target_include_directories(Lib PUBLIC include)

enable_testing()
add_subdirectory("test")