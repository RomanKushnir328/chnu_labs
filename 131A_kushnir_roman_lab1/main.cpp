#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int MY_DEFAULT_PRECISION = 3;
    const string TXT_F_EQ_TO = "f = ";
    float x, f;
    int n;

    system("clear");

    cout << "x = ";
    cin >> x;

    cout << "n = ";
    cin >> n;

    f = fabs((sin(3*x+M_PI_2)-1) / (sin(5*x-M_PI_2)+1));
    f += tan(pow(n, 2)) + log10(x+1);

    cout << endl << "Result is:\n";
    cout << "'as is'\t\t\t" << TXT_F_EQ_TO << f << endl;
    cout << setprecision(MY_DEFAULT_PRECISION);
    cout << "fixed format\t\t" << TXT_F_EQ_TO << fixed << f << endl;
    cout << "scientific format\t" <<  TXT_F_EQ_TO << scientific << f << endl;

    return 0;
}