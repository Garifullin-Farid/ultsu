﻿#include<stdio.h>
#include <Windows.h>

void print1_10() {
	int a = 1;
	do
	{
		printf("%d ", a);
		a += 1;
	} while (a<=10);
}
void print10_1() {
	int a = 10;
	do
	{
		printf("%d ", a);
		a -= 1;
	} while (a >= 1);
}
void printSOdds() {
	int a = 1;
	int i = 1;
	do
	{
		printf("%d", a);
		a += 2;
		i += 1;
	} while (i<=5);
}
void print100_10_while() {
	int a = 100;
	while (a >= 10) {
		printf("%d " , a);
		a -= 100;
	}
}
void print1000_100_while() {
	int a = 1000;
	while (a >= 100) {
		printf("%d ", a);
		a -= 100;
	}
}
void print_bank_account() {
	int s,n,i=0;
	printf("s = ");
	scanf_s("%i" ,&s);
	printf("n = ");
	scanf_s("%i", &n);
	printf("s = %i", s);
	printf("n = %i\n", n);
	do
	{
		printf("через %i лет: %i\n", i, s);
		s = s + (s * n / 100);
		i++;
	} while (i<=10);
}
void print_task_5() {
	int a = 1000;
	while (a >= 0) {
		printf("%d ", a);
		a -= 5;
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	do
	{
		printf("\n");
		printf("\n");
		printf("Выберете нужную вам операцию:\n");
		printf("1: Вывести числа от 1 до 10\n");
		printf("1: Вывести числа от 10 до 0\n");
		printf("3: Вывести 5 первых нечетных чисел начиная с 1\n");
		printf("11: Вывести числа 100 90 80 ... 10 (через WHILE)\n");
		printf("12: Вывести числа 1000 900 800 ... 100 (через WHILE)\n");
		printf("13: Вывести  состояние счета\n");
		printf("20: Вывести  числа от 1000 до 0 с шагом 5\n");
		printf("\n");
		printf("0:выйти из программы\n");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			print10_1();
			break;
		case 2:
			print1_10();
			break;
		case 3:
			printSOdds();
			break;

		case 11:
			print100_10_while();
			break;
		case 12:
			print1000_100_while();
			break;
		case 13:
			print_bank_account();
			break;
		
		case 20:
			print_task_5();
			break;
		}
	

	} while (n!=0);

}