cmake_minimum_required(VERSION 3.20)

project(NanoTekSpice
    VERSION 1.0
    DESCRIPTION "NanoTekSpice"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC ${CMAKE_SOURCE_DIR}/src)
file(GLOB_RECURSE SOURCES "${SRC}/*.cpp" "${SRC}/*.hpp")

add_executable(nanotekspice ${SOURCES})

target_include_directories(nanotekspice PRIVATE ${SRC})

target_compile_options(${PROJECT_NAME} PRIVATE -std=c++20 -Wall -Wextra -Werror)