#include <iostream>
#include <cmath>
using namespace std;

double func(double, int);
double derivative(double, int);
double derivative_2(double, int);

void left_rectangles(double, double, int, int);
void middle_rectangles(double, double, int, int);

int main() {
    setlocale(LC_ALL, "Russian");
    const double pi = 3.14;

    int i;
    cout << "Введите номер интегрируемой функции" << endl;
    cin >> i;
    if (!(i >= 1 && i <= 7)) {
        cout << "Нет функции с таким номером" << endl;
        return 0;
    }

    int n;
    cout << "Введите количество отрезков, на которые разбивается исходный отрезок" << endl;
    cin >> n;

    double a, b;
    if (i == 1) {
        a = -5; b = 5;
    }
    if (i == 2) {
        a = -pi; b = pi;
    }
    if (i == 3) {
        a = -pi; b = pi;
    }
    if (i == 4) {
        a = -1; b = 3;
    }
    if (i == 5) {
        a = -100; b = 100;
    }
    if (i == 6) {
        a = -pi; b = pi;
    }
    if (i == 7) {
        a = -7; b = 7;
    }

    left_rectangles(a, b, n, i);
    middle_rectangles(a, b, n, i);
    return 0; 
}
void middle_rectangles(double a, double b, int n, int i) {
    double integral_sum = 0;
    double h = (b - a) / n;
    double left = a;
    double R = 0; //Остаточный член
    for (int j = 0; j < n; j++) {
        R += derivative_2(left + h / 2, i);
        integral_sum += func(left + h / 2, i) * h;
        left += h;
    }
    R *= pow(h , 3) / 24;
    cout << endl << "Результаты метода средних прямоугольников:" << endl;
    cout << "Приближенное значение интеграла: " << integral_sum << endl;
    cout << "Остаточный член: " << R << endl;
}
void left_rectangles(double a, double b, int n, int i) {
    double integral_sum = 0;
    double h = (b - a) / n;
    double left = a;
    double R = 0; //Остаточный член
    for (int j = 0; j < n; j++) {
        R += derivative(left + h / 2, i);
        integral_sum += func(left, i) * h;
        left += h;
    }
    R *= pow(h, 2) / 2;
    cout << endl << "Результаты метода левых прямоугольников:" << endl;
    cout << "Приближенное значение интеграла: " << integral_sum << endl;
    cout << "Остаточный член: " << R << endl;
}
double func(double x, int i) {
    if (i == 1) {
        return pow(x, 2);
    }
    if (i == 2) {
        return sin(x) * sin(x);
    }
    if (i == 3) {
        return sin(2 * x) + cos(7 * x) + 8;
    }
    if (i == 4) {
        return 2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24;
    }
    if (i == 5) {
        return log(pow(x, 2) + 1) + sin(x / 3) + 17;
    }
    if (i == 6) {
        return pow(5, x) + sin(x) + x + 11;
    }
    if (i == 7) {
        return pow(x, 5) + 2 * pow(x, 4) + 3 * pow(x, 3) + 4 * pow(x, 2) + 5 * x + 6;
    }
}
double derivative(double x, int i) {
    if (i == 1) {
        return 2 * x;
    }
    if (i == 2) {
        return 2 * sin(x) * cos(x);
    }
    if (i == 3) {
        return 2 * cos(2 * x) - 7 * sin(7 * x);
    }
    if (i == 4) {
        return 8 * pow(x, 3) + 3 * pow(x, 2) + 4 * x + 3;
    }
    if (i == 5) {
        return 2 * x / (pow(x, 2) + 1) + cos(x / 3) / 3;
    }
    if (i == 6) {
        return pow(5, x) * log(5) + cos(x) + 1;
    }
    if (i == 7) {
        return 5 * pow(x, 4) + 8 * pow(x, 3) + 9 * pow(x, 2) + 8 * x + 5;
    }
}
double derivative_2(double x, int i) {
    if (i == 1) {
        return 2;
    }
    if (i == 2) {
        return 2 * (pow(cos(x), 2) - pow(sin(x), 2));
    }
    if (i == 3) {
        return -(4 * sin(2 * x) + 49 * cos(7 * x));
    }
    if (i == 4) {
        return 24 * pow(x, 2) + 6 * x + 4;
    }
    if (i == 5) {
        return 2 / (pow(x, 2) + 1) - 4 * pow(x, 2) / pow((pow(x, 2) + 1), 2) - sin(x / 3) / 9;
    }
    if (i == 6) {
        return pow(5, x) * pow(log(5), 2) - sin(x);
    }
    if (i == 7) {
        return 20 * pow(x, 3) + 24 * pow(x, 2) + 18 * x + 8;
    }
}
