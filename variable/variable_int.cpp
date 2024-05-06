int a  = 1;
int b = 2;
static int c = 3;

void write() {
    a = 2;
    b = 3;
    c = 4;
}


/*

a:
        .long   1
b:
        .long   2
c:
        .long   3
write():
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR a[rip], 2
        mov     DWORD PTR b[rip], 3
        mov     DWORD PTR c[rip], 4
        nop
        pop     rbp
        ret

*/

