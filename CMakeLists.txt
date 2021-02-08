cmake_minimum_required(VERSION 3.10)

project(im_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_BUILD_TYPE Debug)

include_directories(./master)

find_package(spdlog REQUIRED)
set(cryptopplib -lcryptopp)

set(SRC_ ./master/ClientCache.cc)

add_executable(main main.cc ${SRC_})

target_link_libraries(main PRIVATE
	spdlog::spdlog_header_only
	${cryptopplib}
	-lpthread
)
