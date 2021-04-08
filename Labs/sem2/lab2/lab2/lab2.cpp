/*
 Лабораторная работа 2.
 Потапов Максим, 91 группа, ПММ.

 Задача 11.
 Написать функцию nonalpha, которая получает параметр str
 и возвращает позицию 1-й литеры, не являющейся прописной
 или строчной буквой латинского или русского алфавитов.
 Например, nonalpha("stew7m") даёт 5.
*/

#include <iostream>
//#include <cstring>
#include <Windows.h>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;


// Просит пользователя ввести строку и изменяет на неё переменную s
void input_string(char* s);

/* Возвращает позицию 1-й литеры (индексы нумеруются с 1),
   не являющейся прописной или строчной буквой
   латинского или русского алфавитов.
   Если все символы - буквы, то возвращает 0. */
int nonalpha(char* str);

/* Проверяет, является ли симво лпрописной или строчной
   буквой латинского или русского алфавитов. */
bool isletter(char c);

// Вывод в консоль результата
void print_result(const int result);

// Спрашивает у пользователя, нужно ли продолжить работу программы
bool continue_work();


// Просит пользователя ввести строку и изменяет на неё переменную s
void input_string(char* s)
{
    cout << "Введите строку" << endl;
    cin >> s;
}

/* Возвращает позицию 1-й литеры (индексы нумеруются с 1),
   не являющейся прописной или строчной буквой
   латинского или русского алфавитов.
   Если все символы - буквы, то возвращает 0. */
int nonalpha(char* str)
{
    int i = 0;
    bool flag = true;
    while (flag && str[i] != '\0') {
        flag = isletter(str[i]);
        i++;
    }
    int result = 0;
    if (!flag)
        result = i;
    return result;
}

/* Проверяет, является ли симво лпрописной или строчной
   буквой латинского или русского алфавитов. */
bool isletter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
           (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') ||
            c == 'ё' || c == 'Ё';
}

// Вывод в консоль результата
void print_result(const int result)
{
    if (result)
        cout << endl << "Первый символ, не являющийся буквой, находится на позиции " << result << endl << endl;
    else
        cout << endl << "Все символы являются буквами" << endl << endl;
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[255];

    do {
        input_string(s);
        print_result(nonalpha(s));
    } while (continue_work());

    return 0;
}
