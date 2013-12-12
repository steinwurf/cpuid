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

            cpuinfo_x86()
            {
                //Create instruction set map and fill it
            }

            //Prints vendor ID as a string
            void print_vendor_id()
            {

                printf("\n\n");

                //Print EBX register
                for (uint8_t i = 0; i<4; i++)
                {
                    printf("%c" ,((char *)EX_registers)[i+4]);
                }

                //Print EDX register
                for (uint8_t i = 0; i<4; i++)
                {
                    printf("%c" ,((char *)EX_registers)[i+12]);
                }

                //Print ECX register
                for (uint8_t i = 0; i<4; i++) {
                    printf("%c" ,((char *)EX_registers)[i+8]);
                }

                printf("\n\n");

            }

            //Print EX registers values
            void print_EX_registers(uint8_t eax_input)
            {

                printf("Register values in HEX for request EAX = %d:\n",
                       eax_input);
                printf("EAX: %#010x\n",EX_registers[0]);
                printf("EBX: %#010x\n",EX_registers[1]);
                printf("ECX: %#010x\n",EX_registers[2]);
                printf("EDX: %#010x\n\n",EX_registers[3]);
            }

            //Assembler function that gets the CPU info
            void get_cpuinfo(uint8_t eax_input)
            {

                __asm__("cpuid"
                        : "=a"(EX_registers[0]), "=b"(EX_registers[1]),
                          "=c"(EX_registers[2]), "=d"(EX_registers[3])
                        : "a"(eax_input) );

            }

            //Function to get the register and flag values to check
            bool has_instruction_set(std::string instruction_set_name)
            {
                uint8_t register_id = m_instruction_set_map.find(instruction_set_name)->second.first;
                uint8_t flag = m_instruction_set_map.find(instruction_set_name)->second.second;

                return(register_flag(register_id,flag));
            }

            //Check the required register and flag
            bool register_flag(uint8_t register_id,uint8_t flag)
            {

                get_cpuinfo(1);

                if(EX_registers[register_id] & (1 << flag))
                {
                    return(true);
                }
                else
                {
                    return(false);
                }
            }

        private:
            //Register container
            typedef std::pair<uint8_t,uint8_t> register_map;
            //Instruction set map container
            typedef const std::map<std::string,register_map> instruction_set_map;
            //Register values
            uint32_t EX_registers[4];
            static instruction_set_map m_instruction_set_map;
    };

    cpuinfo_x86::instruction_set_map cpuinfo_x86::m_instruction_set_map = {
        {"FPU",std::make_pair(3,0)},
        {"MMX",std::make_pair(3,23)},
        {"SSE",std::make_pair(3,25)},
        {"SSE2",std::make_pair(3,26)},
        {"SSE3",std::make_pair(2,0)},
        {"SSSE3",std::make_pair(2,9)},
        {"SSE4.1",std::make_pair(2,19)},
        {"SSE4.2",std::make_pair(2,20)},
        {"PCLMULQDQ",std::make_pair(2,1)},
        {"AVX",std::make_pair(2,28)}
    };
}
