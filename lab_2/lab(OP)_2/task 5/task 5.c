#include <stdio.h>
#include<Windows.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	printf("задача-5(объем пирамиды)\n");
	printf("\n");
	float a, b, h, v;
	printf("введите стороны основания\n");
	scanf_s("%f%f", &a, &b);
	printf("введите высоту\n");
	scanf_s("%f", &h);
	v = (a * b) / 3 * h;
	printf("%f\n", v);
	printf("\n");


}