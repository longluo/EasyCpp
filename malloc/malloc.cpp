#include <stdlib.h>

class A {

public:
    A() {
        x = 1;
        y = 2;
    }

    ~A() {
        x = y = 0;
    }

    int x, y;
};


void *func1() {
    return malloc(3);
}


A* func2() {
    return new A();
}


void func3(A* p) {
    delete p;
}

/*

A::A() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 1
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax+4], 2
        nop
        pop     rbp
        ret
A::~A() [base object destructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax+4], 0
        mov     rax, QWORD PTR [rbp-8]
        mov     edx, DWORD PTR [rax+4]
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], edx
        nop
        pop     rbp
        ret
func1():
        push    rbp
        mov     rbp, rsp
        mov     edi, 3
        call    malloc
        pop     rbp
        ret
func2():
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 8
        mov     edi, 8
        call    operator new(unsigned long)
        mov     rbx, rax
        mov     rdi, rbx
        call    A::A() [complete object constructor]
        mov     rax, rbx
        mov     rbx, QWORD PTR [rbp-8]
        leave
        ret
func3(A*):
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 24
        mov     QWORD PTR [rbp-24], rdi
        mov     rbx, QWORD PTR [rbp-24]
        test    rbx, rbx
        je      .L9
        mov     rdi, rbx
        call    A::~A() [complete object destructor]
        mov     esi, 8
        mov     rdi, rbx
        call    operator delete(void*, unsigned long)
.L9:
        nop
        mov     rbx, QWORD PTR [rbp-8]
        leave
        ret

*/



