#include <iostream>

class A {
    public:
    int a;

    virtual void func() {
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

A::func():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax+8], 1
        nop
        pop     rbp
        ret
A::A() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     edx, OFFSET FLAT:vtable for A+16
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax+8], 1
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
        mov     edx, OFFSET FLAT:vtable for B+16
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax+8], 1
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-16]
        mov     rdi, rax
        call    B::B() [complete object constructor]
        mov     eax, 0
        leave
        ret
vtable for B:
        .quad   0
        .quad   typeinfo for B
        .quad   A::func()
vtable for A:
        .quad   0
        .quad   typeinfo for A
        .quad   A::func()
typeinfo for B:
        .quad   vtable for __cxxabiv1::__si_class_type_info+16
        .quad   typeinfo name for B
        .quad   typeinfo for A
typeinfo name for B:
        .string "1B"
typeinfo for A:
        .quad   vtable for __cxxabiv1::__class_type_info+16
        .quad   typeinfo name for A
typeinfo name for A:
        .string "1A"

*/