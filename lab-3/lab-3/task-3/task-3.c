#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int t;
	printf("Введите температуру");
	scanf_s("%d", &t);
	if (t < 18){
		printf("холодно");
		
	}
	else if (t >= 18 && t < 22) {
		printf("прохладно");
	}
	else if (t >= 22 && t < 26) {
		printf("тепло");
	}
	else 
	{
		printf("жарко");
	}
	
}