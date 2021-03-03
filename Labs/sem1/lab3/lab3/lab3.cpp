/*
Лабораторная работа 4.
Потапов Максим, 91 группа, ПММ.

Задача 4, стр. 80.
Дан массив из n целых чисел. M - наибольшее, m - наименьшее из них.
Получить в порядке возрастания все целые числа из интервала (m, M), не входящие в исходный массив.
*/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Rus");
    const int size = 50;
    int array[size];
    int n, j, m, M;
    bool no_elements;
    // Ввод числа элементов с проверкой на корректность
    do {
        do {
            cout << "Введите число элементов массива (n <= " << size << ") или ноль, чтобы завершить прогрмамму: ";
            cin >> n;
            if (n < 0 || n > size)
                cout << "Некорректный ввод. Повторите попытку.\n";
        } while (n < 0 || n > size);
        if (n > 0) {
            cout << "Введите элементы массива: ";
            for (int i = 0; i < n; i++)
                cin >> array[i];
            m = array[0];
            M = array[0];
            // Поиск наименьшего и наибольшего элементов
            for (int i = 1; i < n; i++) {
                if (array[i] < m)
                    m = array[i];
                else if (array[i] > M)
                    M = array[i];
            }
            no_elements = true;
            // Перебираем все элементы в интервале (m, M)
            for (int i = m + 1; i < M; i++) {
                // Перебираем все элементы массива и сравниваем с i
                j = 0;
                while (j < n && array[j] != i)
                    j++;
                if (i != array[j]) {
                    no_elements = false;
                    cout << i << " ";
                }
            }
            if (no_elements)
                cout << "Последовательность пуста.";
            cout << endl;
        }
    } while (n != 0);
    return 0;
}

