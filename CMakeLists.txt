cmake_minimum_required(VERSION 3.20)

project(nanotekspice
    VERSION 1.0
    DESCRIPTION "NanoTekSpice"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${SRC_DIR}/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)