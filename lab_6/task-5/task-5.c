
#include <stdio.h>

void main() {
	int i, n,a,a1;
	printf("n = ");
	scanf_s("%d", &n);
	printf("a = ");
	scanf_s("%d", &a);
	a1 = a;
	i = 1;
	do {
		printf("%d ", a);
		i += 1;
		a += a1;
	} while (i <= n);
	return 0;
}