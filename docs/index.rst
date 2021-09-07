CPUid Documentation
===================

cpuid is a C++ library for CPU dispatching. Currently the project can detect the following CPU capabilities:

* Instruction sets detected on x86: FPU, MMX, SSE, SSE2, SSE3, SSSE3,
  SSE 4.1, SSE 4.2, PCLMULQDQ, AVX, and AVX2

* Instruction sets detected on ARM: NEON

We have created cpuid to fit our specific needs, however we hope that
others may also find it useful. When designing cpuid we found
inspiration in these other nice projects:

* CPUID article on Wikipedia: http://en.wikipedia.org/wiki/CPUID

* zchotia’s gist: https://gist.github.com/zchothia/3078968

* Facebook CPU ID implementation:
   https://github.com/facebook/folly/blob/master/folly/CpuId.h

* ARM Cortex-A Programmer’s guide:
   http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.den0013d/index.html


The cpuid repository: https://github.com/steinwurf/cpuid

The ``examples`` folder contains some programs that demonstrate the usage
of the available API.

If you have any questions or suggestions about this library, please contact
us at our developer mailing list (hosted at Google Groups):

* http://groups.google.com/group/steinwurf-dev


Table of Contents
-----------------

.. toctree::
  :maxdepth: 2

  user_api/user_api
  examples/examples
  license


.. toctree::
  :maxdepth: 1

  news
