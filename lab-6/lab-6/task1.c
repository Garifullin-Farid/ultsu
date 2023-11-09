#include <stdio.h>

void main() {
	int i, n;
	printf("n = ");
	scanf_s("%d", &n);

	i = 1;
	do {
		printf("%d ", i);
		i += 1;
	} while (i <= n);
	return 0;
}