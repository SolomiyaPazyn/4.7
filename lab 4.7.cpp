#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(18) << "ln((1+x)/(1-x))" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = x;
        S = 2 * a;
        do {
            n++;
            R = (2 * n - 1) * pow(x, 2) / (2 * n + 1);
            a *= R;
            S += 2 * a;
        } while (abs(2 * a) >= eps);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(18) << setprecision(10) << log((1 + x) / (1 - x)) << " |"
            << setw(10) << setprecision(5) << S << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}