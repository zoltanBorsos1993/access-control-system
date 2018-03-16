cmake_minimum_required (VERSION 3.0)

project (mod_driver)

FILE(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(mod_driver ${SRC_FILES})

set_target_properties(
	mod_driver
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY bin/
	OUTPUT_NAME mod_driver.run
	)
