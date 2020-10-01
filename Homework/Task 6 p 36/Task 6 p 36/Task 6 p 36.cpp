#include <iostream>
using namespace std;

int main()
{
    double x, y, min, max;
    setlocale(0, "");
    cout << "Введите числа x и y.\n";
    cin >> x >> y;

    if (x > y) {
        min = y;
        max = x;
    }
    else {
        min = x;
        max = y;
    }

    double z = (min + 0.5) / (1 + max * max);
    cout << "Полученное число Z = " << z;
}