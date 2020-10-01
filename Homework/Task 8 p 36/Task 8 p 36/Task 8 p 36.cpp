#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    double x, y, r, fi;
    setlocale(0, "");
    cout << "Введите координаты x и y.\n";
    cin >> x >> y;
    r = sqrt(x * x + y * y);
    if (x > 0)
        if (y >= 0) fi = atan(y / x);
        else fi = 2 * M_PI + atan(y / x);
    else if (x == 0)
        if (y > 0) fi = M_PI / 2;
        else if (y < 0) fi = 1.5 * M_PI;
        else fi = 0;
    else fi = M_PI + atan(y / x);

    cout << "Полярные координаты точки: (" << r << ", " << fi << ")";
}