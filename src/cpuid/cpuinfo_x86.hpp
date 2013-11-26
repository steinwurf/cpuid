#include <iostream>
#include <stdio.h>

namespace cpuid
{

    class cpuinfo_x86
    {
        public:

            //Prints vendor ID as a string
            void print_vendorID(uint32_t* EX_registers)
            {

                //Print EBX register
                for (int i = 0; i<4; i++)
                {
                    printf("%c" ,((char *)EX_registers)[i+4]);
                }

                //Print EDX register
                for (int i = 0; i<4; i++)
                {
                    printf("%c" ,((char *)EX_registers)[i+12]);
                }

                //Print ECX register
                for (int i = 0; i<4; i++) {
                    printf("%c" ,((char *)EX_registers)[i+8]);
                }

                printf("\n\n");

            }

            //Print EX registers values
            void print_EX_registers(uint32_t* EX_registers, int eax_input)
            {

                printf("Register values in HEX for request EAX = %d:\n",
                       eax_input);
                printf("EAX: %#010x\n",EX_registers[0]);
                printf("EBX: %#010x\n",EX_registers[1]);
                printf("ECX: %#010x\n",EX_registers[2]);
                printf("EDX: %#010x\n\n",EX_registers[3]);
            }

            //Assembler function that gets the CPU info
            void get_cpuinfo(uint32_t& EX_registers, int eax_input)
            {

                __asm__("cpuid"
                        : "=a"(EX_registers[0]), "=b"(EX_registers[1]),
                          "=c"(EX_registers[2]), "=d"(EX_registers[3])
                        : "a"(eax_input) );

            }

        private:

            //Register values
            uint32_t EX_registers[4];
    };

}
