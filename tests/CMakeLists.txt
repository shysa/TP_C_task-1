project(tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(..)

add_executable(Google_Tests_run test.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main lib)

add_test(NAME Google_Tests_run COMMAND Google_Tests_run)