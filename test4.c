#include <stdint.h>

bool divisible(uint32_t n)
{
    return n * M <= (M - 1);
}