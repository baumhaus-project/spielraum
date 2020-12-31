cmake_minimum_required(VERSION 3.17)

project(spielraum)

include(cmake/pkg.cmake)
include(cmake/buildcache.cmake)

option(LINT "Run clang-tidy with the compiler." OFF)
if (LINT)
    include(cmake/clang-tidy.cmake)
endif ()

express2cpp(deps/express2cpp/test/ifc23.txt ifc2x3)
file(GLOB cl-files cl/test/main.cc)
add_executable(test-cl ${cl-files})
target_link_libraries(test-cl ifc2x3)
