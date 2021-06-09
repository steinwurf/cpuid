cpuid
-----

.. image:: https://travis-ci.org/steinwurf/cpuid.svg?branch=master
    :target: https://travis-ci.org/steinwurf/cpuid

cpuid is a C++ library for CPU dispatching. Currently the
project can detect the following CPU capabilities:

- Instruction sets detected on x86: FPU, MMX, SSE, SSE2, SSE3, SSSE3,
  SSE 4.1, SSE 4.2, PCLMULQDQ, AVX, AVX2 and AVX-512 extensions.
- Instruction sets detected on ARM: NEON


.. contents:: Table of Contents:
   :local:

License
-------
cpuid license is based on the BSD License. Please refer to the LICENSE.rst
file for more details.

Platforms
---------
We have tested cpuid on various versions of Windows, Linux and Mac. We
run automated tests with different compilers like g++, clang and msvc.

Build
-----

Fetch the sources, and we also recommend that you switch to the last released
version of the library:

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
  python waf install --destdir cpuid_install

The final ``install`` step will create a folder containing all the nessecary
files needed to use the library (e.g. static library, headers etc.). You
can change the output folder by passing a different path to ``--destdir``.

When building the libraries, waf will also build the ``print_cpuinfo_example``
executable which is useful to print the available CPU instruction sets.
The compiled binary is located in the ``build/[platform]/examples/print_cpuinfo``
folder (where ``[platform]`` denotes your current platform,
e.g. ``linux``, ``win32`` or ``darwin``).

API
---

.. wurfapi:: class_synopsis.rst
  :selector: cpuid::cpuinfo

Use as Dependency in CMake
--------------------------

To depend on this project when using the CMake build system, add the following
in your CMake build script:

::

   add_subdirectory("/path/to/cpuid" cpuid)
   target_link_libraries(<my_target> steinwurf::cpuid)

Where ``<my_target>`` is replaced by your target.

Credits
-------
We have created cpuid to fit our specific needs, however we hope
that others may also find it useful. When designing cpuid we found
inspiration in these other nice projects:

* CPUID article on Wikipedia: http://en.wikipedia.org/wiki/CPUID
* zchotia's gist: https://gist.github.com/zchothia/3078968
* Facebook CPU ID implementation: https://github.com/facebook/folly/blob/master/folly/CpuId.h
* ARM Cortex-A Programmer's guide: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.den0013d/index.html
* Intel® Architecture Instruction Set Extensions Programming Reference: https://software.intel.com/content/dam/develop/public/us/en/documents/architecture-instruction-set-extensions-programming-reference.pdf
