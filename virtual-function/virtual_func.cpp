#include <iostream>

class A {
    public:
    int a;

    int func() {
        return this->a;
    }

    virtual int vfunc() {
        return a;
    }

    A() {
        a = 1;
    }
};


void call_func(A* a) {
    a->func();
}


void call_vfunc(A* a) {
    a->vfunc();
}

int main() {
    A b;
    return 0;
}


/*

A::func():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax+8]
        pop     rbp
        ret
A::vfunc():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax+8]
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
call_func(A*):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    A::func()
        nop
        leave
        ret
call_vfunc(A*):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax]
        mov     rdx, QWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    rdx
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-16]
        mov     rdi, rax
        call    A::A() [complete object constructor]
        mov     eax, 0
        leave
        ret
vtable for A:
        .quad   0
        .quad   typeinfo for A
        .quad   A::vfunc()
typeinfo for A:
        .quad   vtable for __cxxabiv1::__class_type_info+16
        .quad   typeinfo name for A
typeinfo name for A:
        .string "1A"

*/

