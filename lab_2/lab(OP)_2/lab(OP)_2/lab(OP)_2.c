#include <stdio.h>
#include<Windows.h>
#include<math.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("задача-1\n");

	float h = 12.0;
	float g = 9.8;
	float t = sqrt(2 * h / g);
	printf("Предмет выброшен с высоты %f метров\n", h);
	printf("Он коснется земли через %f секунд\n", t);



	printf("задача-2\n");
	float h;
	printf("Ведите высоту в метрах=");
	scanf_s("%f", &h);
	float g = 9.8;
	float t = sqrt(2 * h / g);
	printf("Предмет выброшен с высоты %f метров\n", h);
	printf("Он коснется земли через %f секунд\n", t);
	

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



	printf("задача-5(объем пирамиды)\n");
	printf("\n");
	float a, b, h, v;
	printf("введите стороны основания\n");
	scanf_s("%f%f", &a, &b);
	printf("введите высоту\n");
	scanf_s("%f", &h);
	v = (a * b) / 3 * h;
	printf("%f\n", v );
	printf("\n");


	printf("задача-6(колчество теплоты для нагревания тела)\n");
	float q, c, m, t1, t2;
	printf("введите удельную теплоемкость\n");
	scanf_s("%f", &c);
	printf("введите массу\n");
	scanf_s("%f", &m);
	printf("введите начальную температуру тела\n");
	scanf_s("%f", &t1);
	printf("введите конечную теплоту тела\n");
	scanf_s("%f", &t2);
	q = c * m * (t2 - t1);
	printf("%f\2", q);
	printf("\n");


	printf("задача-7(расчет эластичности спроса)\n");
	float E, q2, q1, p2, p1;
	printf("введите страую величину спроса\n");
	scanf_s("%f", &q1);
	printf("введите новую величину спроса\n");
	scanf_s("%f", &q2);
	printf("введите старую цену\n");
	scanf_s("%f", &p1);
	printf("введите новую цену\n");
	scanf_s("%f", &p2);
	E = ((q2 - q1) / q1) / ((p2 - p1) / p1);
	printf("%f", E);

	
}