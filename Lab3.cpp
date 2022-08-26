#include <iostream>
#include <cmath>
using namespace std;
bool eps_check(double*, double*, int, double);
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размерность матрицы коэффициентов A" << endl;
	cin >> n;
	double** A = new double* [n];
	cout << "Введите элементы матрицы коэффициентов A" << endl;
	for (int i = 0; i < n; i++) {
		A[i] = new double[n];
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
		if (A[i][i] == 0) {
			cout << "Диагональные элементы должны быть отличны от нуля!" << endl;
			return 0;
		}
	}
	cout << "Введите элементы столбца B" << endl;
	double* B = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	double** Alpha = new double* [n];
	double* Beta = new double[n];
	for (int i = 0; i < n; i++) {
		Alpha[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Alpha[i][j] = -A[i][j] / A[i][i];
		}
		Beta[i] = B[i] / A[i][i];
		Alpha[i][i] = 0;
	}
	double* x = new double[n];
	double* x_prev = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = Beta[i];
	}
	double eps;
	cout << "Задайте точность вычислений" << endl;
	cin >> eps;
	double mul;
	int iterations = 0;
	do {
		for (int i = 0; i < n; i++) {
			x_prev[i] = x[i];
			mul = 0;
			for (int k = 0; k < n; k++) {
				mul += Alpha[i][k] * x[k];
			}
			x[i] = Beta[i] + mul;
		}
		iterations++;
	} while (!(eps_check(x_prev, x, n, eps)));
	cout << "Решение:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i << " = " << x[i] << endl;
	}
	cout << "Количество итераций: " << iterations << endl;
	cout << "Проверка решения подстановкой:" << endl;
	double resi;
	for (int i = 0; i < n; i++) {
		resi = 0;
		for (int j = 0; j < n; j++) {
			resi += x[j] * A[i][j];
		}
		cout << "Уравнение " << i << ": " << resi << " " << "B" << i << " = " << B[i] << endl;;
	}
	for (int i = 0; i < n; i++) {
		delete[] A[i];
		delete[] Alpha[i];
	}
	delete[] B;
	delete[] Beta;
	return 0;
}
bool eps_check(double* x_prev, double* x, int dimension, double eps) {
	double norma_x;
	norma_x = 0; // k-норма
	for (int i = 0; i < dimension; i++) {
		norma_x += pow(abs(x_prev[i] - x[i]), 2);
	}
	norma_x = sqrt(norma_x);
	if (norma_x < eps) return 1;
	else return 0;
}
