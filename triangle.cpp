#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int checkTrgl(int firstSd, int secondSd, int thirdSd) { //сверка подходящих сторон
	vector <int> sumSds = {firstSd + secondSd, firstSd + thirdSd, secondSd + thirdSd };
	for (int i = 0; i < 3; i++) {
		if (firstSd >= sumSds[i] || secondSd >= sumSds[i] || thirdSd >= sumSds[i]) { //если хоть 1 сторона больше суммы двух других - это не треугольник
			return 0;
		}
	}
	return 1;
}
int checkSds(int firstSd, int secondSd, int thirdSd) { //проверка на равнобедренность
	if (firstSd == secondSd || firstSd == thirdSd || secondSd == thirdSd) {
		return 1;
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int firstSd, secondSd, thirdSd;
	bool isTrue = 1;
	while (isTrue) { //пользователь вводит значения сторон до тех пор, пока это не окажется треугольником
		cout << "Введите через пробел длины трёх сторон треугольника" << endl;
		cin >> firstSd >> secondSd >> thirdSd;

		if (checkTrgl(firstSd, secondSd, thirdSd)) {
			isTrue = 0;
		}
	}
	float prmtr = firstSd + secondSd + thirdSd;
	float halfPrmtr = prmtr / 2; 
	cout << "периметр вашего треугольника = " << prmtr << endl;
	cout << "площадь по формуле Герона = " << pow(halfPrmtr * (halfPrmtr - firstSd) * (halfPrmtr - secondSd) * (halfPrmtr - thirdSd), 0.5) << endl; //формула герона
	cout << "равнобедренный ли ваш треугольник? - " << (checkSds(firstSd, secondSd, thirdSd) ? "Да" : "Нет") << endl;
}
