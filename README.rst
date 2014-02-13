Introduction
------------
cpuid is a C++ library for CPU dispatching. Currently, the
project checks the following CPU capabilities:

* Available instruction sets checked for x86: FPU, MMX, SSE, SSE2, SSE3, SSSE3,
  SSE 4.1, SSE 4.2, PCLMULQDQ and AVX
* Available instruction sets checked for ARM: NEON

License
-------
cpuid license is based on the BSD License. Please refer to LICENSE.rst file
for more details.

Platforms
---------
We have tested cpuid on various versions of Windows, Linux and Mac. Also, we
have tested it on x86 and ARM architectures with different compilers like g++,
Microsoft Visual Studio, clang. You can see the status by selecting
the cpuid project on the Steinwurf
`buildbot page <http://buildbot.steinwurf.dk:12344/>`_:

Build
-----
We use the ``waf`` build-system to build the cpuid static library.
With some additional tools which may be found at external-waf_

.. _external-waf: https://github.com/steinwurf/external-waf

To build cpuid run the following command:
::
  ./waf configure --bundle=ALL --bundle-path=~/dev/bundle_dependencies
  ./waf build

Substitute the ``~/dev/bundle_dependencies`` with the path where you wish
waf to download cpuid's dependencies. You should now have the ``libcpuid.a``
static lib. In the cpuid directory type ``find . -type f -name "*.a"`` to see
the libraries produced.

When building the static lib, waf will also build the ``print_cpuinfo_example``
executable in the ``~/dev/cpuid/build/linux/examples/print_cpuinfo``
path. You may check with this example your local instruction sets

Credits
-------
We have created cpuid to fit our specific purpose, however we hope
that others may also find it useful. When designing cpuid we found
inspiration in these other nice projects:

* CPUID website on Wikipedia: http://en.wikipedia.org/wiki/CPUID
* zchotia's gist: https://gist.github.com/zchothia/3078968
* Facebook CPU ID implementation: https://github.com/facebook/folly/blob/master/folly/CpuId.h
* ARM Cortex-A Programmer's guide

Thanks in advance
