#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Hello Syscall!\n");

    write(1, "Hello!\n", 7);

    return 0;
}

/*
.LC0:
        .string "Hello!\n"
main:
        sub     rsp, 8
        mov     edx, 7
        mov     esi, OFFSET FLAT:.LC0
        mov     edi, 1
        call    write
        xor     eax, eax
        add     rsp, 8
        ret
*/

