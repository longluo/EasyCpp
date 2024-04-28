#include <stdio.h>

volatile const int a = 1; // store in read only page.
int b = 1;

int func1() {
    *(int *)&a = 1;
    return a;
}


int func2() {
    b = 1;
    return b;
}

// stack
int func3() {
    const int c = 2;
    *(int *)&c = 3;
    return c;
}


int main() {
	printf("a: %p b: %p \n", &a, &b);

    func1(); // protect by MMU
    func2(); 
    func3(); 

    return 0;
}
