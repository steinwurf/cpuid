#include <stdint.h>

#if (defined(_MSC_VER))
    #include <intrin.h>
#endif

#include "cpuinfo.hpp"

namespace cpuid
{

#if (defined(__x86_64__)||defined(_M_X64)||defined(__i386__)||defined(_M_IX86))

    // Private class definition for x86
    class cpuinfo::impl
    {
        public:

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

            bool has_neon() const
            {
                return false;
            }

            /// CPU feature set info in m_eax,m_ebx,m_ecx,m_edx

    #if (defined(_MSC_VER))

            void get_cpuinfo()
            {
                uint32_t ex_registers[4] = {m_eax,m_ebx,m_ecx,m_edx};
                //uint32_t input = 1;

                __cpuid(ex_registers,0x1);
            }

    #else

            void get_cpuinfo()
            {
                __asm__("cpuid"
                        : "=a"(m_eax), "=b"(m_ebx),
                          "=c"(m_ecx), "=d"(m_edx)
                        : "a"(1) );
            }

    #endif

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

#elif (defined(__arm__) || defined(_M_ARM)) || defined(__mips__)

    // Private class definition for ARM
    class cpuinfo::impl
    {
        public:

            bool has_fpu() const
            {
                return false;
            }
            bool has_mmx() const
            {
                return false;
            }

            /// @return true if the CPU supports the SSE instruction set
            bool has_sse() const
            {
                return false;
            }

            /// @return true if the CPU supports the SSE2 instruction set
            bool has_sse2() const
            {
                return false;
            }

            /// @return true if the CPU supports the SSE3 instruction set
            bool has_sse3() const
            {
                return false;
            }

            /// @return true if the CPU supports the SSSE3 instruction set
            bool has_ssse3() const
            {
                return false;
            }

            /// @return true if the CPU supports the SSE4.1 instruction set
            bool has_sse4_1() const
            {
                return false;
            }

            /// @return true if the CPU supports the SSE4.2 instruction set
            bool has_sse4_2() const
            {
                return false;
            }

            /// @return true if the CPU supports the PCLMULQDQ instruction set
            bool has_pclmulqdq() const
            {
                return false;
            }

            /// @return true if the CPU supports the AVX instruction set
            bool has_avx() const
            {
                return false;
            }

            void get_cpuinfo()
            {
            }

    #if (defined(__linux__) || defined(ANDROID))

            bool has_neon() const
            {
                bool has;
                FILE* cpufile;
                cpufile = fopen("/proc/cpuinfo","r");

                char buffer[512];
                while (fgets(buffer, 511, cpufile) != NULL)
                {
                    if (memcmp(buffer, "Features", 8) == 0)
                    {
                        char* neon;
                        neon = strstr(buffer,"neon");
                        if(neon != NULL)
                        {
                            has = true;
                        }
                        else
                        {
                            has = false;
                        }
                    }
                    else
                    {
                        has = false;
                    }
                }

                fclose(cpufile);

                return has;

            }

    #elif (defined(_MSC_VER) && defined(_M_ARM))

            bool has_neon() const
            {
                try
                {
                    __emit(0xF2200150);
                    return true;
                }
                catch(const std::exception &e)
                {
                    //std::cout << "Error:" << e.what() << std::endl;
                    return false;
                }
            }

    #else

            bool has_neon() const
            {
                return false;
            }

    #endif
    };

#else

#error "Failed to detect architecture"

#endif

    // Constructor
    cpuinfo::cpuinfo()
        : m_impl(new impl())
    {
        m_impl->get_cpuinfo();
    }

    // Destructor

#if (defined(_MSC_VER))
    cpuinfo::~cpuinfo()
    { }
#else
    cpuinfo::~cpuinfo() = default;
#endif

    // x86 member functions
    bool cpuinfo::has_fpu() const
    {
        return m_impl->has_fpu();
    }

    bool cpuinfo::has_mmx() const
    {
        return m_impl->has_mmx();
    }

    bool cpuinfo::has_sse() const
    {
        return m_impl->has_sse();
    }

    bool cpuinfo::has_sse2() const
    {
        return m_impl->has_sse2();
    }

    bool cpuinfo::has_sse3() const
    {
        return m_impl->has_sse3();
    }

    bool cpuinfo::has_ssse3() const
    {
        return m_impl->has_ssse3();
    }

    bool cpuinfo::has_sse4_1() const
    {
        return m_impl->has_sse4_1();
    }

    bool cpuinfo::has_sse4_2() const
    {
        return m_impl->has_sse4_2();
    }

    bool cpuinfo::has_pclmulqdq() const
    {
        return m_impl->has_pclmulqdq();
    }

    bool cpuinfo::has_avx() const
    {
        return m_impl->has_avx();
    }

    // ARM member functions
    bool cpuinfo::has_neon() const
    {
        return m_impl->has_neon();
    }

}
