cmake_minimum_required (VERSION 3.12)
project(cpuid)

message("Resolving dependencies... cpuid")
message("$CMAKE_SOURCE_DIR")
message("$CMAKE_CURRENT_SOURCE_DIR")
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    execute_process(
        COMMAND python waf resolve
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

file( GLOB_RECURSE cpuid_sources ./src/*.cpp)
add_library(cpuid STATIC ${cpuid_sources})

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/resolve_symlinks/platform")

target_link_libraries(cpuid platform)

target_compile_features(cpuid PUBLIC cxx_std_11)

target_include_directories(cpuid INTERFACE src)
