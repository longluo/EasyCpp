#include <stdio.h>

int g_a = 1;
static int s_b = 2;

// 未初始化或者初始化为0，都存储在未初始化字段中。
int g_c;
int g_d = 0;

static int s_e;
static int s_f = 0;


int main() {
	printf("%p, %p, \n\n%p, %p, %p, %p\n", &g_a, &s_b, &g_c, &g_d, &s_e, &s_f);
    return 0;
}

