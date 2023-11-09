
#include <stdio.h>
#include <Windows.h>



void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Гарифуллин Фарид\n");
	printf("Задача 1\n");
	int a, b, c;
	int p;

	scanf_s("%d%d%d", &a, &b, &c);
	printf("ввели: %d, %d, %d\n", a, b, c);
	p = a * b * c;
	printf("p =  %d\n", p);
}
