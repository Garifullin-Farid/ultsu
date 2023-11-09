#include <stdio.h>
#include<Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
	int i = 0;
	while (i < n) {
		printf("%d ",arr[i]);
		i++;
	}
};

void keyboardInput() {
	printf("n= ");
	scanf_s("%d", & n);
	printf("input %d values:", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}
void oddsX10() {
	int i = 0;
	while (i < n) {
		if (arr[i]%2 == 1)
		{
			arr[i] = arr[i] * 10;
		}
		
		i++;
	}
}
int findMin() {
	int i = 0;
	int min = arr[i];
	while (i < n) {
		if (min > arr[i])
		{
			min = arr[i];
		}
		i++;
	}
	return min;
}
findIndexMin() {
	int min = arr[0];
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			c = i;
		}
	}
	return c;
}
int MoreThan10(){
	int score = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 10){
			score++;
		}
	}
	return score;
}
int findLastEven() {
	int c;
	for (int i = n-1; i >=0; i-=1)
	{
		if (arr[i]%2 == 0) {
			c = i;
			return i;
			break;
		}
		
	}
}
void evenNumbers1() {
	int i = 0;
	while (i < n) {
		if (arr[i] % 2 == 0)
		{
			arr[i] = arr[i] * -1;
		}
		i++;
	}
}
void replace() {
	int i = 0;
	while (i < n) {
		if (arr[i]  <= 4)
		{
			arr[i] = 4;
		}
		i++;
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do
	{
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов < 10\n");
		printf("5: x2 для последнего четного\n");
		printf("6: сколько четных левее мнимального\n");
		printf("7: Все четные на -1\n");
		printf("8: все меньше 4 заменить на 4\n");

		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);
		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		case 4:
		{
			int score = MoreThan10();
			printf("%d Элементов больше чем 10\n", score);
		}
		case 5:
		{
			int index = findLastEven();
			if (index>=0) {
				arr[index] *= 2;
			}
		}
		case 6: {
			int index = findIndexMin();
			int cnt = 0;
			for (int i = 0; i < index; i++)
			{
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("Левее минимального %d элементов четных",cnt);
		}
		case 7:
			evenNumbers1();
			break;
		case 8:
			replace();
			break;

		

		break;
		}
	} while (item!= 0);
}