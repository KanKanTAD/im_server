add_library(master STATIC ${SRC_} ${INC_})
target_link_libraries(master PUBLIC 
	pthread
	fmt::fmt-header-only
	nlohmann_json::nlohmann_json
	spdlog
)
