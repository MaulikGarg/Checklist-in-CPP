# minimum cmake version required
cmake_minimum_required(VERSION 3.10)

# project name
project(ListManager VERSION 1.0 LANGUAGES CXX)

# set c++ standard and make it mandatory
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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

#create executable
add_executable("${PROJECT_NAME}" ${SOURCES} ${HEADERS} )
