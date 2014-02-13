Introduction
------------
cpuid is a C++ library for CPU dispatching functionality testing.

License
-------
cpuid license is based on the BSD License. Please refer to LICENSE.rst file
for more details.

Dependencies
------------
* We work mainly with C++11 and currently use a few features, so you therefore
  have to supply the appropiate C++11 compiler switch when using cpuid.
* cpuid relies on the boost libraries and gtest as dependencies for its unit
  tests. However, the source code itself is a non-dependent standalone library.

Platforms
---------
We have tested cpuid on various versions of Windows, Linux and Mac. Also, we
have tested it in x86 and ARM architectures with different compilers like GCC,
Microsoft Visual Studio, CLang and LLVM. You can see the status by selecting
the cpuid project on the Steinwurf
`buildbot page <http://176.28.49.184:12344/>`_:

Build
-----
We use the ``waf`` build-system to build the cpuid static library.
With some additional tools which may be found at external-waf_

.. _external-waf: https://github.com/steinwurf/external-waf

To build gauge run the following command:
::
  ./waf configure --bundle=ALL --bundle-path=~/dev/bundle_dependencies
  ./waf build

Substitute the ``~/dev/bundle_dependencies`` with the path where you wish
waf to download cpuid's dependencies. You may omit this option then waf
will download the dependencies into the gauge project folder.

You should now have the ``libcpuid.a`` static lib. In the gauge directory
type ``find . -type f -name "*.a"`` to see the libraries produced. We need to
use the path to the libraries when using gauge with our own applications as
shown in the following.

When building the static lib, waf will also build the ``print_cpuinfo_example``
executable in the ``~/dev/cpuid/build/linux/examples/print_cpuinfo``
path.
Depending on your platform you should be able to launch it by running (linux):
::
  ./build/linux/examples/print_cpuinfo/print_cpuinfo_example

Example Use
-----------
Run ``print_cpuinfo_example`` to check your local available instruction sets.
To try it out either use the code provided or save the following code in a file called ``main.cpp``
::

#include <iostream>
#include <cpuid/cpuinfo.hpp>


int main()
{
    cpuid::cpuinfo m_cpuid;

    std::cout << "Platform: " << m_cpuid.platform() << std::endl;

    std::cout << "CPU has FPU?: "
        << (m_cpuid.has_fpu() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has MMX?: "
        << (m_cpuid.has_mmx() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE?: "
        << (m_cpuid.has_sse() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE2?: "
        << (m_cpuid.has_sse2() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE3?: "
        << (m_cpuid.has_sse3() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSSE3?: "
        << (m_cpuid.has_ssse3() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE4.1?: "
        << (m_cpuid.has_sse4_1() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has SSE4.2?: "
        << (m_cpuid.has_sse4_2() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has PCLMULQDQ?: "
        << (m_cpuid.has_pclmulqdq() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has AVX?: "
        << (m_cpuid.has_avx() ? "Yes" : "No") << std::endl;

    std::cout << "CPU has ARM NEON?: "
        << (m_cpuid.has_neon() ? "Yes" : "No") << std::endl;

    return 0;
}

cpuid is an abstract class designed under the pImpl Idiom (Pointer to
Implementation or Cheshire Cat) that defines itself according a specific
architecture. It contains several public member functions, e.g.
``bool m_cpuid::has_XX()`` per each instruction set that supports SIMD or some
other multiple data instructions.

Using ``g++`` the example code may be compiled as:
::
  g++ main.cpp -o print_cpuinfo --std=c++0x -I../path_to_cpuid/ -L../path_to_libcpuid -lcpuid -L../path_to_libboostxyz -lboost_program_options -lrt

We assume you are using the boost libs built together with cpuid. In the
future we will attempt also support boost libraries installed using your
package manager or similar.

You should now be able to run the example using:
::
  ./print_cpuinfo

Unit tests
----------

On the ``~/dev/cpuid/test`` path you will find the unit tests designed within
the Google Test framework and a Boost Program Options' source file for command-
line arguments parsing. You can check the executable ``cpuid_tests`` by ``waf``
build on ``~/dev/cpuid/build/linux/test`` that implements this. It allows command
line options such as, e.g. ``--has_sse=True``, to indicate if a specific
instruction set is considered to be available.


Credits
-------
We have created cpuid to fit our specific purpose, however we hope
that others may also find it useful. When designing cpuid we found
inspiration in these other nice projects:

* CPUID website on Wikipedia: http://en.wikipedia.org/wiki/CPUID
* zchotia's gist: https://gist.github.com/zchothia/3078968
* Facebook CPU ID implementation: https://github.com/facebook/folly/blob/master/folly/CpuId.h
* ARM A-Cortex Programmer's guide: 

Thanks in advance.

