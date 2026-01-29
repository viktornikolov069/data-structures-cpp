cmake_minimum_required(VERSION 3.20)

project(dscpp LANGUAGES CXX)

# Header-only library
add_library(dscpp INTERFACE)
add_library(dscpp::dscpp ALIAS dscpp)

# Require C++23
target_compile_features(dscpp INTERFACE cxx_std_23)

# Public include directory
target_include_directories(dscpp
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
