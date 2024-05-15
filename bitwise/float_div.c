#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


float float_div2(float x)
{   
    if(x == 0)return 0;
    // using bitwise operations. No mul, div
    __uint32_t calculate = *(__uint32_t*) &x;
    __uint32_t exponent = calculate & 0x7F800000;
    calculate &= 0x807FFFFF;
    exponent -= 0x800000;
    exponent &= 0x7F800000;
    calculate |= exponent;
    return *(float*) &calculate;
}

int main(){
    srand(time(NULL));
    bool check = true;
    for(int i = 0; i < 10000 ; i++){
        float x = (float)rand() / RAND_MAX;
        if(float_div2(x) != x/2){
            printf("Calculation Incorrect\n");
            printf("x =  %6f\n", x);
            printf("float_div2(x) = %6f\n", float_div2(x));
            printf("x/2 =  %6f\n", x/2);
            check = false;
            break;
        }
    }
    
    if(check)printf("Calculation Correct\n");
    
    return 0;
}

