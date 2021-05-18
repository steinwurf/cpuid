cmake_minimum_required(VERSION 3.12)
project(cpuid)

# Use waf to resolve dependencies
if(NOT DEFINED STEINWURF_RESOLVE)
  message(STATUS "Resolving dependencies...")
  execute_process(COMMAND python waf resolve ${STEINWURF_RESOLVE_OPTIONS}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  set(STEINWURF_RESOLVE "${CMAKE_CURRENT_SOURCE_DIR}/resolve_symlinks")
  set(STEINWURF_TOP_NAME cpuid)
endif()

# platform dependency
if(NOT TARGET steinwurf::platform)
  add_subdirectory("${STEINWURF_RESOLVE}/platform" platform EXCLUDE_FROM_ALL)
endif()

# Define library
file(GLOB_RECURSE cpuid_sources ./src/*.cpp)

# Is this the top-level steinwurf project?
if(${PROJECT_NAME} STREQUAL ${STEINWURF_TOP_NAME})
  # Create static library
  add_library(cpuid STATIC ${cpuid_sources})
  # Install library
  install(FILES $<TARGET_FILE:cpuid> DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
else()
  # Create object library
  add_library(cpuid OBJECT ${cpuid_sources})
  # Add this library to a global list of steinwurf object libraries
  set_property(GLOBAL APPEND PROPERTY steinwurf::object_libraries
                                      steinwurf::cpuid)
endif()

# Link header only dependencies
target_link_libraries(cpuid PRIVATE steinwurf::platform)

target_include_directories(cpuid INTERFACE src)
target_compile_features(cpuid PUBLIC cxx_std_14)
add_library(steinwurf::cpuid ALIAS cpuid)

# Install headers excluding "detail" as these are internal to the library.
install(
  DIRECTORY ./src/cpuid
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING
  PATTERN *.hpp
  PATTERN ./src/cpuid/detail EXCLUDE)

# Is top level project?
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  # Build executables
  add_executable(print_cpuinfo examples/print_cpuinfo/main.cpp)
  target_link_libraries(print_cpuinfo cpuid)
endif()
