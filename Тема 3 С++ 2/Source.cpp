#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std; // Использование пространства имен std

// Функция для интегрирования
double g(double x) {
    return exp(-2 * x) * sin(6 * x);
}

// Метод прямоугольников
double rectangleMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += g(a + i * h);
    }
    return sum * h;
}

// Метод трапеций
double trapezoidalMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (g(a) + g(b));
    for (int i = 1; i < n; ++i) {
        sum += g(a + i * h);
    }
    return sum * h;
}

// Метод Симпсона
double simpsonMethod(double a, double b, int n) {
    if (n % 2 == 1) n++; // Симпсон требует четного количества отрезков
    double h = (b - a) / n;
    double sum = g(a) + g(b);
    for (int i = 1; i < n; ++i) {
        sum += (i % 2 == 0) ? 2 * g(a + i * h) : 4 * g(a + i * h);
    }
    return sum * h / 3.0;
}

int main() {
    setlocale(LC_ALL, "ru"); // Установка локали на русский язык

    double a = 0.0; // Нижний предел интегрирования
    double b = 1.0; // Верхний предел интегрирования
    int n = 1000; // Количество отрезков

    cout << setprecision(10);
    cout << "Метод прямоугольников: " << rectangleMethod(a, b, n) << endl;
    cout << "Метод трапеций: " << trapezoidalMethod(a, b, n) << endl;
    cout << "Метод Симпсона: " << simpsonMethod(a, b, n) << endl;

    return 0;
}
