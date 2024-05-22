#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std; // ������������� ������������ ���� std

// ������� ��� ��������������
double g(double x) {
    return exp(-2 * x) * sin(6 * x);
}

// ����� ���������������
double rectangleMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += g(a + i * h);
    }
    return sum * h;
}

// ����� ��������
double trapezoidalMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (g(a) + g(b));
    for (int i = 1; i < n; ++i) {
        sum += g(a + i * h);
    }
    return sum * h;
}

// ����� ��������
double simpsonMethod(double a, double b, int n) {
    if (n % 2 == 1) n++; // ������� ������� ������� ���������� ��������
    double h = (b - a) / n;
    double sum = g(a) + g(b);
    for (int i = 1; i < n; ++i) {
        sum += (i % 2 == 0) ? 2 * g(a + i * h) : 4 * g(a + i * h);
    }
    return sum * h / 3.0;
}

int main() {
    setlocale(LC_ALL, "ru"); // ��������� ������ �� ������� ����

    double a = 0.0; // ������ ������ ��������������
    double b = 1.0; // ������� ������ ��������������
    int n = 1000; // ���������� ��������

    cout << setprecision(10);
    cout << "����� ���������������: " << rectangleMethod(a, b, n) << endl;
    cout << "����� ��������: " << trapezoidalMethod(a, b, n) << endl;
    cout << "����� ��������: " << simpsonMethod(a, b, n) << endl;

    return 0;
}
