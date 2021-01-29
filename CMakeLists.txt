cmake_minimum_required (VERSION 3.10)
project(cpuid)

if(NOT DEFINED STEINWURF_RESOLVE)
    message(STATUS "Resolving dependencies...")
    execute_process(
        COMMAND python waf resolve
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    set(STEINWURF_RESOLVE "${CMAKE_CURRENT_SOURCE_DIR}/resolve_symlinks")
    set(CPUID_TOPLEVEL 1)
endif()

file(GLOB cpuid_headers ./src/cpuid/*.hpp)
file(GLOB_RECURSE cpuid_sources ./src/*.cpp)

add_library(cpuid_objects OBJECT ${cpuid_sources})

if (NOT TARGET platform)
add_subdirectory("${STEINWURF_RESOLVE}/platform" platform EXCLUDE_FROM_ALL)
endif()

target_link_libraries(cpuid_objects PRIVATE steinwurf::platform)

target_compile_features(cpuid_objects PUBLIC cxx_std_11)

target_include_directories(cpuid_objects INTERFACE src)

install(FILES ${cpuid_headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/cpuid)


if (DEFINED CPUID_TOPLEVEL)
add_library(cpuid STATIC $<TARGET_OBJECTS:cpuid_objects>)
install(FILES $<TARGET_FILE:cpuid> DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
add_library(steinwurf::cpuid ALIAS cpuid)
else()
add_library(steinwurf::cpuid ALIAS cpuid_objects)
endif()

