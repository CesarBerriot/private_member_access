cmake_minimum_required(VERSION 3.31)
project(private_member_access)

set(required_cxx_standard 17)

if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD ${required_cxx_standard})
else()
  if(CMAKE_CXX_STANDARD LESS required_cxx_standard)
    message(FATAL_ERROR "private_member_access depends on C++ 17 features.")
  endif()
endif()

include(FetchContent)
FetchContent_Declare(setup_gtest GIT_REPOSITORY https://github.com/CesarBerriot/setup_gtest.git GIT_TAG 1.2.0)
FetchContent_MakeAvailable(setup_gtest)
include(${setup_gtest_SOURCE_DIR}/setup_gtest.cmake)

add_library(private_member_access INTERFACE)
target_include_directories(private_member_access INTERFACE include)

if(${BUILD_TESTING})
  setup_gtest(private_member_access)
endif()