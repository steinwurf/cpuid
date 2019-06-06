cpuid
-----

.. image:: http://buildbot.steinwurf.dk/svgstatus?project=cpuid
    :target: http://buildbot.steinwurf.dk/stats?projects=cpuid

cpuid is a C++ library for CPU dispatching. Currently the
project can detect the following CPU capabilities:

- Instruction sets detected on x86: FPU, MMX, SSE, SSE2, SSE3, SSSE3,
  SSE 4.1, SSE 4.2, PCLMULQDQ, AVX, and AVX2
- Instruction sets detected on ARM: NEON


.. contents:: Table of Contents:
   :local:

License
-------
cpuid license is based on the BSD License. Please refer to the LICENSE.rst
file for more details.

Platforms
---------
We have tested cpuid on various versions of Windows, Linux and Mac. We run
automated tests on x86 and ARM architectures with different compilers like
g++, clang and Microsoft Visual Studio.

You can see the status by selecting the cpuid project on the
`Steinwurf buildbot page <http://buildbot.steinwurf.dk:12344/>`_.

Build
-----

Fetch the sources:

.. parsed-literal::

  git clone https://github.com/steinwurf/cpuid
  cd cpuid
  git checkout |version|

We use the ``waf`` build system to build the cpuid static library.
We have some additional waf tools which can be found at waf_.

.. _waf: https://github.com/steinwurf/waf

To configure and build cpuid, run the following commands::

  python waf configure
  python waf build
  python waf install --destdir .

The final ``install`` step will create a folder containing all the nessecary
files needed to use the library (e.g. static library, headers etc.). You
can change the output folder by passing a different path to ``--destdir``:

.. parsed-literal::

  python waf install --destdir=/tmp
  cd /tmp/cpuid\_\ |version|


When building the libraries, waf will also build the ``print_cpuinfo_example``
executable which is useful to print the available CPU instruction sets.
The compiled binary is located in the ``build/[platform]/examples/print_cpuinfo``
folder (where ``[platform]`` denotes your current platform,
e.g. ``linux``, ``win32`` or ``darwin``).

API
---

.. wurfapi:: class_synopsis.rst
  :selector: cpuid::cpuinfo

Credits
-------
We have created cpuid to fit our specific needs, however we hope
that others may also find it useful. When designing cpuid we found
inspiration in these other nice projects:

* CPUID article on Wikipedia: http://en.wikipedia.org/wiki/CPUID
* zchotia's gist: https://gist.github.com/zchothia/3078968
* Facebook CPU ID implementation: https://github.com/facebook/folly/blob/master/folly/CpuId.h
* ARM Cortex-A Programmer's guide: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.den0013d/index.html
