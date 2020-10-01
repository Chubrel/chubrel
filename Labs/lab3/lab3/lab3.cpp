/*
Лабораторная работа 3.
Потапов Максим, 91 группа, ПММ.

Задача 4, стр. 80.
Дан массив из n целых чисел. M - наибольшее, m - наименьшее из них.
Получить в порядке возрастания все целые числа из интервала (m, M), не входящие в исходный массив.
*/


#include <iostream>
using std::cin;
using std::cout;

int main()
{
    setlocale(LC_ALL, "Rus");
    const int size = 50;
    int array[size];
    int n;
    // Ввод числа элементов с проверкой на корректность
    do {
        cout << "Введите число элементов массива (<=" << size << "): ";
        cin >> n;
        if (n <= 0 || n > size)
            cout << "Некорректный ввод. Повторите попытку.\n";
    } while (n <= 0 || n > size);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int m = INT16_MAX;
    int M = INT16_MIN;
    // Поиск наименьшего и наибольшего элемента
    for (int i = 0; i < n; i++) {
        if (array[i] < m)
            m = array[i];
        if (array[i] > M)
            M = array[i];
    }
    // Перебираем все элементы от m до M
    for (int i = m + 1; i < M; i++) {
        int j;
        // Перебираем все элементы массива и сравниваем с i
        for (j = 0; j < n && array[j] != i; j++) {}
        if (i != array[j])
            cout << i << " ";
    }
    return 0;
}

