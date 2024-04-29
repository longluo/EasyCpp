#include <stdio.h>

template<typename T>
T add(T x, T y) {
    return x + y;
}


int main() {
    add<int>(1, 2);
}


int add(int x, int y) {
    return x + y;
}


/*

main:
        push    rbp
        mov     rbp, rsp
        mov     esi, 2
        mov     edi, 1
        call    int add<int>(int, int)
        mov     eax, 0
        pop     rbp
        ret
add(int, int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     DWORD PTR [rbp-8], esi
        mov     edx, DWORD PTR [rbp-4]
        mov     eax, DWORD PTR [rbp-8]
        add     eax, edx
        pop     rbp
        ret
int add<int>(int, int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     DWORD PTR [rbp-8], esi
        mov     edx, DWORD PTR [rbp-4]
        mov     eax, DWORD PTR [rbp-8]
        add     eax, edx
        pop     rbp
        ret

*/
