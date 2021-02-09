cmake_minimum_required(VERSION 3.10)

project(im_server)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_BUILD_TYPE Debug)

include_directories(./master)

find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)
set(cryptopplib -lcryptopp)
set(fmtlib -lfmt)

add_subdirectory(./master)

add_executable(main main.cc)

target_link_libraries(main PRIVATE
	master
	spdlog::spdlog_header_only
	nlohmann_json::nlohmann_json
	${cryptopplib}
	${fmtlib}
	pthread
)

add_subdirectory(./test)
