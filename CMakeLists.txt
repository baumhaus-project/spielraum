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

#svg-viewport
file(GLOB svg-viewport-ui-files ui/svg-viewport/src/*.cc)

if (MSVC)
    add_executable(svg-viewport WIN32 ${svg-viewport-ui-files})
else ()
    add_executable(svg-viewport ${svg-viewport-ui-files})
endif ()
target_include_directories(svg-viewport PRIVATE ui/svg-viewport/include)
target_compile_features(svg-viewport PUBLIC cxx_std_17)
target_link_libraries(svg-viewport wx::core wx::base)