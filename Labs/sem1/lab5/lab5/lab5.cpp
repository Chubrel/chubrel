/*
Лабораторная работа 5.
Потапов Максим, 91 группа, ПММ.

Задача 50, стр. 76.
Дана последовательность элементов.
Увеличить её, вставив после каждого минимального элемента максимальный.
*/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "ru");
    int size, j, count_min, min_el, max_el;
    do {
        do {
            cout << "Введите число элементов массива или 0, чтобы выйти из программы: ";
            cin >> size;
            if (size < 0)
                cout << "Число элементов массива не должно быть отрицательным!" << endl;
        } while (size < 0);
        if (size != 0) {
            cout << "Введите элементы массива\n";
            int* array = new int[size];
            for (int i = 0; i < size; i++)
                cin >> array[i];
            // Ищем наименьший и наибольший элементы. Считаем количество минимальных элементов.
            min_el = array[0];
            max_el = array[0];
            count_min = 1;
            for (int i = 1; i < size; i++) {
                if (array[i] < min_el) {
                    min_el = array[i];
                    count_min = 1;
                }
                else if (array[i] == min_el)
                    count_min++;
                else if (array[i] > max_el)
                    max_el = array[i];
            }
            // Создаём увеличенный массив, в который поместятся все новые элементы.
            int* new_array = new int[size + count_min];

            // Помещаем все старые элементы в новый массив,
            // вставляя после каждого минимального
            // элемента максимальный.
            
            // j отвечает за индексы в новом массиве.
            j = 0;
            for (int i = 0; i < size; i++) {
                new_array[j] = array[i];
                j++;
                if (array[i] == min_el) {
                    new_array[j] = max_el;
                    j++;
                }
            }
            delete[] array;
            // Вывод нового массива.
            for (int i = 0; i < size + count_min; i++)
                cout << new_array[i] << " ";
            cout << endl;
            delete[] new_array;
        }
    } while (size != 0);
    return 0;
}
