
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_json test_json.cc)
target_link_libraries(test_json PRIVATE 
	${GTEST_LIBRARIES}
	nlohmann_json::nlohmann_json
	pthread
)

add_custom_command(TARGET test_json 
	POST_BUILD 
	COMMAND ./test_json
)
