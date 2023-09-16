#include <stdio.h>
#include<Windows.h>

#include<math.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float m;
	int rub;
	float salary;
	

	printf("Введите площадь квартиры m*m=");
	scanf_s("%f", &m);

	printf("Введите зарплату RUB=");
	scanf_s("%f", &salary);

	printf("стоймость 1 квадратного метрф квартиры RUb=");
	scanf_s("%d", &rub);
	float price = m * rub;

	printf("Квартира площадью %f m*m по цене %d RUB(m*m) стоит <%10.1f> RUB\n", m, rub, price);

	int months = price /(salary / 2);
	printf("%d месяцев понадобится чтобы купить квартиру", months);





}