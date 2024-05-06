short a  = 1;
short b = 2;
static short c = 3;

void write() {
    a = 2;
    b = 3;
    c = 4;
}


/*

a:
        .value  1
b:
        .value  2
c:
        .value  3
write():
        push    rbp
        mov     rbp, rsp
        mov     WORD PTR a[rip], 2
        mov     WORD PTR b[rip], 3
        mov     WORD PTR c[rip], 4
        nop
        pop     rbp
        ret

*/

