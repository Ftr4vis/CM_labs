#include <iostream>
#include <math.h>
using namespace std;
double equation(double, int);
int main() {
	setlocale(LC_ALL, "Russian");
	const double pi = 3.1415926535;
	int n;
	cout << "Введите номер уравнения" << endl;
	cin >> n;
	if (!(n >= 1 && n <= 5)){
		cout << "Нет уравнения с таким номером" << endl;
		return 0;
	}
	double left_bound, right_bound;
	cout << "Введите границы отрезка" << endl;
	cin >> left_bound >> right_bound;
	double e;
	cout << "Введите точность решения" << endl;
	cin >> e;
	if (!((equation(left_bound, n) * equation(right_bound, n)) < 0)) {
		cout << "Границы отрезка не удовлетворяют условиям метода" << endl;
		return 0;
	}
	if ((n == 4) && !(left_bound >= 0 && right_bound <= 2 * pi)){
		cout << "Границы отрезка не удовлетворяют условиям задания" << endl;
		return 0;
	}

	int iterations = 0;
	double prev_solution, solution; //Приближенные корни
	do {
		prev_solution = solution;
		solution = left_bound - (equation(left_bound, n) / (equation(right_bound, n) - equation(left_bound, n))) * (right_bound - left_bound);
		iterations++;
		if(equation(solution, n) == 0) {
			goto END; //График функции - прямая
		}
		if (equation(left_bound, n) * equation(solution, n) < 0) {
			right_bound = solution;
		}
		else {
			left_bound = solution;
		}
	} while (fabs(prev_solution - solution) > e);
	END:
	cout << "Корень уравнения: x = " << solution << endl;
	cout << "Количество итераций: " << iterations << endl;
	cout << "Проверка решения: f(solution) = " << equation(solution,n) << endl; 
	return 0;
}
double equation(double x, int n) {
	if (n == 1) {
		return pow(5, x) * sqrt(pow(8, x - 1)) - 189;
	}
	if (n == 2) {
		return pow(x, 3) - pow(x, 2) + 2 * x - 5;
	}
	if (n == 3) {
		return 2 * log10(pow(x, 2)) - 5 * pow(log10(x), 2) - 4;
	}
	if (n == 4) {
		return 2 * sin(2 * x) - cos(3 * x) - 0.5;
	}
	if (n == 5) {
		return 2 * pow(x, 3) - 7 * pow(x, 2) - 7 * x - 2.5;
	}
}
