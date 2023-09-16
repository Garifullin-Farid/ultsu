#include <stdio.h>
#include <Windows.h>

void main() {
	int a, b, min, max;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите первое число=");
	scanf_s("%d", &a);
	printf("Введите второе число=");
	scanf_s("%d", &b);
	if (a < b) {
		min = a;
		max = b;
	}
	else
	{
		max = a;
		min = b;
	}
	printf("большее число = %d\n",max);
	printf("меньшее число = %d\n", min);

}