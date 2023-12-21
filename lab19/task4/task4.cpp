#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int* pa; //Указатель на массив. 
int n; // Реальное количество элементов в массиве

void Load() {
	// Открытие входного файла
	FILE* fin = fopen("D:\\уник\\ОАиП_(Савельев)\\files(19)\\in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	// Загрузка массива из входного файла
	fscanf(fin, "%d", &n);
	// Выделение памяти под динамический массив
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	// Закрытие входного файла
	fclose(fin);
}
void SaveResult() {
	
	int max = pa[0];
	for (int i = 0; i < n; i++) {
		if (pa[i] > max) {
			max = pa[i];
		}
	}
	int t = (max * 2) / 3;
	// Выяснение, сколько элементов больше ср арифметического
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] >= t) {
			m++;
		}
	}
	// Открытие выходного файла
	FILE* fout = fopen("D:\\уник\\ОАиП_(Савельев)\\files(19)\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] >= t){
			fprintf(fout, "%d ", pa[i]);
		}
	}
	// Закрытие файла
	fclose(fout);
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Hello! It is Task4!\n");

	Load();
	SaveResult();

	free(pa);
}
