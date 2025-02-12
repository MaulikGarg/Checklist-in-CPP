cmake_minimum_required(VERSION 3.10)
project(ListManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/bossList.cpp
    src/getInput.cpp
    src/main.cpp
    src/list.cpp
)

set(HEADERS
    src/bossList.h
    src/getInput.h
    src/list.h
)

add_executable(list ${SOURCES} ${HEADERS})
