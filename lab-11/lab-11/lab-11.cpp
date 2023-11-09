#include<stdio.h>
#include <Windows.h>

void task1() {
	int i=1,j=1;
	do
	{	
		i = 1;
		do
		{
			printf("%i%i ", j, i);
			i += 1;
		} while (i<=5);
		printf("\n");
		j++;
	} while (j <= 5);
}
void task2() {
	int i = 1, j = 1;
	do
	{
		i = 1;
		do
		{
				printf("%3i ", i*j);
			i += 1;
		} while (i <= 5);
		printf("\n");
		j++;
	} while (j <= 10);
}
void task3() {
	int i = 1, j = 1;
	do
	{
		i = j-1;
		printf("%i ", j);
		while (i >= 1)
		{
			printf("%i ",i);
			i -= 1;
		} 
		printf("\n");
		j++;
	} while (j <= 5);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	do
	{
		printf("\n");
		printf("\n");
		printf("Выберете нужную вам операцию:\n");
		printf("1: task1\n");
		printf("2: task2\n");
		printf("3: task3\n");
		printf("\n");
		printf("0:выйти из программы\n");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;

		}


	} while (n != 0);

}