#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
uint32_t unaligned_get8(void *src)
{
    // explicit type conversion
    uintptr_t csrc = (uintptr_t) src;
    // set last 2 bits as 0
    uint32_t v = *(uint32_t*) (csrc & 0xfffffffc);
    v = (v >> (((uint32_t) csrc & 0x3) * 8)) & 0x000000ff;
    return v;
}
uint32_t unaligned_get32(void *src) {
    uint32_t d = 0;
    // explicit type conversion
    uintptr_t csrc = (uintptr_t) src;
    for (int n = 0; n < 4; n++) {
        uint32_t v = unaligned_get8((void *) csrc);
        v = v << (n * 8);
        d = d | v;
        csrc++;
    }
    return d;
}

int main(){
    int ptr = 0x23456780;
    uint32_t result = unaligned_get32((void *) ptr);
    return 0;
}