#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib> 

using namespace std;

const string ERR_MSG_INCORRECT_ENTERED_VALUE = "\nНевірно введене значення ";
const string ERR_MSG_PROGRAM_STOP = "\nПрограму буде завершено";
const int DISPLAYING_PRECISION_MIN = 2, DISPLAYING_PRECISION_MAX = 6;

float func(int a, float x);
void validateDisplayingPrecision(int precision);
void printResult(float y, char viewKind, int precision);
float ctg(float x);
float log3(float x);

int main(){
    const int A_MIN = -20, A_MAX = 10;
    const string TXT_ENTER = "\nВведіть ";
    float f, x;
    int a, displayingPrecision;
    char viewKind;

    system("clear");

    cout << TXT_ENTER << "число x, x=";
    cin >> x;

    cout << TXT_ENTER << "ціле число 'a' в межах від " << A_MIN << " до " << A_MAX << ", a=";
    cin >> a;

    if( a < A_MIN || a > A_MAX ) {
        cout << ERR_MSG_INCORRECT_ENTERED_VALUE << "змінної 'a'";
        cout << ERR_MSG_PROGRAM_STOP;
        return 0; 
    }

    cout << TXT_ENTER
         << "кількість значущих цифр після десяткового розділового знака при відображенні результату розрахунку";
    cout << "(ціле число від " << DISPLAYING_PRECISION_MIN << " до " << DISPLAYING_PRECISION_MAX << " ):";
    cin >> displayingPrecision;

    validateDisplayingPrecision(displayingPrecision);

    cout << TXT_ENTER << "один символ що відповідає необхідному Вам вигляду результату:\n";
    cout << " 'g' - науковий (scientific)\n";
    cout << " 'h' - фіксований (fixed)\n";
    cin >> viewKind;

    f = func(a, x);

    printResult(f, viewKind, displayingPrecision);

    return 0;
}

float func(int a, float x) {
    float result;
    int const X_LIMIT_1 = a*3;

    if(x >= X_LIMIT_1) {
        result = log3(x);
    } else if(X_LIMIT_1 > x && x > 1) {
        result = ctg(x)-2;
    } else if(x <= 1 && x > 0){
        result = 1+pow(sin(3*x+(M_PI/3.0)), 3);
    } else if (x <= 0){
        result = 5*a+x;
    }
    return result;
}

void validateDisplayingPrecision(int precision) {
    if( precision < DISPLAYING_PRECISION_MIN || precision > DISPLAYING_PRECISION_MAX ) {
        cout << ERR_MSG_INCORRECT_ENTERED_VALUE << "точності відображення результату розрахунку";
        cout << ERR_MSG_PROGRAM_STOP;
        exit(0); 
    }
}

void printResult(float y, char viewKind, int precision) {
    const string TXT_F_EQ_TO = "f(a, x)=";

    cout << endl << "Результат розрахунку:\n";
    cout << setprecision(precision);

    switch(viewKind) {
    case 'h':
    case 'H':
        cout << fixed;
        break;
    case 'g':
    case 'G':
        cout << scientific;
        break;
    }

    cout << TXT_F_EQ_TO << y << endl;
}

float ctg(float x) {
    return 1.0 / tan(x);
}

float log3(float x){
    return log(x) / log(3.0);
}