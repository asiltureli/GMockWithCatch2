cmake_minimum_required(VERSION 3.20)
set(ProjectID "GMockCatch2Danger")
project(${ProjectID} VERSION 1.0.0 LANGUAGES CXX)

set(CATCH2_VERSION v3.7.1)
set(GTEST_VERSION v1.15.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(FetchContent)
include(AddGTest)
include(AddCatch2)
include(CTest)

enable_testing()

add_executable(TestGMockCatch2WithMain TestGMockCatch2WithMain.cpp)

add_executable(TestGMockCatch2 TestGMockCatch2.cpp)

target_link_libraries(TestGMockCatch2WithMain PRIVATE 
                Catch2::Catch2WithMain
                gmock)

target_link_libraries(TestGMockCatch2 PRIVATE
                Catch2::Catch2
                gmock)

add_test(NAME TestGMockCatch2WithMain COMMAND TestGMockCatch2WithMain)
add_test(NAME TestGMockCatch2 COMMAND TestGMockCatch2)
