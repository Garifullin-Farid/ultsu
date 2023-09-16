#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int p;
	printf("поупка кросовок\n");
	printf("Введите цену:");
	scanf_s("%d", &p);
	if (p < 3000) {
		printf("дешево");

	}
	else if (p >= 3000 && p < 6000) {
		printf("нормально");
	}
	else if (p >= 6000 && p < 9000) {
		printf("дорого");
	}
	else
	{
		printf("жарко");
	}

}