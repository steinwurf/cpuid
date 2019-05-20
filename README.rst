
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

Fetch the sources:

::

   git clone https://github.com/steinwurf/cpuid
   cd cpuid
   git checkout 5.0.3

We use the ``waf`` build system to build the cpuid static library. We
have some additional waf tools which can be found at `waf
<https://github.com/steinwurf/waf>`_.

To configure and build cpuid, run the following commands:

::

   python waf configure
   python waf build
   python waf install

The final ``install`` step will create a folder containing all the
nessecary files needed to use the library (e.g. static library,
headers etc.) in:

::

   cd cpuid_5.0.3

To install to a different location use the ``--destdir`` option:

::

   python waf install --destdir=/tmp
   cd /tmp/cpuid_5.0.3

When building the libraries, waf will also build the
``print_cpuinfo_example`` executable which is useful to print the
available CPU instruction sets. The compiled binary is located in the
``build/[platform]/examples/print_cpuinfo`` folder (where
``[platform]`` denotes your current platform, e.g. ``linux``,
``win32`` or ``darwin``).


API
***

.. _cpuid-steinwurf-cpuid-version-cpuinfo:


class cpuinfo
=============

**Scope:** cpuid::STEINWURF_CPUID_VERSION

**In header:** ``#include <cpuinfo.hpp>``


Member functions (public)
-------------------------

+----------------------------------------------------+----------------------------------------------------------------------------------------+
|                                                    | `cpuinfo <cpuid-steinwurf-cpuid-version-cpuinfo-cpuinfo_>`_ ()                         |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
|                                                    | `~cpuinfo <id1_>`_ ()                                                                  |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_avx <cpuid-steinwurf-cpuid-version-cpuinfo-has-avx-const_>`_ ()
const             |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_avx2 <cpuid-steinwurf-cpuid-version-cpuinfo-has-avx2-const_>`_ ()
const           |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_fpu <cpuid-steinwurf-cpuid-version-cpuinfo-has-fpu-const_>`_ ()
const             |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_mmx <cpuid-steinwurf-cpuid-version-cpuinfo-has-mmx-const_>`_ ()
const             |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_neon <cpuid-steinwurf-cpuid-version-cpuinfo-has-neon-const_>`_ ()
const           |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_pclmulqdq
<cpuid-steinwurf-cpuid-version-cpuinfo-has-pclmulqdq-const_>`_ ()
const |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_sse <cpuid-steinwurf-cpuid-version-cpuinfo-has-sse-const_>`_ ()
const             |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_sse2 <cpuid-steinwurf-cpuid-version-cpuinfo-has-sse2-const_>`_ ()
const           |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_sse3 <cpuid-steinwurf-cpuid-version-cpuinfo-has-sse3-const_>`_ ()
const           |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_sse4_1
<cpuid-steinwurf-cpuid-version-cpuinfo-has-sse4-1-const_>`_ () const       |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_sse4_2
<cpuid-steinwurf-cpuid-version-cpuinfo-has-sse4-2-const_>`_ () const       |
+----------------------------------------------------+----------------------------------------------------------------------------------------+
| bool                                               | `has_ssse3 <cpuid-steinwurf-cpuid-version-cpuinfo-has-ssse3-const_>`_
() const         |
+----------------------------------------------------+----------------------------------------------------------------------------------------+


Description
-----------

The cpuinfo object extract information about which, if any, additional
instructiions are supported by the CPU.


Member Function Description
---------------------------

.. _cpuid-steinwurf-cpuid-version-cpuinfo-cpuinfo:

**cpuinfo** ()

..

   Constructor for feature detection with default values.

======================================================================

.. _id1:

**~cpuinfo** ()

..

   Destructor.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-avx-const:

bool **has_avx** ()

..

   Return true if the CPU supports AVX.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-avx2-const:

bool **has_avx2** ()

..

   Return true if the CPU supports AVX2.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-fpu-const:

bool **has_fpu** ()

..

   Has X87 FPU.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-mmx-const:

bool **has_mmx** ()

..

   Return true if the CPU supports MMX.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-neon-const:

bool **has_neon** ()

..

   ARM member functions.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-pclmulqdq-const:

bool **has_pclmulqdq** ()

..

   Return true if the CPU supports pclmulqdq.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-sse-const:

bool **has_sse** ()

..

   Return true if the CPU supports SSE.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-sse2-const:

bool **has_sse2** ()

..

   Return true if the CPU supports SSE2.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-sse3-const:

bool **has_sse3** ()

..

   Return true if the CPU supports SSE3.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-sse4-1-const:

bool **has_sse4_1** ()

..

   Return true if the CPU supports SSE 4.1.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-sse4-2-const:

bool **has_sse4_2** ()

..

   Return true if the CPU supports SSE 4.2.

======================================================================

.. _cpuid-steinwurf-cpuid-version-cpuinfo-has-ssse3-const:

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
