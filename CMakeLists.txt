cmake_minimum_required (VERSION 3.12)
project(cpuid)

if(NOT DEFINED STEINWURF_RESOLVE)
    set(STEINWURF_RESOLVE TRUE)
    message(STATUS "Resolving dependencies...")
    execute_process(
        COMMAND python waf resolve
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

file(GLOB_RECURSE cpuid_sources ./src/*.cpp)
add_library(cpuid STATIC ${cpuid_sources})
add_library(steinwurf::cpuid ALIAS cpuid)

add_subdirectory("${CMAKE_SOURCE_DIR}/resolve_symlinks/platform" platform)

target_link_libraries(cpuid PRIVATE steinwurf::platform)

target_compile_features(cpuid PUBLIC cxx_std_11)

target_include_directories(cpuid INTERFACE src)
