# minimum cmake version required
cmake_minimum_required(VERSION 3.10)

# project name
project(ListManager VERSION 1.0 LANGUAGES CXX)

# set c++ standard and make it mandatory
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Force static linking
set(CMAKE_EXE_LINKER_FLAGS "-static")

# set sources for all our code files
set(LIB_SOURCES
    src/bossList.cpp
    src/getInput.cpp     
    src/list.cpp
    src/fileIO.cpp
)

# set header locations
set(LIB_HEADERS
    src/bossList.h
    src/getInput.h
    src/list.h
    src/fileIO.h
    lib/json.hpp
)

# Create a static library with your source files
add_library(ListManagerLib ${LIB_SOURCES})
target_include_directories(ListManagerLib PUBLIC src lib)

# Create main executable and link against the library
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ListManagerLib)

# Look for Catch2 on the system
find_package(Catch2 QUIET)
if(Catch2_FOUND)
    message(STATUS "Catch2 found, enabling and running tests...")

    # Set sources for all the tests
    set(TESTS
        tests/getInputTest.cpp
    )

    # Add the test executable and link it with Catch2 and your library
    add_executable(tests ${TESTS})
    target_link_libraries(tests PUBLIC Catch2::Catch2WithMain ListManagerLib)

    include(CTest)
    include(Catch)
    catch_discover_tests(tests)
else()
    message(WARNING "Catch2 not found, skipping tests.")
endif()
