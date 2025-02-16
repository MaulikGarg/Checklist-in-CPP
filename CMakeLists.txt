# minimum cmake version required
cmake_minimum_required(VERSION 3.10)

# project name
project(ListManager VERSION 1.0 LANGUAGES CXX)

# set c++ standard and make it mandatory
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Look for Catch2 on the system
find_package(Catch2 QUIET)
if(Catch2_FOUND)
    message(STATUS "Catch2 found, enabling and running tests...")

    # set sources for all the tests
    set(TESTS
        tests/getInputTest.cpp
    )

    # add catch 2 executable and link libs
    add_executable(tests ${TESTS})
    target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
else()
    message(WARNING "Catch2 not found, skipping tests.")
endif()

# set sources for all our code files
set(SOURCES
    src/bossList.cpp
    src/getInput.cpp
    src/main.cpp
    src/list.cpp
    src/fileIO.cpp
)

# set header location
set(HEADERS
    src/bossList.h
    src/getInput.h
    src/list.h
    src/fileIO.h
    lib/json.hpp
)

#create main executable
add_executable("${PROJECT_NAME}" ${SOURCES})

# Include directories
target_include_directories("${PROJECT_NAME}" PRIVATE src lib)
