#include <stdio.h>

void main1() {
	int i, stepen;
	stepen = 1;
	i = 0;
	do {
		printf("2^%d = %d\n", i,stepen);
		stepen *= 2;
		i += 1;
	} while (i <= 5);
}