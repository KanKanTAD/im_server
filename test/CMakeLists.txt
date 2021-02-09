
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_json test_json.cc)
target_link_libraries(test_json PUBLIC
	master
	gtest
	spdlog::spdlog_header_only
	nlohmann_json::nlohmann_json
	${cryptopplib}
	pthread
)

add_custom_command(TARGET test_json 
	POST_BUILD 
	COMMAND ./test_json
)
