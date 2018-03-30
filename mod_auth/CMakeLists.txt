cmake_minimum_required (VERSION 3.0)

SET(MODULE_NAME "auth")

PROJECT(mod_${MODULE_NAME})

INCLUDE_DIRECTORIES("/root/deps/usr/include" "/root/deps/usr/local/include")
LINK_DIRECTORIES("/root/deps/usr/lib" "/root/deps/usr/local/lib")

# Linking
## Expects libraries to be built according to the target architecture and are on the linking path.
SET(LIBRARIES_LIST
			"zmq"
			"czmq"
	 )

# Create binary
## Finding application .cpp sources
FILE(GLOB_RECURSE SRC_FILES src/*.cpp)

ADD_EXECUTABLE(mod_${MODULE_NAME} ${SRC_FILES})
SET_TARGET_PROPERTIES(
	mod_${MODULE_NAME}
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY bin/
	OUTPUT_NAME mod_${MODULE_NAME}.run
	)

TARGET_LINK_LIBRARIES(mod_${MODULE_NAME} ${LIBRARIES_LIST})
