cmake_minimum_required (VERSION 3.0)

project (mod_auth)

FILE(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(mod_auth ${SRC_FILES})

set_target_properties(
	mod_auth
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY bin/
	OUTPUT_NAME mod_auth.run
	)
