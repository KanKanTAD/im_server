cmake_minimum_required(VERSION 3.10)

project(im_server)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_BUILD_TYPE Debug)

set(ROOT_ ${CMAKE_CURRENT_SOURCE_DIR})

set(INC_
	#${ROOT_}/master/ClientCache.h
	${ROOT_}/master/Utils.h
	${ROOT_}/master/Configure.h
)
set(SRC_ 
	#${ROOT_}/master/ClientCache.cc
	${ROOT_}/master/Utils.cc
	${ROOT_}/master/Configure.cc
)

message(STATUS "SRC_:" ${SRC_})

find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)

include_directories(master)

add_subdirectory(master)

add_subdirectory(test)

add_executable(server main.cc)
target_link_libraries(server PRIVATE master)
