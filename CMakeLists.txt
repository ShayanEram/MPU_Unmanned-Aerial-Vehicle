cmake_minimum_required(VERSION 3.10)
project(UAV)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/Inc
    ${CMAKE_SOURCE_DIR}/Inc/Utils
)

# Source files
file(GLOB SRC_FILES
    ${CMAKE_SOURCE_DIR}/Src/*.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})


# Unit tests ##########################################
option(BUILD_TESTS "Enable building unit tests" OFF)

if(BUILD_TESTS)
    # Add GoogleTest
    add_subdirectory(../googletest googletest-build)
    file(GLOB TEST_SOURCES "Tests/*.cpp")

    add_executable(UAV_tests ${TEST_SOURCES})
    target_include_directories(UAV_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)
    target_link_libraries(UAV_tests gtest gtest_main pthread)

    enable_testing()
    add_test(NAME UAV_tests COMMAND UAV_tests)
endif()