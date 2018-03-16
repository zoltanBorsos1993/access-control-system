cmake_minimum_required (VERSION 3.0)

project (mod_database)

FILE(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(mod_database ${SRC_FILES})

set_target_properties(
	mod_database
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY bin/
	OUTPUT_NAME mod_database.run
	)
