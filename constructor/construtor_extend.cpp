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


class B : public A {
    public:
    B() {
        a = 1;
    }
};


int main() {
    B b;
    return 0;
}

/*

A::A() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 1
        nop
        pop     rbp
        ret
B::B() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    A::A() [base object constructor]
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 1
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-4]
        mov     rdi, rax
        call    B::B() [complete object constructor]
        mov     eax, 0
        leave
        ret

*/