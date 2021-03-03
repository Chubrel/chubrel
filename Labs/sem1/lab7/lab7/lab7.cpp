/*
Лабораторная работа 7.
Потапов Максим, 91 группа, ПММ.

Задача 3, стр. 105.
В матрице A(n x n) определить количество строк, упорядоченных по возрастанию.
Использовать подпрограмму проверки упорядоченности строки.
*/


#include <iostream>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;


// Возвращает размер матрицы, введенный пользователем
void input_size(int &n);

// Создание матрицы размера size
void create_matrix(int**& matr, const int size);

// Заполнение матрицы matr размера size вводом пользователя
void input_matrix(int**& matr, const int size);

// Проверяет, возрастают ли элементы массива row размера size
bool is_increasing(const int* const row, const int size);

// Возвращает количество возрастающих строк матрицы matr размера size
int count_increasing(const int** const matr, const int size);

// Удаление матрицы matr размера size
void delete_matrix(int**& matr, const int size);

// Вывод в консоль числа res
void print_result(int res);

// Спрашивает у пользователя, нужно ли продолжить работу программы
bool continue_work();


// Возвращает размер матрицы, введенный пользователем
void input_size(int &n)
{
    do {
        cout << "Введите размер матрицы: ";
        cin >> n;
        if (n <= 0)
            cout << "Некорректный ввод. Повторите попытку.\n";
    } while (n <= 0);
}

// Создание матрицы размера size
void create_matrix(int**& matr, const int size)
{
    matr = new int* [size];

    for (int i = 0; i < size; i++)
        matr[i] = new int[size];
}

// Заполнение матрицы matr размера size вводом пользователя
void input_matrix(int **&matr, const int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> matr[i][j];
}

// Возвращает количество возрастающих строк матрицы matr размера size
int count_increasing(const int **const matr, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (is_increasing(matr[i], size))
            count++;

    return count;
}

// Удаление матрицы matr размера size
void delete_matrix(int **&matr, const int size)
{
    for (int i = 0; i < size; i++)
        delete[] matr[i];

    delete[] matr;
}

// Вывод в консоль числа res
void print_result(int res)
{
    cout << "Количество строк, упорядоченных по возрастанию: " << res << endl << endl;
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

    int n;          // Размер матрицы
    int** matrix;   //
    int count;      // Количество возрастающих строк матрицы matrix

    do
    {
        input_size(n);
        create_matrix(matrix, n);
        input_matrix(matrix, n);
        count = count_increasing(matrix, n);
        delete_matrix(matrix, n);
        print_result(count);
    } while (continue_work());

    return 0;
}

// Проверяет, возрастают ли элементы массива row размера size
bool is_increasing(const int* const row, const int size)
{
    bool flag = true;
    int i = 0;
    while (i < size - 1 && flag)
    {
        flag = row[i] < row[i + 1];
        i++;
    }

    return flag;
}
