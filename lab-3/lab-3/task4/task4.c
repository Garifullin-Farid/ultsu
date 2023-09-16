#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int t;
	printf("Местность:Париж\n");
	printf("Сезон:Зима\n");
	printf("Введите температуру:");
	scanf_s("%d", &t);
	if (t < 4) {
		printf("холодно");

	}
	else if (t >= 4 && t < 6) {
		printf("прохладно");
	}
	else if (t >= 6 && t < 8) {
		printf("тепло");
	}
	else
	{
		printf("жарко");
	}

}