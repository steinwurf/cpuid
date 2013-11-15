#include <iostream>

int main()
{
  int a, b;

  for (a = 0; a < 5; a++)
  {
    __asm__("cpuid;"
            :"=a"(b)                 // EAX into b (output)
            :"0"(a)                  // a into EAX (input)
            :"%ebx","%ecx","%edx");  // clobbered registers

    std::cout << "The code " << a << " gives " << b << std::endl;
  }

  return 0;
}
