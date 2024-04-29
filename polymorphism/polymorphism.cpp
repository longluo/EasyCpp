#include <stdio.h>

class A {

public:
    int x;
    int y;

};

class B : public A {

public:
    int z;

};


void func1(B &b) {
    A* p = &b;
}


void func2(A &a) {
    B* p = (B *)&a;
}


void func3(B &b) {
    int* p = (int *)&b;
}

/*

func1(B&):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-24], rdi
        mov     rax, QWORD PTR [rbp-24]
        mov     QWORD PTR [rbp-8], rax
        nop
        pop     rbp
        ret
func2(A&):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-24], rdi
        mov     rax, QWORD PTR [rbp-24]
        mov     QWORD PTR [rbp-8], rax
        nop
        pop     rbp
        ret

*/


