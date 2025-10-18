cmake_minimum_required(VERSION 3.10)
project(UAV)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCE_FILES "Src/*.cpp")
file(GLOB HEADER_FILES "Inc/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

option(BUILD_TESTS "Build unit tests" OFF)
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