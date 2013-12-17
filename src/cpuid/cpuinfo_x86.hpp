#include <iostream>
#include <stdio.h>
#include <stdint.h>

namespace cpuid
{

    class cpuinfo_x86
    {
        public:

            // Default constructor for feature detection
            cpuinfo_x86()
            {
               get_cpuinfo();
            }

            /// @return true if the CPU supports the FPU instruction set
            bool has_fpu() const
            {
                return m_edx & (1 << 0);
            }

            /// @return true if the CPU supports the MMX instruction set
            bool has_mmx() const
            {
                return m_edx & (1 << 23);
            }

            /// @return true if the CPU supports the SSE instruction set
            bool has_sse() const
            {
                return m_edx & (1 << 25);
            }

            /// @return true if the CPU supports the SSE2 instruction set
            bool has_sse2() const
            {
                return m_edx & (1 << 26);
            }

            /// @return true if the CPU supports the SSE3 instruction set
            bool has_sse3() const
            {
                return m_ecx & (1 << 0);
            }

            /// @return true if the CPU supports the SSSE3 instruction set
            bool has_ssse3() const
            {
                return m_ecx & (1 << 9);
            }

            /// @return true if the CPU supports the SSE4.1 instruction set
            bool has_sse4_1() const
            {
                return m_ecx & (1 << 19);
            }

            /// @return true if the CPU supports the SSE4.2 instruction set
            bool has_sse4_2() const
            {
                return m_ecx & (1 << 20);
            }

            /// @return true if the CPU supports the PCLMULQDQ instruction set
            bool has_pclmulqdq() const
            {
                return m_ecx & (1 << 1);
            }

            /// @return true if the CPU supports the AVX instruction set
            bool has_avx() const
            {
                return m_ecx & (1 << 28);
            }

        protected:

            /// CPU feature set info in m_eax,m_ebx,m_ecx,m_edx
            void get_cpuinfo()
            {
                __asm__("cpuid"
                        : "=a"(m_eax), "=b"(m_ebx),
                          "=c"(m_ecx), "=d"(m_edx)
                        : "a"(1) );
            }

        private:

            // Feature bits of the EAX register when calling get_cpuinfo
            uint32_t m_eax;

            // Feature bits of the EBX register when calling get_cpuinfo
            uint32_t m_ebx;

            // Feature bits of the ECX register when calling get_cpuinfo
            uint32_t m_ecx;

            // Feature bits of the EDX register when calling get_cpuinfo
            uint32_t m_edx;

    };
}
