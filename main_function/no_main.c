#include <stdio.h>
#include <stdlib.h>

void func() {
    printf("Hello World!\n");
    exit(0);
}

/*
    gcc no_main.c
    

    gcc -nostartfiles -efunc no_main.c

    
*/
