cmake_minimum_required(VERSION 3.10.0)
project(linkedlist VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/extern/cmake-modules")

# *** VARIABLES ***

# targets
set(APP_TARGET linkedlist)
set(TEST_TARGET unit-tests)

# includes
set(APP_INCLUDES ${PROJECT_SOURCE_DIR}/inc)


# sources
file(GLOB_RECURSE APP_SRCS src/*.cpp)

# build options
option(BUILD_TEST "Build the tests." OFF)



# *** BUILD & LINK ***
if(${BUILD_TEST})
    enable_testing()
    add_subdirectory(tests)
else()
    add_executable(${APP_TARGET} ${APP_SRCS})
    target_include_directories(${APP_TARGET} PRIVATE ${APP_INCLUDES})
endif()
