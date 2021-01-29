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