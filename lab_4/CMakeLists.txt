cmake_minimum_required(VERSION 3.14)

project(lab4 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-g)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "tests/*.cpp")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_l4 ${TESTS} ${SOURCES})

add_compile_options(-fconcepts)

target_link_libraries(
  test_l4
  GTest::gtest_main
)

include(GoogleTest)
add_test(NAME BASIC COMMAND tests)
