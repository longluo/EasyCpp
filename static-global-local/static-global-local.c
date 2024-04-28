#include <stdio.h>

int g_var_a = 1;

void func() {
	static int s_var_b = 2;
	
	int local_var_c = 3;
	
	s_var_b++;
	local_var_c++;
	
	printf("a: %d, %p | b: %2d, %p | c: %d, %p \n", g_var_a, &g_var_a, s_var_b, &s_var_b, local_var_c, &local_var_c);
	
	// func();
}

int main() {
    func();
    return 0;
}


/*
g_var_a:
        .long   1
func:
        push    rbp
        mov     rbp, rsp
        nop
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        mov     eax, 0
        call    func
        mov     eax, 0
        pop     rbp
        ret
*/

