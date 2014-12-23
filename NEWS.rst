News for cpuid
==============

This file lists the major changes between versions. For a more detailed list of
every change, see the Git log.

Latest
------
* Minor: Update to waf 1.8.0-pre1
* Minor: Made python files comply with pep8
* Minor: Added version define.

3.1.0
-----
* Minor: Added detection for AVX2 instruction set
* Bug: Fixed issue with the -fPIC compiler flag on x86.

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
