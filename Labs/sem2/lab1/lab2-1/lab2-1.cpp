/*
 Лабораторная работа 1.
 Потапов Максим, 91 группа, ПММ.
 
 Задача 6, стр. 112.
 Для заданных границ интегирирования a и b вычислить значение определённого интеграла следующего вида:
 c) integral(dx / sin(x) ^ n) =
    x, n = 0
    ln(tg(x / 2)), n = 1
    -1 / (n - 1)) * (cos(x) / sin(x) ^ (n - 1)) + ((n - 2) / (n - 1)) * integral(dx / sin(x) ^ (n - 2)), n >= 2
*/


#include <iostream>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;


// Ввод степени синуса
int input_n();

// Ввод первой границы интегрирования
double input_a();

// Ввод второй границы интегрирования
double input_b();

// Рекурсивное вычисление заданного интеграла
double integrate(double x, int n);

// Вывод в консоль результата вычислений
void print_result(double result);

// Спрашивает у пользователя, нужно ли продолжить работу программы
bool continue_work();


// Ввод степени синуса
int input_n()
{
    int n;
    do {
        cout << "Введите целую неотрицательную степень синуса: ";
        cin >> n;
        if (n < 0)
            cout << "Некорректный ввод. Повторите попытку.\n";
    } while (n < 0);
    return n;
}

// Ввод первой границы интегрирования
double input_a()
{
    double x;
    cout << "Введите первую границу интегрирования: ";
    cin >> x;
    return x;
}

// Ввод второй границы интегрирования
double input_b()
{
    double x;
    cout << "Введите вторую границу интегрирования: ";
    cin >> x;
    return x;
}

// Рекурсивное вычисление заданного интеграла
double integrate(double x, int n)
{
    if (n == 0) return x;

    else if (n == 1) return log(tan(x / 2));

    else {
        const double sin_x = sin(x);
        double sin_n = 1;  // sin(x) ^ (n - 1)
        for (int i = 1; i < n; i++)
            sin_n *= sin_x;
        return (-1. / (n - 1.)) * (cos(x) / sin_n) + ((n - 2.) / (n - 1.)) * integrate(x, n - 2);
    }
}

// Вывод в консоль результата вычислений
void print_result(double result)
{   
    // С помощью встроенной функции определяем,
    // "хорошее" ли значение находится в переменной result,
    // где может находиться inf или nan(ind)
    if (isnormal(result))
        cout << endl << "Результат интегрирования: " << result << endl << endl;
    else
        cout << endl << "Значение результата интегрирования не определено" << endl << endl;
}

// Спрашивает у пользователя, нужно ли продолжить работу программы
bool continue_work()
{
    char ch;

    do {
        cout << "Хотите продолжить работу программы? y/n: ";
        ch = _getche();
        cout << endl;
    } while (ch != 'y' && ch != 'n');
    cout << endl;

    return ch == 'y';
}


int main()
{
    setlocale(LC_ALL, "ru");
    
    // const double PI = 3.14159265358979323846;

    double a, b;    // Границы интегрирования
    int n;          // Степень синуса

    do {
        n = input_n();
        a = input_a();
        b = input_b();
        print_result(integrate(b, n) - integrate(a, n));

    } while (continue_work());

    return 0;

}
