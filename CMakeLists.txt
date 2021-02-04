cmake_minimum_required(VERSION 3.10)
project(cpuid)

# Use waf to resolve dependencies
if(NOT DEFINED STEINWURF_RESOLVE)
  message(STATUS "Resolving dependencies...")
  execute_process(COMMAND python waf resolve
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  set(STEINWURF_RESOLVE "${CMAKE_CURRENT_SOURCE_DIR}/resolve_symlinks")
endif()

# platform dependency
if(NOT TARGET steinwurf::platform)
  add_subdirectory("${STEINWURF_RESOLVE}/platform" platform EXCLUDE_FROM_ALL)
endif()

# Define library
file(GLOB_RECURSE cpuid_sources ./src/*.cpp)
add_library(cpuid_internal OBJECT ${cpuid_sources})
target_compile_features(cpuid_internal PUBLIC cxx_std_14)

# Link dependencies
target_link_libraries(cpuid_internal PRIVATE steinwurf::platform)

# Add interface library encapsulating the internal the library object
add_library(cpuid_objects INTERFACE)
target_sources(cpuid_objects INTERFACE $<TARGET_OBJECTS:cpuid_internal>)
target_link_libraries(cpuid_objects INTERFACE)
target_include_directories(cpuid_objects INTERFACE src)
target_compile_features(cpuid_objects INTERFACE cxx_std_14)

# Install headers excluding "detail" as these are internal to the library.
install(
  DIRECTORY ./src/cpuid
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING
  PATTERN *.hpp
  PATTERN ./src/cpuid/detail EXCLUDE)

# Is top level project?
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  add_library(cpuid_static STATIC)
  target_link_libraries(cpuid_static PUBLIC cpuid_objects)
  set_target_properties(cpuid_static PROPERTIES OUTPUT_NAME cpuid)

  install(FILES $<TARGET_FILE:cpuid_static>
          DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

  # Build executables
  add_executable(print_cpuinfo examples/print_cpuinfo/main.cpp)
  target_link_libraries(print_cpuinfo cpuid_static)
else()
  add_library(steinwurf::cpuid ALIAS cpuid_objects)
endif()
