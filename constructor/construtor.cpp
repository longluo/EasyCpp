#include <iostream>

class A {
    public:
    int a;

    void func() {
        this->a = 1;
    }

    A() {
        a = 1;
    }
};


int main() {
    A a;
    a.func();
    return 0;
}

/*

A::func():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 1
        nop
        pop     rbp
        ret
A::A() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 1
        nop
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-4]
        mov     rdi, rax
        call    A::A() [complete object constructor]
        lea     rax, [rbp-4]
        mov     rdi, rax
        call    A::func()
        mov     eax, 0
        leave
        ret

*/