
cpuid
*****

cpuid is a C++ library for CPU dispatching. Currently the project can
detect the following CPU capabilities:

* Instruction sets detected on x86: FPU, MMX, SSE, SSE2, SSE3, SSSE3,
   SSE 4.1, SSE 4.2, PCLMULQDQ, AVX, and AVX2

* Instruction sets detected on ARM: NEON

.. image:: http://buildbot.steinwurf.dk/svgstatus?project=cpuid
   :target: http://buildbot.steinwurf.dk/stats?projects=cpuid


License
*******

cpuid license is based on the BSD License. Please refer to the
LICENSE.rst file for more details.


Platforms
*********

We have tested cpuid on various versions of Windows, Linux and Mac. We
run automated tests on x86 and ARM architectures with different
compilers like g++, clang and Microsoft Visual Studio.

You can see the status by selecting the cpuid project on the
`Steinwurf buildbot page <http://buildbot.steinwurf.dk:12344/>`_.


Build
*****

We use the ``waf`` build system to build the cpuid static library. We
have some additional waf tools which can be found at `waf
<https://github.com/steinwurf/waf>`_.

To configure and build cpuid, run the following commands:

::

   python waf configure
   python waf build

The ``waf configure`` command will download several auxiliary
libraries into a folder called ``bundle_dependencies`` within the
cpuid folder. You can also use the ``--bundle-path`` option to specify
the download location for the project dependencies:

::

   python waf configure --bundle-path=/my/path/to/bundle_dependencies

When building the static lib, waf will also build the
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

+----------------------------------------------------+----------------------------------------------------+
|                                                    | cpuinfo ()                                         |
+----------------------------------------------------+----------------------------------------------------+
|                                                    | ~cpuinfo ()                                        |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_avx () const                                   |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_avx2 () const                                  |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_fpu () const                                   |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_mmx () const                                   |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_neon () const                                  |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_pclmulqdq () const                             |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_sse () const                                   |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_sse2 () const                                  |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_sse3 () const                                  |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_sse4_1 () const                                |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_sse4_2 () const                                |
+----------------------------------------------------+----------------------------------------------------+
| bool                                               | has_ssse3 () const                                 |
+----------------------------------------------------+----------------------------------------------------+


Description
-----------

The cpuinfo object extract information about which, if any, additional
instructiions are supported by the CPU.


Member Function Description
---------------------------

.. _cpuid-cpuinfo-cpuinfo:

..

   **cpuinfo** ()

   ..

      Constructor for feature detection with default values.

======================================================================

.. _id1:

..

   **~cpuinfo** ()

   ..

      Destructor.

======================================================================

.. _cpuid-cpuinfo-has-avx-const:

bool **has_avx** ()

..

   Return true if the CPU supports AVX.

======================================================================

.. _cpuid-cpuinfo-has-avx2-const:

bool **has_avx2** ()

..

   Return true if the CPU supports AVX2.

======================================================================

.. _cpuid-cpuinfo-has-fpu-const:

bool **has_fpu** ()

..

   Has X87 FPU.

======================================================================

.. _cpuid-cpuinfo-has-mmx-const:

bool **has_mmx** ()

..

   Return true if the CPU supports MMX.

======================================================================

.. _cpuid-cpuinfo-has-neon-const:

bool **has_neon** ()

..

   ARM member functions.

======================================================================

.. _cpuid-cpuinfo-has-pclmulqdq-const:

bool **has_pclmulqdq** ()

..

   Return true if the CPU supports pclmulqdq.

======================================================================

.. _cpuid-cpuinfo-has-sse-const:

bool **has_sse** ()

..

   Return true if the CPU supports SSE.

======================================================================

.. _cpuid-cpuinfo-has-sse2-const:

bool **has_sse2** ()

..

   Return true if the CPU supports SSE2.

======================================================================

.. _cpuid-cpuinfo-has-sse3-const:

bool **has_sse3** ()

..

   Return true if the CPU supports SSE3.

======================================================================

.. _cpuid-cpuinfo-has-sse4-1-const:

bool **has_sse4_1** ()

..

   Return true if the CPU supports SSE 4.1.

======================================================================

.. _cpuid-cpuinfo-has-sse4-2-const:

bool **has_sse4_2** ()

..

   Return true if the CPU supports SSE 4.2.

======================================================================

.. _cpuid-cpuinfo-has-ssse3-const:

bool **has_ssse3** ()

..

   Return true if the CPU supports SSSE3.


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
