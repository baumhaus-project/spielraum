cmake_minimum_required(VERSION 3.17)

project(spielraum)

include(cmake/pkg.cmake)
include(cmake/buildcache.cmake)

option(LINT "Run clang-tidy with the compiler." OFF)
if (LINT)
    include(cmake/clang-tidy.cmake)
endif ()

file(GLOB cl-files cl/test/main.cc)
add_executable(test-cl ${cl-files})
