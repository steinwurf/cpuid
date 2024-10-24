News for cpuid
==============

This file lists the major changes between versions. For a more detailed list of
every change, see the Git log.

Latest
------
* tbd

9.0.1
-----
* Patch: Made Neon detection work on MacOS.

9.0.0
-----
* Major: Use waf-tools 5.
* Minor: Added different AVX-512 extensions.
* Minor: Updated waf.

8.0.0
-----
* Major: Change cmake object library approach.

7.0.0
-----
* Major: Change cmake build to be object library based.

6.5.0
-----
* Minor: Added install step to CMake.

6.4.0
-----
* Minor: Added detection for F16C instruction

6.3.1
-----
* Patch: Added add_subdirectory guard to CMakeLists.txt.

6.3.0
-----
* Minor: Changed resolve step in CMake file.
* Minor: Lowered required cmake version.
* Minor: Upgrade to boost 4

6.2.1
-----
* Patch: Use variable for resolve step in cmake.

6.2.0
-----
* Minor: Improve cmake build file.

6.1.0
-----
* Minor: Added cmake build file.
* Patch: Move options.log to build folder
* Patch: Fix generator to build .o files when dependency and static lib when
  top-level.

6.0.0
-----
* Major: Moved internal files to the ``details`` folder.
* Major: Added inline namespace for versioning.
* Major: Added prepare_release function to wscript.
* Major: Expose objects rather than static lib when used as a dependency.

5.0.2
-----
* Patch: Fix the detection of the AVX2 instruction set on older CPUs. If the
  CPU does not support the eax=7 input value for the cpuid instruction, then
  the corresponding query is skipped.

5.0.1
-----
* Patch: Fix the detection of the NEON instruction set on 64-bit ARM CPUs,
  where Advanced SIMD (NEON) is always available.

5.0.0
-----
* Major: Upgrade to waf-tools 4
* Major: Upgrade to platform 3
* Minor: Upgrade to boost 3
* Minor: Upgrade to gtest 4
* Minor: Added buildbot.py for coverage reports.

4.0.0
-----
* Major: Upgrade to waf-tools 3
* Major: Upgrade to platform 2
* Minor: Upgrade to boost 2
* Minor: Upgrade to gtest 3

3.3.1
-----
* Patch: Added missing ``cstdint`` includes

3.3.0
-----
* Minor: Added init_msvc_arm.hpp to enable the NEON instruction set on
  Windows Phone 8 (and above).

3.2.1
-----
* Patch: Fix version define.

3.2.0
-----
* Patch: On win32 use __cpuidex when detecting extended features (such as
  AVX2). This bug was reported by Ilya Lavrenov <ilya.lavrenov@itseez.com>.
* Minor: Update to waf 1.8.0-pre1
* Minor: Made python files comply with pep8
* Minor: Added version define.

3.1.0
-----
* Minor: Added detection for AVX2 instruction set
* Patch: Fixed issue with the -fPIC compiler flag on x86.

3.0.0
-----
* Major: Platform detection is now handled by the 'platform' library

2.0.0
-----
* Major: Renamed Clang detection macros to always use the name CLANG instead of
  LLVM.

1.0.0
-----
* Major: Initial release with support for x86 and ARM architectures.
