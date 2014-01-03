#include <vector>
#include <algorithm>

#include "commandline_arguments.hpp"

namespace cpuid
{

    commandline_arguments::commandline_arguments()
        : m_options("Options for cpuid")
    {
        m_options.add_options()
            ("help_cpuid", "produce help message for cpuid")
            ("has_fpu", po::value<bool>(),
             "Specify if you consider that current CPU has FPU "
              "for example ./cpuid_tests --has_fpu=true")
            ("has_mmx", po::value<bool>(),
             "Specify if you consider that current CPU has MMX "
              "for example ./cpuid_tests --has_mmx=true")
            ("has_sse", po::value<bool>(),
             "Specify if you consider that current CPU has SSE "
              "for example ./cpuid_tests --has_sse=true")
            ("has_sse2", po::value<bool>(),
             "Specify if you consider that current CPU has SSE2 "
              "for example ./cpuid_tests --has_sse2=true")
            ("has_sse3", po::value<bool>(),
             "Specify if you consider that current CPU has SSE3 "
              "for example ./cpuid_tests --has_sse3=true")
            ("has_ssse3", po::value<bool>(),
             "Specify if you consider that current CPU has SSSE3 "
              "for example ./cpuid_tests --has_ssse3=true")
            ("has_sse4_1", po::value<bool>(),
             "Specify if you consider that current CPU has SSE4.1 "
              "for example ./cpuid_tests --has_sse4_1=true")
            ("has_sse4_2", po::value<bool>(),
             "Specify if you consider that current CPU has SSE4.2 "
              "for example ./cpuid_tests --has_fpu=true")
            ("has_pclmulqdq", po::value<bool>(),
             "Specify if you consider that current CPU has PCLMULQDQ "
              "for example ./cpuid_tests --has_pclmulqdq=true")
            ("has_avx", po::value<bool>(),
             "Specify if you consider that current CPU has AVX "
              "for example ./cpuid_tests --has_avx=true");
    }

    po::variables_map commandline_arguments::parse(int argc, char **argv)
    {
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, m_options), vm);
        po::notify(vm);

        if (vm.count("help_cpuid"))
        {
            std::cout << m_options << std::endl;
        }

        return vm;
    }

}
