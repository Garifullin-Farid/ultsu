﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Гарифуллин Фарид\n");
	printf("Задача 1\n");
	int a, b, c,d,e;
	int p;

	FILE* fin = fopen("D:\\уник\\ОАиП_(Савельев)\\files\\in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	fclose(fin);
	printf("ввели: %d, %d, %d,%d, %d\n", a, b, c,e,d);

	p = a + b + c+d+e;
	printf("p =  %d\n", p);
	FILE* fout = fopen("D:\\уник\\ОАиП_(Савельев)\\files\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	fprintf(fout, "%d", p);
	fclose(fout);

}
