#include <stdio.h>

void main() {
	int summa, procent,year,i=0;
	printf("summa = ");
	scanf_s("%d", &summa);
	printf("procent  = ");
	scanf_s("%d",&procent);
	printf("year  = ");
	scanf_s("%d", &year);
	do {
		printf("%d RUB in %d year\n",summa,i);
		summa += summa*procent/100;
		i += 1;
	} while (i <= year);
}