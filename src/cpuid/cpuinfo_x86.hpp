#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <map>
#include <string>

namespace cpuid
{

    class cpuinfo_x86
    {
        public:

            // Default constructor for feature detection
            cpuinfo_x86()
            {
                get_cpuinfo(1);
            }

            // Overload constructor for vendor_id detection
            /// @input EAX input = 0
            cpuinfo_x86(uint8_t eax_input)
            {
                get_cpuinfo(eax_input);
            }

            /// @return Vendor ID as a string
            std::string vendor_id() const
            {

                std::string vendor_id = ("");

                // Get EBX register char values
                for (uint8_t i = 0; i<4; i++)
                {
                    vendor_id += ((char*)&m_ebx)[i];
                }

                // Get EDX register char values
                for (uint8_t i = 0; i<4; i++)
                {
                    vendor_id += ((char*)&m_edx)[i];
                }

                // Get ECX register char values
                for (uint8_t i = 0; i<4; i++)
                {
                    vendor_id += ((char*)&m_ecx)[i];
                }

                return vendor_id;
            }

            /// @return CPU info in ex registers: m_eax,m_ebx,m_ecx,m_edx
            void get_cpuinfo(uint8_t eax_input)
            {
                __asm__("cpuid"
                        : "=a"(m_eax), "=b"(m_ebx),
                          "=c"(m_ecx), "=d"(m_edx)
                        : "a"(eax_input) );
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

        private:

            // EAX, EBX, ECX and EDX registers
            uint32_t m_eax;
            uint32_t m_ebx;
            uint32_t m_ecx;
            uint32_t m_edx;

            // EAX input to get_cpuinfo
            uint8_t eax_input;
    };
}

