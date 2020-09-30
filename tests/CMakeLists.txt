# see https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html 

set(CMAKE_CXX_STANDARD 11)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)

macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_include_directories(${TESTNAME} PRIVATE ${APP_INCLUDES})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main ${LIB_TARGETS})
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER test)
endmacro()

file(GLOB_RECURSE TEST_SRCS *.cpp)

list(REMOVE_ITEM APP_SRCS "${PROJECT_SOURCE_DIR}/src/main.cpp") # remove app main from sources

package_add_test(${TEST_TARGET} ${TEST_SRCS} ${APP_SRCS})




