
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
   SSE 4.1, SSE 4.2, PCLMULQDQ, AVX, and AVX2

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
   git checkout 6.4.0

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


API
***

.. _cpuid-cpuinfo:


class cpuinfo
=============

**Scope:** cpuid

**In header:** ``#include <cpuinfo.hpp>``


Member functions (public)
-------------------------

+------------------------------------------------------------+----------------------------------------------------------------+
|                                                            | `cpuinfo <cpuid-cpuinfo-cpuinfo_>`_ ()                         |
+------------------------------------------------------------+----------------------------------------------------------------+
|                                                            | `~cpuinfo <id13_>`_ ()                                         |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx <cpuid-cpuinfo-has-avx-const_>`_ () const             |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx2 <cpuid-cpuinfo-has-avx2-const_>`_ () const           |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_f16c <cpuid-cpuinfo-has-f16c-const_>`_ () const           |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_fpu <cpuid-cpuinfo-has-fpu-const_>`_ () const             |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_mmx <cpuid-cpuinfo-has-mmx-const_>`_ () const             |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_neon <cpuid-cpuinfo-has-neon-const_>`_ () const           |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_pclmulqdq <cpuid-cpuinfo-has-pclmulqdq-const_>`_ () const |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse <cpuid-cpuinfo-has-sse-const_>`_ () const             |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse2 <cpuid-cpuinfo-has-sse2-const_>`_ () const           |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse3 <cpuid-cpuinfo-has-sse3-const_>`_ () const           |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse4_1 <cpuid-cpuinfo-has-sse4-1-const_>`_ () const       |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse4_2 <cpuid-cpuinfo-has-sse4-2-const_>`_ () const       |
+------------------------------------------------------------+----------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_ssse3 <cpuid-cpuinfo-has-ssse3-const_>`_ () const         |
+------------------------------------------------------------+----------------------------------------------------------------+


Description
-----------

The cpuinfo object extract information about which, if any, additional
instructions are supported by the CPU.


Member Function Description
---------------------------

.. _cpuid-cpuinfo-cpuinfo:

**cpuinfo** ()

..

   Constructor for feature detection with default values.

======================================================================

.. _id13:

**~cpuinfo** ()

..

   Destructor.

======================================================================

.. _cpuid-cpuinfo-has-avx-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx** ()

..

   Return true if the CPU supports AVX.

======================================================================

.. _cpuid-cpuinfo-has-avx2-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx2** ()

..

   Return true if the CPU supports AVX2.

======================================================================

.. _cpuid-cpuinfo-has-f16c-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_f16c** ()

..

   Return true if the CPU supports F16C.

======================================================================

.. _cpuid-cpuinfo-has-fpu-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_fpu** ()

..

   Has X87 FPU.

======================================================================

.. _cpuid-cpuinfo-has-mmx-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_mmx** ()

..

   Return true if the CPU supports MMX.

======================================================================

.. _cpuid-cpuinfo-has-neon-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_neon** ()

..

   Return true if the CPU supports NEON.

======================================================================

.. _cpuid-cpuinfo-has-pclmulqdq-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_pclmulqdq** ()

..

   Return true if the CPU supports pclmulqdq.

======================================================================

.. _cpuid-cpuinfo-has-sse-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse** ()

..

   Return true if the CPU supports SSE.

======================================================================

.. _cpuid-cpuinfo-has-sse2-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse2** ()

..

   Return true if the CPU supports SSE2.

======================================================================

.. _cpuid-cpuinfo-has-sse3-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse3** ()

..

   Return true if the CPU supports SSE3.

======================================================================

.. _cpuid-cpuinfo-has-sse4-1-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse4_1** ()

..

   Return true if the CPU supports SSE 4.1.

======================================================================

.. _cpuid-cpuinfo-has-sse4-2-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse4_2** ()

..

   Return true if the CPU supports SSE 4.2.

======================================================================

.. _cpuid-cpuinfo-has-ssse3-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_ssse3** ()

..

   Return true if the CPU supports SSSE3.


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

* zchotia’s gist: https://gist.github.com/zchothia/3078968

* Facebook CPU ID implementation:
   https://github.com/facebook/folly/blob/master/folly/CpuId.h

* ARM Cortex-A Programmer’s guide:
   http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.den0013d/index.html
