cmake_minimum_required(VERSION 3.17)

project(spielraum)

include(cmake/pkg.cmake)
include(cmake/buildcache.cmake)

message(STATUS "Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

option(LINT "Run clang-tidy with the compiler." OFF)
if (LINT)
    include(cmake/clang-tidy.cmake)
endif ()

express2cpp(deps/express2cpp/express/test/ifc23.txt ifc2x3)

file(GLOB geom-lib-files lib/geom_reader/src/*.cc)
add_library(geom-lib ${geom-lib-files})
target_include_directories(geom-lib PUBLIC lib/geom_reader/include)
target_link_libraries(geom-lib cista utl ifc2x3)
target_compile_features(geom-lib PUBLIC cxx_std_17)

file(GLOB ifc_utl-files lib/ifc_utl/src/*.cc)
add_library(ifc_utl ${ifc_utl-files})
target_include_directories(ifc_utl PUBLIC lib/ifc_utl/include)
target_link_libraries(ifc_utl cista utl ifc2x3)
target_compile_features(ifc_utl PUBLIC cxx_std_17)

file(GLOB_RECURSE test-files test/*.cc)
add_executable(spielraum-test ${test-files})
target_link_libraries(spielraum-test ifc_utl geom-lib doctest)

file(GLOB cl-files cl/test/main.cc)
add_executable(test-cl ${cl-files})
target_link_libraries(test-cl ifc_utl geom-lib)


# GUI
file(GLOB spielraum-ui-files ui/spielraum/src/*.cc)

if (MSVC)
    add_executable(spielraum WIN32 ${spielraum-ui-files} ui/dpi.manifest)
else ()
    add_executable(spielraum ${spielraum-ui-files})
endif ()

target_include_directories(spielraum PRIVATE ui/spielraum/include)
target_compile_features(spielraum PRIVATE cxx_std_17)
target_link_libraries(spielraum wx::core wx::base wx::webview pugixml)