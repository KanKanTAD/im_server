find_package(GTest REQUIRED)

################################################
add_executable(test_none test_none.cc)
target_link_libraries(test_none PRIVATE 
	${GTEST_BOTH_LIBRARIES}
	pthread
)
add_custom_command( 
	TARGET test_none 
	POST_BUILD
	COMMAND ./test_none
)
##############################################
add_executable(test_json test_json.cc)
target_link_libraries(test_json 
	${GTEST_BOTH_LIBRARIES}
	pthread
	nlohmann_json::nlohmann_json
)
add_custom_command( 
	TARGET test_json
	POST_BUILD
	COMMAND ./test_json
)
#############################################
add_executable(test_spdlog test_spdlog.cc)
target_link_libraries(test_spdlog  PRIVATE
	${GTEST_BOTH_LIBRARIES}
	pthread
	spdlog
)
add_custom_command( 
	TARGET test_spdlog
	POST_BUILD
	COMMAND ./test_spdlog
)
#############################################
message(STATUS "the utils.cc:" ${ROOT_}/master/Utils.cc)
add_executable(test_utils test_utils.cc 
	${ROOT_}/master/Utils.cc
)
target_link_libraries(test_utils  PRIVATE
	${GTEST_BOTH_LIBRARIES}
	pthread
	spdlog
)
add_custom_command( 
	TARGET test_utils
	POST_BUILD
	COMMAND ./test_utils
)
#############################################
add_executable(test_configure test_configure.cc 
	${SRC_}
)
target_link_libraries(test_configure  PRIVATE
	${GTEST_BOTH_LIBRARIES}
	pthread
)
add_custom_command( 
	TARGET test_configure
	POST_BUILD
	COMMAND ./test_configure
)
#############################################
