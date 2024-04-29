#include <stdio.h>

void func1(long x, long y, long z) {
    x = 0;
}

void func2(long* x, long* y, long* z) {
    *x = 0;
}

long a = 1;
long b = 2;
long c = 3;

int main() {
    func1(a, b, c);
    func2(&a, &b, &c);

    return 0;
}

/*

func1(long, long, long):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     QWORD PTR [rbp-16], rsi
        mov     QWORD PTR [rbp-24], rdx
        mov     QWORD PTR [rbp-8], 0
        nop
        pop     rbp
        ret
func2(long*, long*, long*):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     QWORD PTR [rbp-16], rsi
        mov     QWORD PTR [rbp-24], rdx
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], 0
        nop
        pop     rbp
        ret
a:
        .quad   1
b:
        .quad   2
c:
        .quad   3
main:
        push    rbp
        mov     rbp, rsp
        mov     rdx, QWORD PTR c[rip]
        mov     rcx, QWORD PTR b[rip]
        mov     rax, QWORD PTR a[rip]
        mov     rsi, rcx
        mov     rdi, rax
        call    func1(long, long, long)
        mov     edx, OFFSET FLAT:c
        mov     esi, OFFSET FLAT:b
        mov     edi, OFFSET FLAT:a
        call    func2(long*, long*, long*)
        mov     eax, 0
        pop     rbp
        ret

*/

