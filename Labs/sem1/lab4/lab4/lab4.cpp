/*
Лабораторная работа 3.
Потапов Максим, 91 группа, ПММ.

Задача 16, стр. 51.
Дано натуральное число n.
Найти наименьшее из чисел k^3 * sin(n + k/n), k = 1, 2, ..., n.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    double elem, min_elem;
    do {
        do {
            cout << "Введите натуральное число n или ноль, чтобы выйти из программы: ";
            cin >> n;
            if (n < 0)
                cout << "Некорректный ввод. Повторите попытку." << endl;
            cout << endl;
        } while (n < 0);

        if (n > 0) {
            min_elem = sin(n + 1 / n);
            // Вычисляем значения через цикл и находим минимальное
            for (int k = 2; k <= n; k++) {
                elem = sin(n + k / n) * k * k * k;
                //cout << elem << endl;
                if (elem < min_elem)
                    min_elem = elem;
            }
            cout << "Минимальный элемент = " << min_elem << endl << endl;
        }

    } while (n != 0);

    return 0;
}
