#include <stdio.h>
#include "pico/stdlib.h"
#include "extra.hpp"

int main()
{
    uint32_t a = 1;
    uint32_t b = 2;

    uint32_t c = a + b;

    while (1)
    {
        printf("Hello World!\n");
        extra_print();
    }

    return 0;
}