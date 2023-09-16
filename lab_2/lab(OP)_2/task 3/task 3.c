#include <stdio.h>
#include<Windows.h>

#include<math.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float m;
	int rub;

	printf("Введите площадь квартиры m*m=");
	scanf_s("%f", &m);

	printf("стоймость 1 квадратного метрф квартиры RUb=");
	scanf_s("%d", &rub);
	float price = m * rub;
	 
	printf("Квартира площадью %f m*m по цене %d RUB(m*m) стоит <%10.1f> RUB\n", m, rub, price);


}