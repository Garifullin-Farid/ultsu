
#include <stdio.h>

void main() {
	int n,i,m;
	printf("n = ");
	scanf_s("%d", &n);
	i = 2;
	m = 1;
	do {
		printf("%d ", i);
		i+=2;
		m += 1;
	} while (m <= n);
	return 0;
}