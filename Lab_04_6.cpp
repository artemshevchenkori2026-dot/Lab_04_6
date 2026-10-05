#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

int main()
{
    double P, S;
    int k, i;

    cout << fixed << setprecision(10);

    // 1 Спосіб: while (...) { ... while(...) {...} ... }
    P = 1.0;
    k = 1;
    while (k <= 15)
    {
        S = 0.0;
        i = 1;
        while (i <= k)
        {
            S += (i + 1);
            i++;
        }
        P *= sqrt(1.0 + S * S) / (1.0 + S);
        k++;
    }
    cout << "1) while - while:   P = " << P << endl;

    // 2 Спосіб: do { ... do {...} while(...); ... } while(...);
    P = 1.0;
    k = 1;
    do
    {
        S = 0.0;
        i = 1;
        do
        {
            S += (i + 1);
            i++;
        } while (i <= k);

        P *= sqrt(1.0 + S * S) / (1.0 + S);
        k++;
    } while (k <= 15);
    cout << "2) do - do while:   P = " << P << endl;

    // 3 Спосіб: for (...; ...; k++) { ... for (...; ...; i++) {...} ... }
    P = 1.0;
    for (k = 1; k <= 15; k++)
    {
        S = 0.0;
        for (i = 1; i <= k; i++)
        {
            S += (i + 1);
        }
        P *= sqrt(1.0 + S * S) / (1.0 + S);
    }
    cout << "3) for (++) - for (++): P = " << P << endl;

    // 4 Спосіб: for (...; ...; k--) { ... for (...; ...; i--) {...} ... }
    P = 1.0;
    for (k = 15; k >= 1; k--)
    {
        S = 0.0;
        for (i = k; i >= 1; i--)
        {
            S += (i + 1);
        }
        P *= sqrt(1.0 + S * S) / (1.0 + S);
    }
    cout << "4) for (--) - for (--): P = " << P << endl;

    return 0;
}