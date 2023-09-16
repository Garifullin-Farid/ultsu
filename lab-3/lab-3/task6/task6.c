#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int v;
	printf("Скоростные ограничения ПДД для легкового автомобиля\n");
	printf("Введите скорость:");
	scanf_s("%d", &v);
	if (v < 20) {
		printf("медленно");

	}
	else if (v >= 20 && v < 60) {
		printf("нормально");
	}
	else if (v >= 60 && v < 90) {
		printf("быстро");
	}
	else
	{
		printf("очень быстро");
	}

}