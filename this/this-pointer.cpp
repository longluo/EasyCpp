#include <iostream>

class A {
    public:
    A* mFunc() {
        return this;
    }
};

long func(long thisPointer) {
    return thisPointer;
}

int main() {
    A a;
    a.mFunc();
    func((long)&a);
    return 0;
}


/*
A::mFunc():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        pop     rbp
        ret
func(long):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-1]
        mov     rdi, rax
        call    A::mFunc()
        lea     rax, [rbp-1]
        mov     rdi, rax
        call    func(long)
        mov     eax, 0
        leave
        ret
*/


