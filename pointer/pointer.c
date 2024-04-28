#include <stdio.h>

void func() {
    char *a[] = {"abc", "def", "hij"};
    char **p = a;
	
	printf("output：%c \n", *(a[2] + 1));
	printf("output：%c \n", a[2][1]);
    printf("output：%c \n", *(p[2] + 1));
	printf("output：%c \n", *(*(p + 2) + 1));
}

int main() {
    func();
    return 0;
}


