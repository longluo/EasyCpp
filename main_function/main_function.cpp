int main() {
    return 0;
}

int func() {
    return 0;
}


/*

main:
        push    rbp
        mov     rbp, rsp
        mov     eax, 0
        pop     rbp
        ret
func():
        push    rbp
        mov     rbp, rsp
        mov     eax, 0
        pop     rbp
        ret

*/
