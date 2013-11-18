#include <iostream>
#include <stdio.h>


#define XSTR(x) STR(x)
#define STR(x) #x

#ifdef __x86_64__
  #pragma message "x86 macro exist and is: " XSTR(__x86_64__)
#endif



int main()
{

    uint32_t EX_registers[4];

    for (int eax_input = 0; eax_input < 3; eax_input++)
    {
      __asm__("cpuid"
              : "=a"(EX_registers[0]), "=b"(EX_registers[1]),
                "=c"(EX_registers[2]), "=d"(EX_registers[3])
              : "a"(eax_input) );

     printf("Register values in HEX for request EAX = %d:\n",eax_input);
     printf("EAX: %#010x\n",EX_registers[0]);
     printf("EBX: %#010x\n",EX_registers[1]);
     printf("ECX: %#010x\n",EX_registers[2]);
     printf("EDX: %#010x\n\n",EX_registers[3]);

    if(eax_input == 0)
    {

        for (int i = 4; i<8; i++)
        {
            printf("%c" ,((char *)EX_registers)[i]);
        }

        for (int i = 12; i<16; i++)
        {
            printf("%c" ,((char *)EX_registers)[i]);
        }

        for (int i = 8; i<12; i++) {
            printf("%c" ,((char *)EX_registers)[i]);
        }

        printf("\n\n");

    }

    if(eax_input == 1)
    {
         if (!EX_registers[0])
         {
             printf("CPU ID NOT SUPPORTED\n");
         }

         if ((EX_registers[3] & (1 << 0))) // FPU
         {
             printf("Onboard x87 FPU supported!\n");
         }

         if ((EX_registers[3] & (1 << 23))) // MMX
         {
             printf("MMX supported!\n");
         }

         if ((EX_registers[3] & (1 << 25))) // SSE
         {
             printf("SSE supported!\n");
         }

         if ((EX_registers[3] & (1 << 26))) // SSE2
         {
             printf("SSE2 supported!\n");
         }

         if ((EX_registers[2] & (1 << 0))) // SSE3
         {
             printf("SSE3 supported!\n");
         }

         if ((EX_registers[2] & (1 << 9))) // SSSE3
         {
             printf("SSSE3 supported!\n");
         }

         if ((EX_registers[2] & (1 << 19))) // SSE4.1
         {
             printf("SSE4.1 supported!\n");
         }

         if ((EX_registers[2] & (1 << 1))) // PCLMULQDQ
         {
             printf("PCLMULQDQ supported!\n");
         }

         if ((EX_registers[2] & (1 << 20))) // SSE4.2
         {
             printf("SSE4.2 supported!\n");
         }

         if ((EX_registers[2] & (1 << 28))) // AVX
         {
             printf("AVX supported!\n");
         }

         printf("\n");
    }

  }

return 0;

}
