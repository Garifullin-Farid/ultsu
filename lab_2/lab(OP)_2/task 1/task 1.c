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


}