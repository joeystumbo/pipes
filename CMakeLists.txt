cmake_minimum_required(VERSION 3.10)
project(_cpp_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Add executable
add_executable(_cpp_test main.cpp)

# Find Threads (required by httplib)
find_package(Threads REQUIRED)
target_link_libraries(_cpp_test PRIVATE Threads::Threads)

# Tests
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE GTest::gtest_main Threads::Threads)
add_test(NAME unit_tests COMMAND unit_tests)
