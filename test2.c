#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)

uint8_t hexchar2val(uint8_t in){
    const uint8_t letter = in & 0x40; 
    const uint8_t shift = (letter >> 3) | (letter >> 6); 
    return (in + shift) & 0xf;
}

uint64_t hexspeak2val(char str[]){

    int len = strlen(str);

    if (len == 1)
        return hexchar2val(str[0]);

    uint64_t total = 0;


    uint64_t i = 2;
    for (; (i + 8) <= len ; i += 8){
        uint64_t in;
        memcpy(&in, str + i, 8);
        
        const uint64_t letter = in & PACKED_BYTE(0x40); 
        const uint64_t shift = (letter >> 3) | (letter >> 6);
        const uint64_t value = (in + shift) & PACKED_BYTE(0x0f);

        for (size_t j = 0; j < 64 ; j += 8)
            total += (( value << j ) >> 56) << (j >> 1);
    }

    for (; i < len ; i++)
        total = total << 4 | hexchar2val(str[i]);

    return total;
}
int main(){
    
}