
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_json test_json.cc)
target_link_libraries(test_json ${GTEST_LIBRARIES} pthread)
add_custom_command(TARGET runTests
	POST_BUILD
	COMMAND ./test_json
)
