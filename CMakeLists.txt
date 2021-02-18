cmake_minimum_required( VERSION 3.5 )

project( CodingTest )

set(CMake_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable( m1 1/13.cpp )

add_executable( m2 2/14.cpp )

add_executable( m3 3/5.cpp )

add_executable( m4 4/7.cpp )

add_executable( m5 5/66.cpp )

add_executable( m6 6/154.cpp )

add_executable( m7 7/620.cpp )

add_executable( m8 8/611.cpp )


add_executable( t1 std.cpp )
add_executable( t2 test2.cpp )


# https://www.lintcode.com/problem/