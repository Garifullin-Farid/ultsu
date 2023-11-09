
#include <stdio.h>
#include <Windows.h>



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Гарифуллин Фарид\n");
	printf("Задача 3\n");
	int a, b, c,d,e;
	int p;

	scanf_s("%d%d%d%d%d", &a, &b, &c,&d,&e);
	printf("ввели: %d, %d, %d,%d, %d\n", a, b, c,d,e);
	p = a + b + c*d+e;
	printf("p =  %d\n", p);
}
