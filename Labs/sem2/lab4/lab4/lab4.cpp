/*
 Лабораторная работа 2.
 Потапов Максим, 91 группа, ПММ.

 Задача 74.
 Напечатать строку, предварительно преобразовав её.
 d) заменить последовательностью ks первое вхождение x, если такое есть.
*/


#include <iostream>
#include <string>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;


// Просит пользователя ввести строку и изменяет на неё переменную str
void input_string(string& str);

// Заменяет последовательностью ks первое вхождение x в строке str,
// если такое есть. Возвращает новую строку
string parse(string str);

// Вывод в консоль строки result
void print_result(string result);

// Спрашивает у пользователя, нужно ли продолжить работу программы
bool continue_work();


// Просит пользователя ввести строку и изменяет на неё переменную str
void input_string(string &str)
{
    cout << "Введите строку" << endl;
    getline(cin, str, '\n');;
}

// Заменяет последовательностью ks первое вхождение x в строке str,
// если такое есть. Возвращает новую строку
string parse(string str)
{
    int index = str.find('x');
    if (index != string::npos)
        str.replace(index, 1, "ks");
    return str;
}

// Вывод в консоль строки result
void print_result(string result)
{
    cout << endl << "Строка с первым вхождением x, заменённым на ks: " << result << endl << endl;
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
    setlocale(0, "");

    string str;

    do {
        input_string(str);
        print_result(parse(str));
    } while (continue_work());

    return 0;
}
