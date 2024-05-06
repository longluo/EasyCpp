int a  = 1;

void write() {
    a = 2;
}


/*

a:
        .long   1
write():
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR a[rip], 2
        nop
        pop     rbp
        ret

*/

