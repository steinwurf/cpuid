
cpuid
*****

.. image:: https://travis-ci.org/steinwurf/cpuid.svg?branch=master
   :target: https://travis-ci.org/steinwurf/cpuid

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


API
***

.. _cpuid-cpuinfo:


class cpuinfo
=============

**Scope:** cpuid


Member functions (public)
-------------------------

+------------------------------------------------------------+------------------------------------------------------------------------------------+
|                                                            | `cpuinfo <cpuid-cpuinfo-cpuinfo_>`_ ()                                             |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
|                                                            | `~cpuinfo <id29_>`_ ()                                                             |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_fpu <cpuid-cpuinfo-has-fpu-const_>`_ () const                                 |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_mmx <cpuid-cpuinfo-has-mmx-const_>`_ () const                                 |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse <cpuid-cpuinfo-has-sse-const_>`_ () const                                 |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse2 <cpuid-cpuinfo-has-sse2-const_>`_ () const                               |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse3 <cpuid-cpuinfo-has-sse3-const_>`_ () const                               |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_ssse3 <cpuid-cpuinfo-has-ssse3-const_>`_ () const                             |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse4_1 <cpuid-cpuinfo-has-sse4-1-const_>`_ () const                           |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_sse4_2 <cpuid-cpuinfo-has-sse4-2-const_>`_ () const                           |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_pclmulqdq <cpuid-cpuinfo-has-pclmulqdq-const_>`_ () const                     |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx <cpuid-cpuinfo-has-avx-const_>`_ () const                                 |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx2 <cpuid-cpuinfo-has-avx2-const_>`_ () const                               |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_f <cpuid-cpuinfo-has-avx512-f-const_>`_ () const                       |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_dq <cpuid-cpuinfo-has-avx512-dq-const_>`_ () const                     |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_ifma <cpuid-cpuinfo-has-avx512-ifma-const_>`_ () const                 |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_pf <cpuid-cpuinfo-has-avx512-pf-const_>`_ () const                     |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_er <cpuid-cpuinfo-has-avx512-er-const_>`_ () const                     |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_cd <cpuid-cpuinfo-has-avx512-cd-const_>`_ () const                     |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_bw <cpuid-cpuinfo-has-avx512-bw-const_>`_ () const                     |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_vl <cpuid-cpuinfo-has-avx512-vl-const_>`_ () const                     |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_vbmi <cpuid-cpuinfo-has-avx512-vbmi-const_>`_ () const                 |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_vbmi2 <cpuid-cpuinfo-has-avx512-vbmi2-const_>`_ () const               |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_vnni <cpuid-cpuinfo-has-avx512-vnni-const_>`_ () const                 |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_bitalg <cpuid-cpuinfo-has-avx512-bitalg-const_>`_ () const             |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_vpopcntdq <cpuid-cpuinfo-has-avx512-vpopcntdq-const_>`_ () const       |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_4vnniw <cpuid-cpuinfo-has-avx512-4vnniw-const_>`_ () const             |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_4fmaps <cpuid-cpuinfo-has-avx512-4fmaps-const_>`_ () const             |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_avx512_vp2intersect <cpuid-cpuinfo-has-avx512-vp2intersect-const_>`_ () const |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_f16c <cpuid-cpuinfo-has-f16c-const_>`_ () const                               |
+------------------------------------------------------------+------------------------------------------------------------------------------------+
| `bool <https://en.cppreference.com/w/cpp/language/types>`_ | `has_neon <cpuid-cpuinfo-has-neon-const_>`_ () const                               |
+------------------------------------------------------------+------------------------------------------------------------------------------------+


Description
-----------

The cpuinfo object extract information about which, if any, additional
instructions are supported by the CPU.


Member Function Descriptions
----------------------------

.. _cpuid-cpuinfo-cpuinfo:

**cpuinfo** ()

..

   Constructor for feature detection with default values.

======================================================================

.. _id29:

**~cpuinfo** ()

..

   Destructor.

======================================================================

.. _cpuid-cpuinfo-has-fpu-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_fpu** () const

..

   Has X87 FPU.

======================================================================

.. _cpuid-cpuinfo-has-mmx-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_mmx** () const

..

   Return true if the CPU supports MMX.

======================================================================

.. _cpuid-cpuinfo-has-sse-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse** () const

..

   Return true if the CPU supports SSE.

======================================================================

.. _cpuid-cpuinfo-has-sse2-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse2** () const

..

   Return true if the CPU supports SSE2.

======================================================================

.. _cpuid-cpuinfo-has-sse3-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse3** () const

..

   Return true if the CPU supports SSE3.

======================================================================

.. _cpuid-cpuinfo-has-ssse3-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_ssse3** () const

..

   Return true if the CPU supports SSSE3.

======================================================================

.. _cpuid-cpuinfo-has-sse4-1-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse4_1** () const

..

   Return true if the CPU supports SSE 4.1.

======================================================================

.. _cpuid-cpuinfo-has-sse4-2-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_sse4_2** () const

..

   Return true if the CPU supports SSE 4.2.

======================================================================

.. _cpuid-cpuinfo-has-pclmulqdq-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_pclmulqdq** () const

..

   Return true if the CPU supports pclmulqdq.

======================================================================

.. _cpuid-cpuinfo-has-avx-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx** () const

..

   Return true if the CPU supports AVX.

======================================================================

.. _cpuid-cpuinfo-has-avx2-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx2** () const

..

   Return true if the CPU supports AVX2.

======================================================================

.. _cpuid-cpuinfo-has-avx512-f-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_f** () const

..

   Return true if the CPU supports AVX512F.

======================================================================

.. _cpuid-cpuinfo-has-avx512-dq-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_dq** () const

..

   Return true if the CPU supports AVX512DQ.

======================================================================

.. _cpuid-cpuinfo-has-avx512-ifma-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_ifma** () const

..

   Return true if the CPU supports AVX512_IFMA.

======================================================================

.. _cpuid-cpuinfo-has-avx512-pf-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_pf** () const

..

   Return true if the CPU supports AVX512PF.

======================================================================

.. _cpuid-cpuinfo-has-avx512-er-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_er** () const

..

   Return true if the CPU supports AVX512ER.

======================================================================

.. _cpuid-cpuinfo-has-avx512-cd-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_cd** () const

..

   Return true if the CPU supports AVX512CD.

======================================================================

.. _cpuid-cpuinfo-has-avx512-bw-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_bw** () const

..

   Return true if the CPU supports AVX512BW.

======================================================================

.. _cpuid-cpuinfo-has-avx512-vl-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_vl** () const

..

   Return true if the CPU supports AVX512VL.

======================================================================

.. _cpuid-cpuinfo-has-avx512-vbmi-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_vbmi** () const

..

   Return true if the CPU supports AVX512_VBMI.

======================================================================

.. _cpuid-cpuinfo-has-avx512-vbmi2-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_vbmi2** () const

..

   Return true if the CPU supports AVX512_VBMI2.

======================================================================

.. _cpuid-cpuinfo-has-avx512-vnni-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_vnni** () const

..

   Return true if the CPU supports AVX512_VNNI.

======================================================================

.. _cpuid-cpuinfo-has-avx512-bitalg-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_bitalg** () const

..

   Return true if the CPU supports AVX512_BITALG.

======================================================================

.. _cpuid-cpuinfo-has-avx512-vpopcntdq-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_vpopcntdq** () const

..

   Return true if the CPU supports AVX512_VPOPCNTDQ.

======================================================================

.. _cpuid-cpuinfo-has-avx512-4vnniw-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_4vnniw** () const

..

   Return true if the CPU supports AVX512_4VNNIW.

======================================================================

.. _cpuid-cpuinfo-has-avx512-4fmaps-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_4fmaps** () const

..

   Return true if the CPU supports AVX512_4FMAPS.

======================================================================

.. _cpuid-cpuinfo-has-avx512-vp2intersect-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_avx512_vp2intersect** () const

..

   Return true if the CPU supports AVX512_VP2INTERSECT.

======================================================================

.. _cpuid-cpuinfo-has-f16c-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_f16c** () const

..

   Return true if the CPU supports F16C.

======================================================================

.. _cpuid-cpuinfo-has-neon-const:

`bool <https://en.cppreference.com/w/cpp/language/types>`_ **has_neon** () const

..

   Return true if the CPU supports NEON.


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

* Intel® Architecture Instruction Set Extensions Programming
   Reference:
   https://software.intel.com/content/dam/develop/public/us/en/documents/architecture-instruction-set-extensions-programming-reference.pdf
