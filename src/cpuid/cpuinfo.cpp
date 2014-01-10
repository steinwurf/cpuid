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

#elif defined(__arm__)

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

#if (defined(__linux__) || defined(ANDROID))
            bool has_neon() const
            {
                bool has;
                FILE* cpufile;
                cpufile = fopen ("/proc/cpuinfo","r");

                char buf[512];
                while (fgets(buf, 511, cpufile) != NULL)
                {
                    if (memcmp(buf, "Features", 8) == 0)
                    {
                        char* neon;
                        neon = strstr(buf,"neon");
                        if(neon != NULL)
                        {
                            has = true;
                        }
                        else
                        {
                            has = false;
                        }
                    }
                }

                fclose(cpufile);

                return has;

            }
#else
            bool has_neon() const
            {
                return false;
            }

            void get_cpuinfo()
            {
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
    cpuinfo::~cpuinfo() = default;

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
