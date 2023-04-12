
cpuid
*****

|Linux make-specs| |Windows make-specs| |MacOS make-specs| |Linux CMake| |Windows CMake| |MacOS CMake| |Raspberry Pi| |Valgrind| |No Assertions| |Clang Format| |Cppcheck|

.. |Linux make-specs| image:: https://github.com/steinwurf/cpuid/actions/workflows/linux_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/linux_mkspecs.yml
   
.. |Windows make-specs| image:: https://github.com/steinwurf/cpuid/actions/workflows/windows_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/windows_mkspecs.yml

.. |MacOS make-specs| image:: https://github.com/steinwurf/cpuid/actions/workflows/macos_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/macos_mkspecs.yml
   
.. |Linux CMake| image:: https://github.com/steinwurf/cpuid/actions/workflows/linux_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/linux_cmake.yml

.. |Windows CMake| image:: https://github.com/steinwurf/cpuid/actions/workflows/windows_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/windows_cmake.yml
   
.. |MacOS CMake| image:: https://github.com/steinwurf/cpuid/actions/workflows/macos_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/macos_cmake.yml
   
.. |Raspberry Pi| image:: https://github.com/steinwurf/cpuid/actions/workflows/raspberry_pi.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/raspberry_pi.yml

.. |Clang Format| image:: https://github.com/steinwurf/cpuid/actions/workflows/clang-format.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/clang-format.yml

.. |No Assertions| image:: https://github.com/steinwurf/cpuid/actions/workflows/nodebug.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/nodebug.yml

.. |Valgrind| image:: https://github.com/steinwurf/cpuid/actions/workflows/valgrind.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/valgrind.yml

.. |Cppcheck| image:: https://github.com/steinwurf/cpuid/actions/workflows/cppcheck.yml/badge.svg
   :target: https://github.com/steinwurf/cpuid/actions/workflows/cppcheck.yml

cpuid is a C++ library for CPU dispatching. Currently the project can
detect the following CPU capabilities:

* Instruction sets detected on x86: FPU, MMX, SSE, SSE2, SSE3, SSSE3,
   SSE 4.1, SSE 4.2, PCLMULQDQ, AVX, AVX2 and AVX-512 extensions.

* Instruction sets detected on ARM: NEON


License
*******

cpuid license is based on the BSD License. Please refer to the
LICENSE.rst file for more details.


Platforms
*********

We have tested cpuid on various versions of Windows, Linux and Mac. We
run automated tests with different compilers like g++, clang and msvc.


Build
*****

Fetch the sources, and we also recommend that you switch to the last
released version of the library:

::

   git clone https://github.com/steinwurf/cpuid
   cd cpuid
   git checkout 8.0.0

We use the ``waf`` build system to build the cpuid static library. We
have some additional waf tools which can be found at `waf
<https://github.com/steinwurf/waf>`_.

To configure and build cpuid, run the following commands:

::

   python waf configure
   python waf build
   python waf install --destdir cpuid_install

The final ``install`` step will create a folder containing all the
nessecary files needed to use the library (e.g. static library,
headers etc.). You can change the output folder by passing a different
path to ``--destdir``.

When building the libraries, waf will also build the
``print_cpuinfo_example`` executable which is useful to print the
available CPU instruction sets. The compiled binary is located in the
``build/[platform]/examples/print_cpuinfo`` folder (where
``[platform]`` denotes your current platform, e.g. ``linux``,
``win32`` or ``darwin``).

Use as Dependency in CMake
**************************

To depend on this project when using the CMake build system, add the
following in your CMake build script:

::

   add_subdirectory("/path/to/cpuid" cpuid)
   target_link_libraries(<my_target> steinwurf::cpuid)

Where ``<my_target>`` is replaced by your target.


Credits
*******

We have created cpuid to fit our specific needs, however we hope that
others may also find it useful. When designing cpuid we found
inspiration in these other nice projects:

* CPUID article on Wikipedia: http://en.wikipedia.org/wiki/CPUID

* zchotia's gist: https://gist.github.com/zchothia/3078968

* Facebook CPU ID implementation:
   https://github.com/facebook/folly/blob/master/folly/CpuId.h

* ARM Cortex-A Programmer's guide:
   http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.den0013d/index.html

* Intel® Architecture Instruction Set Extensions Programming Reference:
   https://software.intel.com/content/dam/develop/public/us/en/documents/architecture-instruction-set-extensions-programming-reference.pdf