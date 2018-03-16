cmake_minimum_required (VERSION 3.0)

project (mod_comm)

FILE(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(mod_comm ${SRC_FILES})

set_target_properties(
	mod_comm
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY bin/
	OUTPUT_NAME mod_comm.run
	)
