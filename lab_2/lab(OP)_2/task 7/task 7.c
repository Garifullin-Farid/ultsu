#include <stdio.h>
#include<Windows.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("задача-7(расчет эластичности спроса)\n");
	float E, q2, q1, p2, p1;
	printf("введите страую величину спроса\n");
	scanf_s("%f", &q1);
	printf("введите новую величину спроса\n");
	scanf_s("%f", &q2);
	printf("введите старую цену\n");
	scanf_s("%f", &p1);
	printf("введите новую цену\n");
	scanf_s("%f", &p2);
	E = ((q2 - q1) / q1) / ((p2 - p1) / p1);
	printf("%f", E);


}