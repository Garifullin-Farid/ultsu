#include <stdio.h>

void main() {
	int i, stepen,n;
	printf("n = ");
	scanf_s("%d",&n);
	stepen = 1;
	i = 0;
	do {
		printf("7^%d = %d\n", i, stepen);
		stepen *= 7;
		i += 1;
	} while (i <= n);
}