#include <stdio.h>
#include<Windows.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);




	printf("задача-6(колчество теплоты для нагревания тела)\n");
	float q, c, m, t1, t2;
	printf("введите удельную теплоемкость\n");
	scanf_s("%f", &c);
	printf("введите массу\n");
	scanf_s("%f", &m);
	printf("введите начальную температуру тела\n");
	scanf_s("%f", &t1);
	printf("введите конечную теплоту тела\n");
	scanf_s("%f", &t2);
	q = c * m * (t2 - t1);
	printf("%f\2", q);
	printf("\n");


}