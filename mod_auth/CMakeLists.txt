cmake_minimum_required (VERSION 3.0)

PROJECT(mod_auth)

# Includes and libs path
SET(ZMQ_INCLUDE_PATH "/usr/local/include")
SET(ZMQ_LIBRARY_PATH "/usr/local/lib")

# Setting includes
INCLUDE_DIRECTORIES(SYSTEM ${ZMQ_INCLUDE_PATH})

# Finding application .cpp sources
FILE(GLOB_RECURSE SRC_FILES src/*.cpp)

# Create target
ADD_EXECUTABLE(mod_auth ${SRC_FILES})
SET_TARGET_PROPERTIES(
	mod_auth
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY bin/
	OUTPUT_NAME mod_auth.run
	)

TARGET_INCLUDE_DIRECTORIES(mod_auth INTERFACE ${ZMQ_INCLUDE_PATH})

# Linking
ADD_LIBRARY(zmq STATIC IMPORTED "${ZMQ_LIBRARY_PATH}/libzmq.a")
ADD_LIBRARY(czmq STATIC IMPORTED "${ZMQ_LIBRARY_PATH}/libczmq.a")
