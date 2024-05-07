#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct _s1 {
    char a[5];
} s1;


int main() {
    for (int i = 0; i < 10000;  ++i) {
        char *z;
        z = malloc(sizeof(char));
        *z = 'a';
        printf("%s\n", z++);
    }
    return 0;
}