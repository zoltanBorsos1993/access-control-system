# Define our host system
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
SET(TOOLCHAINS_PATH $ENV{TOOLCHAINS_PATH})

# Define the cross compiler locations
SET(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

# Use our definitions for compiler tools
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

ADD_DEFINITIONS("-Wall")
ADD_COMPILE_OPTIONS("-std=c++11")
