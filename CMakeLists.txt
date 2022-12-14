# required
cmake_minimum_required(VERSION 3.10)

# set some flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Debug")

# set the project name and version
project(TouhouNS VERSION 0.1)

# add a configuration header
configure_file(TouhouNSConfig.h.in TouhouNSConfig.h)

# add the NSEngine lib directory
# TODO find a way to not need a link
add_subdirectory(NSEngineGit)

# get source files
file(GLOB_RECURSE SRCS src/*.cpp src/*.c)
file(GLOB_RECURSE INCLUDES src/*.hpp src/*.h)

# add the executable
add_executable(TouhouNS ${SRCS} ${INCLUDES})

# add the build directory as an include directory (for the config header)
target_include_directories(TouhouNS PUBLIC
                            "${PROJECT_BINARY_DIR}"
                          )

# link the NSEngine library. All the dependencies are added directly to the engine
target_link_libraries(TouhouNS PUBLIC NSEngine)

# TODO do this better (copy assets in build directory)
file(COPY assets DESTINATION ${PROJECT_BINARY_DIR})
