/*
Лабораторная работа 6.
Потапов Максим, 91 группа, ПММ.

Задача 77c, стр. 92.
Дана последовательность из 2-30 слов, в каждом из которых 2-10 строчных латинских букв.
Между соседними словами не менее одного пробела, за последним словом - точка.
Напечатать все слова, отличные от первого,
предварительно преобразовав каждое из них по следующему правилу:
c) Удалить из слова первую букву.
*/


#include <iostream>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;


int main()
{
    setlocale(LC_ALL, "ru");

    const int rows = 30;
    const int cols = 10;

    int k;

    bool flag;

    char ch, exit;

    // Массив для подсчёта символов в словах
    int count[rows];

    // Матрица, в которой сохраняются отдельные слова
    char a[rows][cols];
    
    do {
        // Заполнение целочисленного массива -1
        for (int i = 0; i < rows; i++)
            count[i] = 0;

        // Ввод матрицы
        cout << "Введите предложение\n";
        k = -1;
        do {
            ch = _getche();
            flag = ch != ' ' && ch != '.';
            if (flag) {
                k++;
            }
            while (flag && count[k] < cols) {
                a[k][count[k]] = ch;
                count[k]++;
                ch = _getche();
                flag = ch != ' ' && ch != '.';
            }
        } while (ch != '.' && k < rows - 1);

        // Обработка матрицы (удаление из слов первой буквы)
        for (int i = 0; i < rows; i++)
        {
            count[i]--;
            for (int j = 0; j < count[i]; j++)
                a[i][j] = a[i][j + 1];
        }

        //Условный вывод строк матрицы (начиная со 2-го слова)
        cout << endl << endl << "Новое предложение" << endl;
        for (int i = 1; i < rows; i++)
        {
            // Сравниваем длину слов
            if (count[0] != count[i])
                flag = true;
            else {
                // Если длина слов одинаковая, сравниваем все символы
                flag = false;
                k = 0;
                while (k < count[i] && !flag) {
                    flag = a[0][k] != a[i][k];
                    k++;
                }
            }
            if (flag) {
                for (int j = 0; j < count[i]; j++)
                    cout << a[i][j];
                cout << " ";
            }
        }
        cout << endl << endl;

        do {
            cout << "Хотите завершить программу? y/n: ";
            exit = _getche();
            cout << endl;
        } while (exit != 'y' && exit != 'n');
        cout << endl;

    } while (exit == 'n');
}
