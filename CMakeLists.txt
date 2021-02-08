cmake_minimum_required(VERSION 3.0.0)

project(im_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_BUILD_TYPE Debug)

set(SRC_)

add_executable(main main.cc ${SRC_})
target_link_libraries(main -lpthread)
