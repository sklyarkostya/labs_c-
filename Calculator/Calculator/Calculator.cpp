#include <iostream>
using namespace std;

void calculator() {
    double a, b;
    char op;
    cout << "Выражение: ";
    cin >> a >> op >> b;
    double res;
    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if (op == '*')
        res = a * b;
    else if (op == '/')
        res = a / b;
    else cout << "Операция не распознана!";
    cout << "Результат: " << a << op << b << '=' << res << endl;
}

void fibonacci() {
    int count;
    cout << "Количество: ";
    cin >> count;
    cout << "Ряд Фибоначчи: ";
    if (count != 0) {
        int a = 1, b = 1;
        cout << 1 << ' ';
        for (int i = 1; i < count; i++) {
            cout << b << ' ';
            b = a + b;
            a = b - a;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "russian");

    while (true)
    {
        cout << "1: Калькулятор " << "2: Ряд Фибоначчи " << "0: Выход" << endl;
        cout << "Ваш выбор: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            calculator();
            break;
        case 2:
            fibonacci();
            break;
        case 0:
            goto metka;
        }
        cout << endl;
    }
metka:
    return 0;
}